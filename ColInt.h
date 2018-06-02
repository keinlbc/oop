#pragma once
#include "column.h"

class ColInt: public Column<int>{

protected:
    // int value;
public:

    ColInt():Column<int>(ColumnBase::TYPE_INT){}
    virtual ~ColInt(){}

    int getValue(){
        return this->value;
    }


    void setValue(int value){
        this->value = value;
    }



};
