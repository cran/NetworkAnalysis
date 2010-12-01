///////////////////////////////
// 
// Set of C++ Functions.
// 20-12-2010.
//
///////////////////////////////
#include "preamble.h"
#include "function.h"

////////////////////////////////
////////////////////////////////
////////////////////////////////
// Main cost integration function. 
// (By default, we only return vector of 'unstandardized' values.)
NumericMatrix cost_int(NumericMatrix &W, int &metric){
  // NOTE: D is here originally a weighted matrix, but then used as a matrix of Shortest paths.
  // NOTE: Sort Wvec in DECREASING order! 

  // 0. Initialization, Set for Wvec.
  vector<double> Wvec=sym2vec(W); 
  int Ne=Wvec.size(), Nv=W.ncol(), i=0, j=0;
  vector<unsigned int> Wrk=order(Wvec); NumericMatrix D(Nv,Nv); 
  for(i=0; i<Nv; ++i){for(j=0; j<Nv; ++j){if(i==j){ D(i,j)=0.0;}else{D(i,j)=INFINITY;}}}
 
  // 1. D matrix and Sets/multisets.    
  multiset<double> mS; set<double> S; IntegerVector p;  
  for(i=0; i<Ne; ++i){if(Wvec[i]>0){S.insert(Wvec[i]); mS.insert(Wvec[i]);}}
  for(dIter t=S.begin();t!=S.end();++t) p.push_back(mS.count(*t)); 

  // 2. Run over non-zero (NZv) edges.
  IntegerVector Vpair(2); int NZv=S.size();
  NumericMatrix out(S.size(),3); int s=0;
  for(i=0; i<NZv; ++i){

     // Adding edge(s).
     for(j=0; j<p[i]; ++j){ Vpair=pos2ind(Wrk[s],Nv); edge_update(D,Vpair); ++s; }//j
 
     // Switch according to a chosen (set of) metric(s).
     switch(metric){
       // Efficiency.
       case 0: 
     	 out(i,0) = cost(D); out(i,1) = ge(D); out(i,2) = 0.0; break;     

       // Entropy. 
       case 1: 
     	 out(i,0) = cost(D); out(i,1) = 0.0; out(i,2) = Hg(D); break; 

       // Both:
       case 2: 
     	 out(i,0) = cost(D); out(i,1) = ge(D); out(i,2) = Hg(D); break; 

       default:  
     	 out(i,0) = cost(D); out(i,1) = ge(D); out(i,2) = 0.0;             
         // No BREAK statement here, as it gets to the end anyway. 
     }//switch
  }//i   
return out;
}//cost_int 

////////////////////////////////
////////////////////////////////
////////////////////////////////
// R/C++ Wrapper. 
SEXP cost_int(SEXP xW, SEXP xMetric){
BEGIN_RCPP
  int metric = as<int>(xMetric); 
  NumericMatrix W(xW); int Nv=W.ncol(); char met; 
  if(Nv<3){ throw( runtime_error("Matrix is too small: Nv<3."));}
  NumericMatrix out = cost_int(W,metric); 
return out;
END_RCPP
}//cost_int.

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// pos2ind.
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// C++.
IntegerVector pos2ind(unsigned int &pos, int &Nv){
  // Assume n*n matrix, and Nv>2; 
  IntegerVector Vpair(2);
  if(pos==0){
    Vpair[0]=0; Vpair[1]=1;
  }else{
    for(int i=2; i<=Nv; ++i){
      for(int j=1; j<=(i-1); ++j){
 	 double out=0; for(int h=1; h<=(i-2); ++h) out += h; 
         if(out+j==pos+1){ Vpair[0]=j-1; Vpair[1]=i-1; goto end; } 
      }//j
    }//i  
  }//fi
  end:  
return Vpair;
}//pos2ind
IntegerVector pos2ind(int &pos, int &Nv){
  // Assume n*n matrix, and Nv>2; 
  IntegerVector Vpair(2);
  if(pos==0){
    Vpair[0]=0; Vpair[1]=1;
  }else{
    for(int i=2; i<=Nv; ++i){
      for(int j=1; j<=(i-1); ++j){
 	 double out=0; for(int h=1; h<=(i-2); ++h) out += h; 
         if(out+j==pos+1){ Vpair[0]=j-1; Vpair[1]=i-1; goto end; } 
      }//j
    }//i  
  }//fi
  end:  
return Vpair;
}//pos2ind

