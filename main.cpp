#include "include/tensor.h"

int main(void) {

  Tensor t({2,2, 3}, 6.6);
  Tensor k({2,2,3}, 9.1);
  Tensor m = t+k;
  m = m.transpose(1, 2);
  std::cout << "Transposed m is:\n";
  m.print();
  return 0;
}
