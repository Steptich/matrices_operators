//
// Created by stept on 30.10.2020.
//

#include "AutoPtr.h"
#include "matirx.h"

AutoPtr::AutoPtr(Matrix *m)
//po vytvoreni se automaticky ukazatel stava vlastnikem matice
    :pm(m), owner(true)
{}

AutoPtr::AutoPtr(AutoPtr &other) {

}

AutoPtr::~AutoPtr() {
    if (owner)
    {//pokud je vlastnik tak ma na starosti mazani
        delete pm;
    }
}

AutoPtr &AutoPtr::operator=(AutoPtr &rhs) {
    return ;
}

Matrix *AutoPtr::operator->() {
    return pm;
}
