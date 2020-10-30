//
// Created by stept on 26.10.2020.
//

#ifndef MATRICES_OPERATORS_MATIRX_H
#define MATRICES_OPERATORS_MATIRX_H

#include "datatype.h"
#include "ostream"
class Matrix
{
    enum{N=3}; //? zjisti si co  to je
    Number  **data;
    void allocateMemory(); //vytvor matici jako ukazatel poli ukozatelu na pole
    void releaseMemory();
    void copyDataFrom(Matrix &src);
public:
    Matrix(Number diag);
    Matrix(Matrix &other);
    ~Matrix();
    int getDim() const {return N;}
    Number & at(int i, int j) {return data[i][j];} //data kde jsem
    Number & operator()  (int i , int j);
    bool operator==(const Matrix &rhs);
    bool operator!=(const Matrix &rhs);
    Number operator~() const; //bitova negace, zmeni nuly na jednicky, zmenim si na co chci
};

std::ostream& operator <<(std::ostream &os,Matrix &m); //pretizeni vystupu pro dany argument

Matrix operator+ (Matrix &A, Matrix &B);

#endif //MATRICES_OPERATORS_MATIRX_H
