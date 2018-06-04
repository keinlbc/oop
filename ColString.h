#pragma once
#include "Column.h"

class ColString: public Column<int>{

protected:
     char* value;
public:

    ColChar(){
        this->type = ColumnBase::TYPE_STRING;
    };
    virtual ~ColChar(){
        delete[] this->value;
    }

    int getValue(){
        return this->value;
    };


    void setValue(int value){
        this->value = value;
    };



};


