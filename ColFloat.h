#pragma once
#include "Column.h"

class ColFloat: public Column<int>{

protected:
     float value;
public:

    ColFloat(){
        this->type = ColumnBase::TYPE_FLOAT;
    };
    virtual ~ColFloat(){}

    int getValue(){
        return this->value;
    };


    void setValue(int value){
        this->value = value;
    };



};

