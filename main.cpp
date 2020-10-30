#include <iostream>
#include "datatype.h"
#include "matirx.h"

int main() {
Matrix A(3);
Matrix B(4);
std::cout <<A.at(0,0) << "\n";
std::cout << B(1,1) << "\n"; //jiz vyuziti pretizeneho ()
std::cout << A << "\n";
std::cout << ~A;
/*Matrix C(0);
C = A+B;
std::cout << C;*/

    return 0;
}
