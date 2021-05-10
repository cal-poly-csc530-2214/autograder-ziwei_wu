#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "deriv_ret_example.h"
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
  if ((poly->sz) == (1)) {
    Array*  _out_s7=NULL;
    modRetVal0(deriv, _out_s7);
    _out = _out_s7;
    return;
  }
  int  N=poly->sz - 1;
  bool  __sa1=(1) < (poly->sz);
  int*  result= new int [N]; CopyArr<int >(result,0, N);
  int  i=1;
  while (__sa1) {
    (result[i - 1]) = i * (poly->A[i]);
    i = i + 1;
    __sa1 = (i) < (poly->sz);
  }
  _out = Array::create(N, result, N);
  delete[] result;
  return;
}
void modRetVal0(Array* a, Array*& _out) {
  bool _tt2[1] = {0};
  _out = Array::create(1, _tt2, 1);
  return;
}

}
