#include <cstdio>
#include <assert.h>
#include <iostream>
using namespace std;
#include "vops.h"
#include "add_to_equal_14.h"
namespace ANONYMOUS{

void test__Wrapper() {
  test();
}
void test__WrapperNospec() {}
void test() {
  int  _out_s1=0;
  equals14(13, _out_s1);
  assert ((_out_s1) == (14));;
}
void equals14(int x, int& _out) {
  _out = x + 1;
  return;
}

}
