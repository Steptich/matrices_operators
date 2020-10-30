//
// Created by stept on 26.10.2020.
//

#ifndef MATRICES_OPERATORS_MATIRX_H
#define MATRICES_OPERATORS_MATIRX_H

#include "datatype.h"
#include "ostream"
class Matrix
{
    enum{N=3}; //vytvari const N = 3
    Number  **data;
    void allocateMemory(); //vytvor matici jako ukazatel poli ukozatelu na pole
    void releaseMemory();
    void copyDataFrom(Matrix &src) const ;
public:
    Matrix(Number diag);
    Matrix(Matrix &other);
    ~Matrix();
    int getDim() const {return N;}
    Number & at(int i, int j) {return data[i][j];} //data kde jsem
    Number & operator()  (int i , int j);
    Matrix& operator=(Matrix &rhs); //delame odkaz aby se mohlo retezit operator prirazeni
    bool operator==(const Matrix &rhs);
    bool operator!=(const Matrix &rhs);
    Number operator~() const; //bitova negace, zmeni nuly na jednicky, zmenim si na co chci
    void print() const;
};

std::ostream& operator <<(std::ostream &os,Matrix &m); //pretizeni vystupu pro dany argument

Matrix operator+ (Matrix &A, Matrix &B);
Matrix operator- (Matrix &A, Matrix &B);

#endif //MATRICES_OPERATORS_MATIRX_H
