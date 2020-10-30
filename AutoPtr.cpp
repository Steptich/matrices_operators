//
// Created by stept on 30.10.2020.
//

#include "AutoPtr.h"
#include "matirx.h"

AutoPtr::AutoPtr(Matrix *m)
//po vytvoreni se automaticky ukazatel stava vlastnikem matice
    :pm(m), owner(true)
{}

AutoPtr::AutoPtr(AutoPtr &other)
    :pm(other.pm), owner(other.owner)
{
    //chceme aby nova instance prevzala vlastnictvi,
    //ukazuji na stejne misto, ale vlastnik jen jeden
    other.owner= false; //takze puvodni vlastnictvi zrusim
}

AutoPtr::~AutoPtr() {
    if (owner)
    {//pokud je vlastnik tak ma na starosti mazani
        delete pm;
    }
}

AutoPtr &AutoPtr::operator=(AutoPtr &rhs) {
    if(this == &rhs)
    {//pro pripad ze to jiz mam, abych si nevzal vlastnictvi
        return *this;
    }
    if(this->owner)
    {//pokud jiz je tak mazu a dam nova data
        delete pm;
    }
    this->pm=rhs.pm;
    this->owner=rhs.owner;
    rhs.owner= false;
    return *this;
}

Matrix *AutoPtr::operator->() {
    return pm;
}
