///////////////////////////////
// 
// Distance functions for Lipschitz paper. 
// 19-01-2011.
//
///////////////////////////////
#include "preamble.h"
#include "function.h"

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// Distance ordering function.
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// C++
double distance_ordering(NumericMatrix &Dg, NumericMatrix &Dh){   

  // 0. Check/initialize. 
  if(Dg.ncol()!=Dh.ncol()) throw( std::runtime_error("Matrices are not of the same order."));
  vector<double> Gvec=sym2vec(Dg), Hvec=sym2vec(Dh); 
  int Ni=Gvec.size(); double Nd=Ni*(Ni-1)/2; 
  double out=0; int e=0, f=0; 
  // 1. Loop over all pairs of edges. 
  for(e=0; e<Ni; e++){
     for(f=e+1; f<Ni; f++){
       if((Hvec[e]<=Hvec[f] and Gvec[e]>Gvec[f]) or (Hvec[e]>Hvec[f] and Gvec[e]<=Gvec[f])) out += 1/Nd; 
     }//f
  }//e
return out;
}//distance_ordering. 

////////////////////////
// R wrapper. 
SEXP distance_ordering(SEXP rDg, SEXP rDh){
    NumericMatrix Dg(rDg), Dh(rDh);                
    double out=distance_ordering(Dg,Dh); 
return wrap(out);
}//distance_ordering

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// Cost-integrated Distance ordering.
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// C++
double int_distance_ordering(NumericMatrix &Wg, NumericMatrix &Wh){   

  // 0. Check/initialize. 
  if(Wg.ncol()!=Wh.ncol()) throw(std::runtime_error("Matrices are not of the same order."));
  vector<double> Gvec=sym2vec(Wg), Hvec=sym2vec(Wh); 
  int Ni=Gvec.size(); double Nd=Ni*(Ni-1)/2; 
  double out=0; int e=0, f=0; 

  // 1. Loop over all pairs of edges. 
  for(e=0; e<Ni; e++){
     for(f=e+1; f<Ni; f++){
       if((Hvec[e]<=Hvec[f] and Gvec[e]>Gvec[f]) or (Hvec[e]>Hvec[f] and Gvec[e]<=Gvec[f])) out += 1/Nd; 
     }//f
  }//e
return out;
}//distance_ordering. 

////////////////////////
// R wrapper. 
SEXP int_distance_ordering(SEXP rWg, SEXP rWh){
    NumericMatrix Wg(rWg), Wh(rWh);                
    double out=distance_ordering(Wg,Wh); 
return wrap(out);
}//int_distance_ordering


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// k-order (indirect) path length statistics. 
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// C++
NumericVector indirect_paths(NumericMatrix &W, IntegerVector &Vpair, int &k){   

  // 0. Check/initialize.   
  int Nv=W.ncol(); 
  int v1=Vpair[0], v2=Vpair[1]; 
  NumericVector out; IntegerVector V; 
  for(int i=0; i<Nv; ++i) V.push_back(i); 

  // 1. Run over k-order paths. 
  if(k==1){ 
    out.push_back(W(v1,v2)); 
  }//k==1 

  if(k==2){ 
    setClass S1(V); S1 -= Vpair; sIter k1=S1.begin(); 
    for(k1=S1.begin();k1!=S1.end();++k1) out.push_back(W(v1,*k1)*W(*k1,v2));
  }//k==2; 

  if(k==3){ 
    setClass S1(V); S1 -= Vpair; sIter k1=S1.begin(); 
    for(k1=S1.begin(); k1!=S1.end(); ++k1){
        setClass S2(V); S2 -= Vpair; S2 -= *k1; sIter k2=S2.begin(); 
        for(k2=S2.begin(); k2!=S2.end(); ++k2) out.push_back(W(v1,*k1)*W(*k1,*k2)*W(*k2,v2)); 
    }//k1
  }//k==3; 

  if(k==4){ 
    setClass S1(V); S1 -= Vpair; sIter k1=S1.begin(); 
    for(k1=S1.begin(); k1!=S1.end(); ++k1){
        setClass S2(V); S2 -= Vpair; S2 -= *k1; sIter k2=S2.begin(); 
        for(k2=S2.begin(); k2!=S2.end(); ++k2){
  	    setClass S3(V); S3 -= Vpair; S3 -= *k1; S3 -= *k2; sIter k3=S3.begin(); 
            for(k3=S3.begin(); k3!=S3.end(); ++k3)
  	        out.push_back(W(v1,*k1)*W(*k1,*k2)*W(*k2,*k3)*W(*k3,v2));
	}//k2 
    }//k1
  }//k==4; 
return out;
}//indirect_paths.

////////////////////////
// R wrapper. 
SEXP indirect_paths(SEXP W, SEXP Vpair, SEXP k){
    int xk = as<int>(k);     
    NumericMatrix xW(W);  
    IntegerVector xVpair(Vpair);  
    NumericVector out=indirect_paths(xW,xVpair,xk); 
return out;
}//indirect_paths