// R wrapper. 
SEXP pos2ind(SEXP pos, SEXP Nv){
  int xPos= as<int>(pos); 
  int xNv = as<int>(Nv);
  xPos=xPos-1; // Correct for R numbering.
  IntegerVector Vpair=pos2ind(xPos,xNv);
  Vpair[0]+=1; Vpair[1]+=1; 
return Vpair;
}//pos2ind

////////////////////////////////
////////////////////////////////
////////////////////////////////
// Neighbor Function. 
// Note that this works for both D and A.
setClass neighbor(NumericMatrix &D,const int &vertex){
    setClass neigh; 
    NumericVector Drow = D.row(vertex); 
    for(int i=0; i<Drow.size(); ++i) if(Drow[i]==1.0) neigh.insert(i); 
return neigh;
}//neigh

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// edge_update
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// C++.
void edge_update(NumericMatrix &D, IntegerVector &Vpair){         
///////////////////
   // 0. Preliminaries and Update.
   int Nv=D.ncol(); 
   int v1=Vpair[0], v2=Vpair[1]; 
   setClass Sall(Vpair), S(v2), neigh, neigh2; 
   D(v2,v1)=1.0; D(v1,v2)=1.0;

   //////////////////////////////////////////////////
   // 1. Neighborhoods around v2.
   for(int m=1; m<=Nv-2; ++m){ 
       neigh.clear();
       for(sIter v=S.begin();v!=S.end();++v){ neigh2=neighbor(D,*v); neigh += neigh2; neigh2.clear(); }       
       neigh -= Sall;         

       // Run over all mth-degree neighbors of v2.
       S.clear(); 
       for(sIter v=neigh.begin();v!=neigh.end();++v){ 
	 if(D(v1,*v)>=m+1){ D(v1,*v)=m+1; D(*v,v1)=m+1; Sall += *v; S += *v; }//fi
       }// t in neigh
       if(S.empty()) break; 
   }//m      
   //////////////////////////////////////////////////
   // 2. Successive neighborhoods around v1 wrt Sall.
   S.clear(); S += v1; Sall -= v1; 
   for(int m=1; m<=Nv-2; ++m){ 
       neigh.clear(); 
       for(sIter v=S.begin();v!=S.end();++v){ neigh2=neighbor(D,*v); neigh += neigh2; neigh2.clear(); }       
       neigh -= Sall;         

       // Run over all mth-degree neighbors of v2.
       S.clear(); 
       for(sIter v=neigh.begin();v!=neigh.end();++v){ 
           for(sIter u=Sall.begin();u!=Sall.end();++u){ 
	       if(D(*v,*u)>=D(v1,*u)+m){ D(*u,*v)=D(*u,v1)+m; D(*v,*u)=D(v1,*u)+m; S += *v; }//fi
            }// u in neigh
       }// v in neigh
       if(S.empty()) break; 
   }//m      
/////////////////////
}//edge.update

////////////////////////////////
////////////////////////////////
// R/C++ Wrapper.
// Not to be called in loops, except through other C++ functions. 
SEXP edge_update(SEXP D, SEXP Vpair){
BEGIN_RCPP

  // Translation.
  // CLONING ensures that we DON'T modify the argument.
  NumericMatrix xD(clone(D));
  IntegerVector xVpair(Vpair); 
  int Nv=xD.ncol();
  xVpair = xVpair-1; 

  // Check not lesser than 0.
  for(int i=0; i<xVpair.size(); ++i){if(xVpair[i]<0)throw( std::runtime_error("Matrix Index is lower than 0."));}
  // Check not identical indexes.
  if(xVpair[0]==xVpair[1]){throw( std::runtime_error("Indexes are equal: No diagonal entries allowed."));}
  // Check matrix is 2*2.
  if(xVpair[0]>Nv-1 or xVpair[1]>Nv-1){throw( std::runtime_error("Indexes/Vertices out of bound."));}
  // Check matrix is 2*2.
  if(Nv==2){
     xD(xVpair[0],xVpair[1]) = 1.0; xD(xVpair[1],xVpair[0]) = 1.0;      
  }else{
     // Call internal C++ function. 
     edge_update(xD,xVpair);    
  }//fi
return xD;
END_RCPP
}//cost_int wrapper


