#pragma once
#include "Column.h"
#include<stdlib.h>

class ColInt: public Column<int>{

protected:

public:

    ColInt():Column<int>(ColumnBase::TYPE_INT){ }
    virtual ~ColInt()
    {}

    int getValue(){
        return this->value;
    }


    void setValue(int value){
        this->value = value;
    }


         void fromString(const std::string& raw){
            this->setValue(atoi(raw.c_str()));
         }

         std::string toString() const{
            return std::to_string(value);
         }

};
