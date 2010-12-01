///////////////////////////////
// 
// Set of C++ Classes.
// 20-12-2010.
//
///////////////////////////////
#include "preamble.h"
#include "function.h"
#include "class.h"

//////////////////////////////////////////////////
//////////////////////////////////////////////////
// Constructor/Destructor.
setClass::setClass(){;}
setClass::setClass(int &v){ Set.insert(v); }
setClass::setClass(IntegerVector &Vec){for(int i=0; i<Vec.size(); ++i) Set.insert(Vec[i]);}
setClass::~setClass(){;}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
// Methods.
int setClass::size(){ return Set.size(); }
set<int> setClass::getSet(){ return Set; }
void setClass::clear(){ Set.clear(); } 
bool setClass::empty(){ return Set.empty(); } 
void setClass::insert(int& newElement){ Set.insert(newElement); } 
void setClass::insert(const int& newElement){ Set.insert(newElement); } 
set<int>::iterator setClass::begin(){ return Set.begin(); }
set<int>::iterator setClass::end(){ return Set.end(); }

// int setClass::getElement(int& index){
//   int element Set; 
//   return element; 
// }// 

void setClass::print(){  
  //cout << "This Set contains:" << endl;
  if(Set.empty()){
     cout << "NULL" << endl;     
  }else{
     for(it=Set.begin(); it!=Set.end(); ++it)
          cout << *it << " ";
     cout << endl;
  }
}

//////////////////////////////////////////////////
//////////////////////////////////////////////////
// Operators.

////////////////////
// Equality (i.e. copying). DEFAULT copy constructor is better!
// setClass& setClass::operator= (setClass& rhs){
//   Set=rhs.getSet(); 
//   return *this;  
// }

////////////////////
// Unions.
setClass& setClass::operator+= (const int& rhs){
  Set.insert(rhs);
  return *this;  
}
setClass& setClass::operator+= (const IntegerVector& rhs){
  for(int i=0; i<rhs.size(); ++i) Set.insert(rhs[i]);
  return *this;  
}
setClass& setClass::operator+= (setClass& rhs){
  for(sIter t=rhs.begin(); t!=rhs.end(); ++t) Set.insert(*t);
  return *this; 
}  

////////////////////
// Set difference. 
setClass& setClass::operator-= (const int& rhs){
  Set.erase(rhs);
  return *this;  
}
setClass& setClass::operator-= (const IntegerVector& rhs){
  for(int i=0; i<rhs.size(); ++i) Set.erase(rhs[i]);
  return *this;  
}
setClass& setClass::operator-= (setClass& rhs){
  for(sIter t=rhs.begin(); t!=rhs.end(); ++t) Set.erase(*t);
  return *this; 
}  

////////////////////////
// Using Boost.
//  set<int> RHS=rhs.getSet();
//  foreach(int i, RHS){}
