#include "include/operation.h"
#include "include/tensor.h"

int main(void) {

  Tensor t({2,2, 3}, 6.6);
  Tensor k({2,2,3}, 9.1);
  std::cout << "t:\n";
  t.print();
  Tensor m = t+k;
  std::cout << "m:\n";
  m.print();
  m = t * k;
  std::cout << "m:\n";
  m.print();
  return 0;
}
