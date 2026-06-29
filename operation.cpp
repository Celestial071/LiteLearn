#include "include/operation.h"
#include <cstdio>


bool ops::has_same_shape(const Tensor &a, const Tensor &b) {
    return a.getShape() == b.getShape();
}


Tensor ops::add(const Tensor &a, const Tensor &b) {
    if(ops::has_same_shape(a, b)) {
        Tensor result(a.getShape());
        for(std::size_t i = 0; i < a.numel(); i++) {
            result[i] = a[i] + b[i];
        }

        return result;
    }
    
    throw std::invalid_argument("Shape Mismatch\n");
}

Tensor ops::multiply(const Tensor &a, const Tensor &b) {
    if(ops::has_same_shape(a, b)) {
        Tensor result(a.getShape());
        for(std::size_t i = 0; i < a.numel(); i++) {
            result[i] = a[i] * b[i];
        }

        return result;
    }
    
    throw std::invalid_argument("Shape Mismatch\n");
}