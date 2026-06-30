#ifndef OPERATION_H
#define OPERATION_H

    #pragma once
    #include "tensor.h"
    namespace ops {
        Tensor add(const Tensor &, const Tensor &);
        Tensor multiply(const Tensor &, const Tensor &);
        bool has_same_shape(const Tensor &, const Tensor &);
    };


#endif //OPERATION_H