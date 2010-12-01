///////////////////////////////
// 
// Set of C++ Functions.
// 20-12-2010.
//
///////////////////////////////
#include "preamble.h"
#include "function.h"

////////////////////////////////
///////////////////////////////
///////////////////////////////
// Sub matrices. 
IntegerMatrix subMatrix(IntegerMatrix &D, setClass &Rows, setClass &Cols){
  IntegerMatrix subD(Rows.size(),Cols.size());  
  int i=0, j=0; 
    for(sIter r=Rows.begin();r!=Rows.end();++r){
       for(sIter c=Cols.begin();c!=Cols.end();++c){
      	   subD(i,j) = D(*r,*c); 
   	   ++j;   
       }//c
       ++i; 
    }//r
return subD; 
}//subMatrix

////////////////////////////////
////////////////////////////////
////////////////////////////////
NumericMatrix subMatrix(NumericMatrix &D, setClass &Rows, setClass &Cols){
  NumericMatrix subD(Rows.size(),Cols.size());  
  // cout << "=================================" << endl; 
  // cout << "IN SUBMATRIX:" << endl; 
  // cout << Rows.size() << "\t" << Cols.size() << endl; 
  int i=0, j=0; 
    for(sIter r=Rows.begin();r!=Rows.end();++r){
       for(sIter c=Cols.begin();c!=Cols.end();++c){
      	   subD(i,j) = D(*r,*c); 
   	   ++j;   
       }//c
       j=0; ++i; 
    }//r
return subD; 
}//subMatrix

////////////////////////////////
////////////////////////////////
// ORDER
////////////////////////////////
////////////////////////////////
// Setup and original code below by Craig Hicks.
template <class random_iterator>
class AscendingComparison
{
   public:
      AscendingComparison (random_iterator begin,random_iterator end)
         : p_begin (begin), p_end (end) {}
      bool operator () (unsigned int a, unsigned int b) const
         { return *(p_begin + a) < *(p_begin + b); }
   private:
      random_iterator const p_begin;
      random_iterator const p_end;
};
template <class random_iterator>
class DescendingComparison
{
   public:
      DescendingComparison (random_iterator begin,random_iterator end)
         : p_begin (begin), p_end (end) {}
      bool operator () (unsigned int a, unsigned int b) const
         { return *(p_begin + a) > *(p_begin + b); }
   private:
      random_iterator const p_begin;
      random_iterator const p_end;
};

////////////////////////////////////
// C++̣.
vector<unsigned int> order(NumericVector &x, bool decreasing){ // default values cannot be passed by reference.
   // Initialization. 
   vector<unsigned int> ind(x.size ());
   for(int i=0; i<ind.size(); i++) ind[i] = i;
  // Condition:
  if(decreasing){
    sort(ind.begin(),ind.end(),DescendingComparison<nvIter>(x.begin(),x.end()));
  }else{
    sort(ind.begin(),ind.end(),AscendingComparison<nvIter>(x.begin(),x.end()));
  }//fi
return ind;
}//order
vector<unsigned int> order(vector<double> &x, bool decreasing){ // default values cannot be passed by reference.
   // Initialization. 
   vector<unsigned int> ind(x.size ());
   for(int i=0; i<ind.size(); i++) ind[i] = i;
  // Condition:
  if(decreasing){
    sort(ind.begin(),ind.end(),DescendingComparison<vector<double>::iterator>(x.begin(),x.end()));
  }else{
    sort(ind.begin(),ind.end(),AscendingComparison<vector<double>::iterator>(x.begin(),x.end()));
  }//fi
return ind;
}//order

////////////////////////////////////
// R wrapper. 
SEXP order(SEXP x, SEXP decreasing){
   int B = as<int>(decreasing); 
   NumericVector vec(x); 
   bool Bdecreasing; 
   if(B==1) Bdecreasing=true; else Bdecreasing=false;
   vector<unsigned int> out = order(vec,Bdecreasing); 
return wrap(out);
}//order

////////////////////////////////
////////////////////////////////
// MaxE
////////////////////////////////
////////////////////////////////
// C++
int maxE(int &Nv){  
  int out = Nv*(Nv-1)/2; 
return out; 
}//maxE

////////////////////////////////
////////////////////////////////
// Combinatorics.
////////////////////////////////
////////////////////////////////

// C++
int factorial(int n){
    if(n>=171) throw( std::runtime_error("Value out of range for factorial."));
    if(n<=1) return 1;
    int out = n*factorial(n-1);
return out;
}//factorial

// C++
int perm(int n, int k){
    int out = factorial(n)/factorial(n-k); 
return out;
}//perm

// C++
int combi(int n, int k){
    int out = factorial(n)/(factorial(n-k)*factorial(k)); 
return out;
}//combi

