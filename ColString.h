#pragma once
#include "Column.h"
#include<string.h>

using namespace std;

class ColString: public Column<char* >{

protected:

public:

    ColString():Column<char*>(ColumnBase::TYPE_STRING){this->value = NULL;}

    virtual ~ColString(){
      delete[] this->value;
    }

    char* getValue(){
        return this->value;
    }


    void setValue(char* value){


          delete[] this->value;

          if(value == NULL)
          {
            this->value = NULL;
            return;
          }

        int n = strlen(value);
        this->value = new char[n+1];
        strcpy(this->value,value);

    }

         void fromString(const std::string& raw){
           char* temp = new char[raw.size()+1];
           strcpy(temp,raw.c_str());
            this->value = temp;
         }

         std::string toString() const{
            return std::string(this->value);
         }



};
