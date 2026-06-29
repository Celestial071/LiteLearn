#include "include/tensor.h"
#include "include/operation.h"

std::size_t Tensor::numel() const {
  auto total = 1;
  for(auto dim : shape) {
    total *= dim;
  }

  return total;
}

void Tensor::reshape(const std::vector<std::size_t> &newShape) {
  shape = newShape;
}

void Tensor::calcStride(void){
  int dim = shape.size() - 1; //4
  stride[dim] = 1;
  for(int i = dim -1; i > -1; i--) {
    stride[i] = stride[i + 1] * shape[i+1];
  }
} 

void Tensor::print() const {
  printRecursive(0,0);
  std::cout << '\n';
}

void Tensor::printRecursive(std::size_t dim,
                            std::size_t offset) const
{
    // Are we at the last dimension?
    std::string indent(dim*INDENT, ' ');
    if (dim == shape.size() - 1)
    {
        
        std::cout << indent << "[";
        for(int i = 0; i < shape[dim]; i++) {
            std::cout << data[offset+i];
            if(i != shape[dim] - 1) {
              std::cout << ",";
            }

        }
        std::cout << "],"<< std::endl;
        return;
    }

    std::cout << indent << "[\n";

    for (int i = 0; i < shape[dim]; i++) 
    {
        std::size_t m = offset + i * stride[dim];
        printRecursive(dim+1, m);
    }

     
    std::cout << indent << ((dim == 0)? "]\n": "],\n");
}

const std::vector<std::size_t> &Tensor::getShape() const {
  return shape;
}

double &Tensor::operator[](std::size_t i) {
  return data[i];
}

const double &Tensor::operator[](std::size_t i) const {
  return data[i];
}

Tensor Tensor::operator+(const Tensor &other) const {
  return ops::add(*this, other);
}

Tensor Tensor::operator*(const Tensor &other) const {
  return ops::multiply(*this, other);
}