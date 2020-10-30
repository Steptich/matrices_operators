//
// Created by stept on 30.10.2020.
//

#ifndef MATRICES_OPERATORS_AUTOPTR_H
#define MATRICES_OPERATORS_AUTOPTR_H
class Matrix; //dopredna deklarace

class AutoPtr {
    Matrix *pm;
    bool owner;
public:
    AutoPtr(Matrix *m);
    AutoPtr(AutoPtr &other);
    ~AutoPtr();
    AutoPtr& operator=(AutoPtr &rhs);
    Matrix * operator->();

};


#endif //MATRICES_OPERATORS_AUTOPTR_H
