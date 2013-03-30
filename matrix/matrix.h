#ifndef BINARY_MATRIX_H_
#define BINARY_MATRIX_H_

#include <stdint.h>
#include <iostream>
#include <string>
#include "MatrixInput.h"


template <typename T>
class Matrix{
    public:
        Matrix() : num_rows(0), num_cols(0){};
        Matrix(uint32_t num_rows, uint32_t num_cols) :
            num_rows(num_rows), num_cols(num_cols){};
        virtual ~Matrix(){};

        uint32_t get_num_rows(){return num_rows;};
        uint32_t get_num_cols(){return num_cols;};

        virtual void set_num_rows(uint32_t nr){num_rows = nr;};
        virtual void set_num_cols(uint32_t nc){num_cols = nc;};

        virtual void readMatrix(MatrixInput &in) = 0;
        virtual void readCache(std::istream &in) = 0;
        virtual void buildCache(std::ostream &out) = 0;
        virtual std::string getCacheName() = 0;
        virtual void multiply(const T *v, T *r) = 0;
        virtual uint64_t memoryUsage() = 0;
        virtual uint32_t granularity() = 0;
        virtual uint32_t nonZeroes() = 0;

        void setStat( double v ) { ss = v; };
        double getStat() { return ss; };
        
        virtual void transferToDevice() = 0;

    protected:
        uint32_t num_rows;
        uint32_t num_cols;
        double ss;

};

#endif //BINARY_MATRIX_H_
