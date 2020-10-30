#include <iostream>
#include "datatype.h"
#include "matirx.h"
#include "AutoPtr.h"

int main() {
Matrix A(3);
Matrix B(4);
std::cout <<A.at(0,0) << "\n";
std::cout << B(1,1) << "\n"; //jiz vyuziti pretizeneho ()
std::cout << A << "\n";
std::cout << ~A << "\n";
Matrix C(0);
A+B;
std::cout << A << "\n";
C = A; //stejne jako operator+(m,n)
std::cout << C;


//chtel jsem ukazatele ale musim dat ty automaticke, jinak ztracim data
AutoPtr apD (new Matrix(5));
AutoPtr apE (new Matrix(7));
apD=apE; //pouzije se pretizeny operator prizareni pro autoptr

    {
        AutoPtr apF(new Matrix (0));
        apF->print(); //lze protoze ukazatel na Matrix a tohle je jeho metoda
    }
    return 0;
}
