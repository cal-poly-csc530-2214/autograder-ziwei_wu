#ifndef FIGURE_4_FIXED_H
#define FIGURE_4_FIXED_H

#include <cstring>

#include "vops.h"

namespace ANONYMOUS{
class Array; 
}
namespace ANONYMOUS{
class Array; 
class Array{
  public:
  int  sz;
  int  A[];
  Array(){}
template<typename T_0>
  static Array* create(  int  sz_,   T_0* A_, int A_len);
  ~Array(){
  }
  void operator delete(void* p){ free(p); }
};
extern void main__Wrapper();
extern void main__WrapperNospec();
extern void _main();
extern void computeDeric_list_int(Array* poly_list_int, Array*& _out);
extern void computeDeriv(Array* poly, Array*& _out);
extern void boolOrFalse0(bool a, bool& _out);
extern void modRetVal0(Array* a, Array*& _out);
extern void intOrPlusOne(int a, int& _out);
extern void boolOrFalse1(bool a, bool& _out);
extern void modRetVal1(Array* a, Array*& _out);
}

#endif
