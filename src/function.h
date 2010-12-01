#ifndef _NetworkAnalysis_SIGNATURES_Hpp
#define _NetworkAnalysis_SIGNATURES_Hpp

////////////////
// Classes
#include "class.h"

////////////////
// Set of declarations for every C++ functions in package.

////////////////
////////////////
// common.cpp
int maxE(int &Nv);
IntegerMatrix subMatrix(IntegerMatrix &D, setClass &Rows, setClass &Cols);
NumericMatrix subMatrix(NumericMatrix &D, setClass &Rows, setClass &Cols);
vector<unsigned int> order(NumericVector &x, bool decreasing=true); 
vector<unsigned int> order(vector<double> &x, bool decreasing=true); 
RcppExport SEXP order(SEXP x, SEXP decreasing); 
int factorial(int n); // Factorial.
int perm(int n, int k); // Permutation.
int combi(int n, int k); // Combi.

////////////////
////////////////
// sym2vec.cpp
vector<double> sym2vec(NumericMatrix &D);
vector<int> sym2vec(IntegerMatrix &D);
RcppExport SEXP sym2vec_numeric(SEXP D);
RcppExport SEXP sym2vec_integer(SEXP D);

////////////////
////////////////
// metrics.cpp
vector<NumericMatrix> graph_cpnts(NumericMatrix &D); 
NumericMatrix giant_cpnt(NumericMatrix &D); 
double ge(NumericMatrix &D);
double Hg(NumericMatrix &D);
double netent(NumericMatrix &D);
double cost(NumericMatrix &D);
double cost(IntegerMatrix &D);
RcppExport SEXP ge(SEXP D);
RcppExport SEXP Hg(SEXP D);
RcppExport SEXP giant_cpnt(SEXP D); 
RcppExport SEXP number_cpnts(SEXP D); 
RcppExport SEXP cost(SEXP D); 

////////////////
////////////////
// metrics_int.cpp
setClass neighbour(NumericMatrix &D, int &Vertex); 
void edge_update(NumericMatrix &D, IntegerVector &Vpair); 
NumericMatrix cost_int(NumericMatrix &D, int &metric); 
IntegerVector pos2ind(int &pos, int &Nv); 
IntegerVector pos2ind(unsigned int &pos, int &Nv); 
RcppExport SEXP edge_update(SEXP D, SEXP Vpair); 
RcppExport SEXP cost_int(SEXP D, SEXP metric); 
RcppExport SEXP pos2ind(SEXP pos, SEXP Nv); 

////////////////
////////////////
// Lipschitz.cpp
double distance_ordering(NumericMatrix &Dg, NumericMatrix &Dh); 
NumericVector indirect_paths(NumericMatrix &W, IntegerVector &Vertices, int &k); 
RcppExport SEXP distance_ordering(SEXP Dg, SEXP Dh); 
RcppExport SEXP indirect_paths(SEXP W, SEXP Vertices, SEXP k); 

///////
#endif

///////
// Re-loaded shared lib in R.
//
// dyn.load("/home/cgineste/pro/spn/src/NetworkAnalysis.so")
//
