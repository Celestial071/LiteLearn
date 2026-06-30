#ifndef TENSOR_H
#define TENSOR_H

  #pragma once

  #include <vector>
  #include <iostream>

  typedef enum {
    CPU,
    GPU
  }Device;


  constexpr std::size_t INDENT = 4;

  class Tensor {
    private:
      std::vector<double> data;
      std::vector<std::size_t> shape;
      std::vector<std::size_t> stride; 
      Device device;
      std::vector<double> grad;
      bool  requiresGrad;

    public:
      Tensor(const std::vector<std::size_t> &s, bool rg=false, Device d=CPU) : shape(s), requiresGrad(rg), device(d) {
        auto n = numel();
        data.resize(n, 0.0);
        stride.resize(s.size(), 0); 
        calcStride();
        if(requiresGrad) {
          grad.resize(n, 0.0);
        }
      }
      Tensor(const std::vector<std::size_t> &s, double val) : Tensor(s){
        std::fill(data.begin(), data.end(), val);
      }

      std::size_t numel() const;
      void zeroGrad(void);
      void reshape(const std::vector<std::size_t> &newShape);
      void print(void) const;
      void printRecursive(std::size_t dim, std::size_t offset) const;
      void calcStride(void);
      const std::vector<std::size_t> &getShape() const;
      double &operator[](std::size_t i);
      const double &operator[](std::size_t i) const;
      Tensor operator+(const Tensor &other) const; 
      Tensor operator*(const Tensor &other) const;
      Tensor transpose(std::size_t dim1, std::size_t dim2) const;
  };

#endif //TENSOR_H
