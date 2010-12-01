///////////////////////////////
// 
// Set of C++ Functions.
// 20-12-2010.
//
///////////////////////////////
#include "preamble.h"
#include "function.h"

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// Number of components.
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// Find Giant Component. 
NumericMatrix giant_cpnt(NumericMatrix &D){   

    // 0. Initialize.
    int Nv = D.ncol(); setClass S0, S, Smax; 
    for(int i=0; i<Nv; ++i) S0.insert(i); 
    sIter v=S0.begin(); 

    // 1. Loop. 
    while(Smax.size() < S0.size()){
        S.clear(); 
        NumericVector Drow = D.row(*v); 
        for(int i=0; i<Nv; ++i) if(!isinf(Drow[i])) S.insert(i); 
        if(Smax.size() < S.size()) Smax = S;  // BEWARE: Copy constructor!
        S0 -= S; 
        v=S0.begin(); 
    }//while 

    // 2. Construct subgraph, i.e.: subD.
    NumericMatrix subD = subMatrix(D,Smax,Smax);  
return subD;
}//giant_cpnt

////////////////////////
// R wrapper. 
SEXP giant_cpnt(SEXP D){
    NumericMatrix xD(D);        
    NumericMatrix subD=giant_cpnt(xD); 
return subD;
}//giant_cpnt

////////////////////////////////
// Graph components.
// (Returns vector of subgraphs in any order.)
vector<NumericMatrix> graph_cpnts(NumericMatrix &D){   

    // 0. Initialize.
    vector<NumericMatrix> lsD; 
    NumericVector Drow; 
    int Nv = D.ncol(); setClass S0, S; 
    for(int i=0; i<Nv; ++i) S0.insert(i); 
    sIter v=S0.begin(); 

    // 1. Loop over components.
    while(!S0.empty()){
        S.clear(); 
        Drow = D.row(*v); 
        for(int i=0; i<Nv; ++i) if(!isinf(Drow[i])) S.insert(i); 
        lsD.push_back(subMatrix(D,S,S)); 
        S0 -= S; 
        v=S0.begin(); 
    }//while
return lsD;
}//graph_cpnts

////////////////////////////////
// Wrapper graph_cpnts.
SEXP number_cpnts(SEXP xD){
    NumericMatrix D(xD);        
    vector<NumericMatrix> lsD = graph_cpnts(D); 
    int K=lsD.size(); 
return wrap(K);
}//number_cpnt


//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// NetEnt (Hg)
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// C++ (main function)
double Hg(NumericMatrix &D){
    vector<NumericMatrix> lsD=graph_cpnts(D); 
    int K=lsD.size(); double out=0; 
    vector<double> Hs(K); 
    for(int i=0; i<K; ++i) Hs[i] = netent(lsD[i]);          
    out= *max_element(Hs.begin(),Hs.end()); 
return out;
}//Hg

////////////////////////////////
// C++ (computional function).
double netent(NumericMatrix &D){
  vector<double> Dvec = sym2vec(D); 
  int Ne = Dvec.size(), i=0; 
  double out=0; 
  // Condition:
  if(Ne!=0){
    NumericVector p;
    multiset<double> mSet; set<double> Set; 

    // Allocate non-zero d's. 
    for(i=0; i<Ne; ++i){ if(1/Dvec[i]>0.0){mSet.insert(Dvec[i]); Set.insert(Dvec[i]);}}

    if(!Set.empty()){
      // Compute probability of each entry. 
      for(set<double>::iterator t=Set.begin();t!=Set.end();++t) p.push_back(mSet.count(*t)); 

      // Normalize vector of probabilities. 
      int Np = p.size(); double Sp=0; 
      for(i=0; i<Np; ++i){ Sp += p[i];}
      for(i=0; i<Np; ++i){ p[i] = p[i]/Sp;}

      // Entropy.
      for(i=0; i<Np; ++i) out += p[i]*log2(1/p[i]); 
    }//fi
  }//fi
return out;
}//netent.

////////////////////////////////
// R.
SEXP Hg(SEXP D){
    NumericMatrix xD(D);        
    double out = Hg(xD); 
return wrap(out);
}//Hg

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// ge 
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// C++
double ge(NumericMatrix &D){
    vector<double> Dvec = sym2vec(D);        
    int Ne = Dvec.size(); double out=0;        
    for(int i=0; i<Ne; ++i) out += (1/Dvec[i])/Ne;  
return out;
}//ge

// R.
SEXP ge(SEXP D){
    NumericMatrix xD(D);        
    vector<double> Dvec = sym2vec(xD);        
    int Ne = Dvec.size();     
    double out=0;        

    // Computing ge. 
    for(int i=0; i<Ne; ++i) out += (1/Dvec[i])/Ne;  
    // Faster than the sugar alternative:
    // double out=sum(1/Dvec)/Ne;        
return wrap(out);
}//ge

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
// (unweighted) Cost.  
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
// (Works for both A and D!!!)

////////////////////////
// C++.
// Numeric.
double cost(NumericMatrix &D){
    vector<double> Dvec=sym2vec(D); 
    double out=0, Ne=Dvec.size(); 
    // BEWARE: 'out' is transformed to int if Ne is not 'double'.
    // This, however, does not affect the conditional: i<Ne.
    for(int i=0; i<Ne; ++i) if(Dvec[i]==1) out += 1/Ne; 
return out;
}//cost
// Integer.
double cost(IntegerMatrix &D){
    vector<int> Dvec=sym2vec(D); 
    double out=0, Ne=Dvec.size(); 
    // BEWARE: 'out' is transformed to int if Ne is not 'double'.
    // This, however, does not affect the conditional: i<Ne.
    for(int i=0; i<Ne; ++i) if(Dvec[i]==1) out += 1/Ne; 
return out;
}//cost

////////////////////////
// R wrapper. 
SEXP cost(SEXP D){
    NumericMatrix xD(D);        
    double out=cost(xD); 
return wrap(out);
}//cost


