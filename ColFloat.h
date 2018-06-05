#pragma once
#include "Column.h"

using namespace std;

class ColFloat: public Column<float>{

protected:

public:

    ColFloat():Column<float>(ColumnBase::TYPE_FLOAT) {}
    virtual ~ColFloat(){}

    float getValue(){
        return this->value;
    }


    void setValue(float value){
        this->value = value;
    }

     void fromString(const std::string& raw){
        this->setValue(atof(raw.c_str()));
     }

     std::string toString() const{
        return std::to_string(this->value);
     }


};
