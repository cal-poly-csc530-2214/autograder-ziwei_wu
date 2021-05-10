#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "figure_4_fixed.h"
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
  int _tt1[5] = {1, 2, 3, 4, 5};
  Array*  arTest1=Array::create(5, _tt1, 5);
  Array*  original_result1_s7=NULL;
  computeDeric_list_int(arTest1, original_result1_s7);
  Array*  student_result1_s9=NULL;
  computeDeriv(arTest1, student_result1_s9);
  assert ((original_result1_s7->sz) == (student_result1_s9->sz));;
  assert (arrCompare(original_result1_s7->A, original_result1_s7->sz, student_result1_s9->A, student_result1_s9->sz) && ((original_result1_s7->sz) == (student_result1_s9->sz)));;
}
void computeDeric_list_int(Array* poly_list_int, Array*& _out) {
  if ((poly_list_int->sz) == (1)) {
    bool _tt2[1] = {0};
    _out = Array::create(1, _tt2, 1);
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
  bool  _out_s11=0;
  boolOrFalse0((poly->sz) == (1), _out_s11);
  if (_out_s11) {
    Array*  _out_s13=NULL;
    modRetVal0(deriv, _out_s13);
    _out = _out_s13;
    return;
  }
  int  start_index_s15=0;
  intOrPlusOne(0, start_index_s15);
  int  arrSize=poly->sz - start_index_s15;
  int  e=0;
  e = start_index_s15;
  bool  __sa1=(start_index_s15) < (poly->sz);
  int*  tempArr= new int [arrSize]; CopyArr<int >(tempArr,0, arrSize);
  while (__sa1) {
    bool  _out_s17=0;
    boolOrFalse1(((poly->A[e])) == (0), _out_s17);
    if (_out_s17) ; else {
      (tempArr[e - start_index_s15]) = (poly->A[e]) * e;
    }
    e = e + 1;
    __sa1 = (e) < (poly->sz);
  }
  Array*  _out_s19=NULL;
  modRetVal1(Array::create(arrSize, tempArr, arrSize), _out_s19);
  _out = _out_s19;
  delete[] tempArr;
  return;
}
void boolOrFalse0(bool a, bool& _out) {
  _out = a;
  return;
}
void modRetVal0(Array* a, Array*& _out) {
  bool _tt3[1] = {0};
  _out = Array::create(1, _tt3, 1);
  return;
}
void intOrPlusOne(int a, int& _out) {
  _out = a + 1;
  return;
}
void boolOrFalse1(bool a, bool& _out) {
  _out = 0;
  return;
}
void modRetVal1(Array* a, Array*& _out) {
  _out = a;
  return;
}

}
