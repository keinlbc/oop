#pragma once
#include "Column.h"

class ColInt: public Column<int>{

protected:
     int value;
public:

    ColInt(){
        this->type = ColumnBase::TYPE_INT;
    };
//    virtual ~ColInt(){
//
//    }

    int getValue(){
        return this->value;
    };


    void setValue(int value){
        this->value = value;
    };



};
