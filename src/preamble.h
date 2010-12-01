#ifndef _NetworkAnalysis_PREAMBLE_Hpp
#define _NetworkAnalysis_PREAMBLE_Hpp

#include <Rcpp.h>
using namespace Rcpp; 
using namespace Rcpp::sugar; 

// STD Specifics:
#include <iostream>
#include <iterator> // ostream_iterator
#include <algorithm>
#include <vector>
#include <set>
//#include <boost/foreach.hpp>
using namespace std; 

/*
 * note : RcppExport is an alias to `extern "C"` defined by Rcpp.
 *
 * It gives C calling convention to the rcpp_hello_world function so that 
 * it can be called from .Call in R. Otherwise, the C++ compiler mangles the 
 * name of the function and .Call can't find it.
 *
 * It is only useful to use RcppExport when the function is intended to be called
 * by .Call. See the thread http://thread.gmane.org/gmane.comp.lang.r.rcpp/649/focus=672
 * on Rcpp-devel for a misuse of RcppExport
 */

// Other definitions:
//#define foreach BOOST_FOREACH
#define sIter set<int>::iterator
#define dIter set<double>::iterator
#define nvIter NumericVector::iterator

#endif
