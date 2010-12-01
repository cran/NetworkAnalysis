///////////////////////////////
// 
// Set of C++ utilities.
// 20-12-2010.
//
///////////////////////////////
#include "preamble.h"
#include "function.h"

///////////////////////////////
///////////////////////////////
// FUNCTIONS (overloading)
///////////////////////////////
////////////////////////////////
// C++ numeric.
//NumericVector sym2vec(NumericMatrix &xD){
vector<double> sym2vec(NumericMatrix &xD){
  int Nv = xD.rows(); 
  vector<double> Dvec; 
  // IntegerVector Dvec(Nv*(Nv-1)/2);        
  if(Nv>1){
    int JC = 2; 
    Dvec.resize(Nv*(Nv-1)/2);
    for(int j = 1; j <= (Nv-1); ++j){
        for(int i = 0; i <= (j-1) ; ++i){
            Dvec[JC + i - 2] = xD(i,j); 
        }//i
        JC = JC + j;          
    }// j   
  }//fi 
return Dvec;
}//EoF

// C++ integer: 
vector<int> sym2vec(IntegerMatrix &xD){
  int Nv = xD.rows(); 
  vector<int> Dvec; 
  if(Nv>1){
    int JC = 2;     
    Dvec.resize(Nv*(Nv-1)/2);
    for(int j = 1; j <= (Nv-1); ++j){
        for(int i = 0; i <= (j-1) ; ++i){
            Dvec[JC + i - 2] = xD(i,j); 
        }//i
        JC = JC + j;          
    }// j
  }//fi
return Dvec;
}//EoF

////////////////////////////////
////////////////////////////////
// R Numeric wrapper.
SEXP sym2vec_numeric(SEXP D){
    NumericMatrix xD(D);        
    vector<double> Dvec = sym2vec(xD); 
return wrap(Dvec);
}//EoF

////////////////////////////////
////////////////////////////////
// R Numeric.
SEXP sym2vec_integer(SEXP D){
    IntegerMatrix xD(D);        
    vector<int> Dvec = sym2vec(xD); 
return wrap(Dvec);
}//EoF
