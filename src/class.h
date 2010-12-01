#ifndef _NetworkAnalysis_CLASSES_Hpp
#define _NetworkAnalysis_CLASSES_Hpp

///////////////////////////////
///////////////////////////////
class setClass 
{
public:
  // Constructors/Destructors.
  setClass();
  setClass(int&);
  setClass(IntegerVector&);
  ~setClass(); 
 
  // Methods.
  int size(); 
  set<int> getSet();
  void insert(int&); 
  void insert(const int&); 
  void print(); 
  void clear(); 
  bool empty(); 
  set<int>::iterator begin(); 
  set<int>::iterator end(); 

  // Operators.
  //setClass& operator=  (setClass& rhs); 
  setClass& operator+= (const int& rhs); 
  setClass& operator+= (const IntegerVector& rhs); 
  setClass& operator+= (setClass& rhs); 
  setClass& operator-= (const int& rhs); 
  setClass& operator-= (const IntegerVector& rhs); 
  setClass& operator-= (setClass& rhs); 

private:
  set<int> Set; 
  set<int>::iterator it; 
  // iterator is here a static member.
};
///////////////////////////////


///////
#endif
