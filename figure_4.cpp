#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "figure_4.h"
namespace ANONYMOUS{

template<typename T_0>
Array* Array::create(int  sz_, T_0* A_, int A_len){
  int tlen_A = sz_; 
  void* temp= malloc( sizeof(Array)   + sizeof(int )*tlen_A); 
  Array* rv = new (temp)Array();
  rv->sz =  sz_;
  CopyArr(rv->A, A_, tlen_A, A_len ); 
  return rv;
}
void main__Wrapper() {
  _main();
}
void main__WrapperNospec() {}
void _main() {
  int _tt0[1] = {4};
  Array*  arTest=Array::create(1, _tt0, 1);
  Array*  original_result_s3=NULL;
  computeDeric_list_int(arTest, original_result_s3);
  Array*  student_result_s5=NULL;
  computeDeriv(arTest, student_result_s5);
  assert (((original_result_s3->sz) == (student_result_s5->sz)) && (((original_result_s3->A[0])) == ((student_result_s5->A[0]))));;
}
void computeDeric_list_int(Array* poly_list_int, Array*& _out) {
  if ((poly_list_int->sz) == (1)) {
    bool _tt1[1] = {0};
    _out = Array::create(1, _tt1, 1);
    return;
  }
  int  N=poly_list_int->sz - 1;
  bool  __sa0=(1) < (poly_list_int->sz);
  int*  result= new int [N]; CopyArr<int >(result,0, N);
  int  i=1;
  while (__sa0) {
    (result[i - 1]) = i * (poly_list_int->A[i]);
    i = i + 1;
    __sa0 = (i) < (poly_list_int->sz);
  }
  _out = Array::create(N, result, N);
  delete[] result;
  return;
}
void computeDeriv(Array* poly, Array*& _out) {
  Array*  deriv=Array::create(0, (int* )NULL, 0);
  bool  _out_s7=0;
  boolOrFalse((poly->sz) == (1), _out_s7);
  if (_out_s7) {
    Array*  _out_s9=NULL;
    modRetVal0(deriv, _out_s9);
    _out = _out_s9;
    return;
  }
  int  e_s11=0;
  intOrPlusOne(0, e_s11);
  int  e=0;
  e = e_s11;
  bool  __sa1=(e_s11) < (poly->sz);
  int*  tempArr= new int [0]; CopyArr<int >(tempArr,NULL, 0, 0);
  while (__sa1) {
    bool  _out_s13=0;
    boolOrFalse(((poly->A[e])) == (0), _out_s13);
    if (_out_s13) ; else {
      (tempArr[e]) = (poly->A[e]) * e;
    }
    e = e + 1;
    __sa1 = (e) < (poly->sz);
  }
  Array*  _out_s15=NULL;
  modRetVal0(Array::create(poly->sz - 1, tempArr, 0), _out_s15);
  _out = _out_s15;
  delete[] tempArr;
  return;
}
void boolOrFalse(bool a, bool& _out) {
  _out = 0;
  return;
}
void modRetVal0(Array* a, Array*& _out) {
  bool _tt2[1] = {0};
  _out = Array::create(1, _tt2, 1);
  return;
}
void intOrPlusOne(int a, int& _out) {
  _out = a + 1;
  return;
}

}
