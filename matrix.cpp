//
// Created by stept on 26.10.2020.
//

#include "matirx.h"
#include "ostream"
Matrix::Matrix(Number diag) {
    //vytvor matici a dej argument na diagonalu
    allocateMemory();
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            data[i][j]= (i==j ? diag:0); // if(i==j){data[i][j]=diag}
                                         // else {data[i][j]=0}
        }
    }
}//musim zvlast jelikoz operator , by vzal jen posledni hodnotu

void Matrix::allocateMemory() {
    //vytvor matici jako ukazatel na pole ukazatelu na pole
    data = new Number*[N];
    for (int i = 0; i < N; ++i) {
        data[i]=new Number[N];
    }
}


void Matrix::releaseMemory() {
    for (int i = 0; i < N; ++i) {
        delete [] data[i];
    }
    delete [] data;
}

Matrix::~Matrix() {
    releaseMemory();
}

void Matrix::copyDataFrom(Matrix &src) {
//odkazy prvku src jsou tu, takze vlastne stejna matice jen v jine pameti,
// ale meni se oboje stejne
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N ; ++j)
        {
            this->data[i][j]=src.data[i][j];
        }
    }
}
Matrix::Matrix(Matrix &other)
{
    allocateMemory();
    copyDataFrom(other);
}

std::ostream& operator <<(std::ostream &os,Matrix &m)
{   //pouzivam ostream jelikoz je to predek iostream a lze tak pouzivat i
    //fstream atd.
    int n = m.getDim();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //nejde pretizit indexovaci operator jelikoz je pak binarni
            // a my mame dva parametry
            os << m.at(i,j) << "\t";
        }
        os << "\n";
    }
    return os;
}
//rhs = = right-hand side
bool Matrix::operator==(const Matrix &rhs) {

    if(this == &rhs) //porovnam ukzatatele
    {
        return true; //pokud jsou adresy stejne tak je to ta stejna matice
    }

    if (this->getDim()!=rhs.getDim()) //overeni dimenze
    {
        return false;
    }

    for (int i = 0; i < this->getDim(); ++i)
    {
        for (int j = 0; j < this->getDim(); ++j)
        {
            if (this->data[i][j]!=rhs.data[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &rhs) {
    return !(*this == rhs); //jiz pouzivam novou definici ==
}

Number &Matrix::operator()(int i, int j) {
    if (i >= N || j >= N)
    {
       // vyvolat vyjimku -index je mimo meze
    }
    return data[i][j];
}

Number Matrix::operator~() const {
    //predelam ho na vypocet stopy
    Number trace;
    for (int i = 0; i < this->getDim(); ++i) {
        trace+= data[i][i];
    }
    return trace;
}

Matrix operator+ (Matrix &A, Matrix &B)
{   Matrix C(0) ;
    int n = A.getDim();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C(i,j)=A(i,j)+B(i,j); //vyuzivam pretizeneho operatoru ()
        }
    } //problem je ze C je lokalni promena a pozdeji v main
    // se pracuje jiz se zrusenou pameti
    return C;
}
