#pragma once
#include <string>
using namespace std;
class ColumnBase{

protected:
    int type;

public:

    static const int TYPE_INT= 1;
    static const int TYPE_FLOAT = 2;
    static const int TYPE_STRING = 3;


    ColumnBase(){this->type =0;}
    ColumnBase(int t){
        this->type  = t;
    }

    int getType() const{
        return this->type;
    }

    virtual ~ColumnBase() {};

    virtual std::string serialize(){};
    virtual void deserialize() {};

};

template <typename T>
class Column:public ColumnBase{


protected:
    std::string name;
    T value;
public:

    Column(int t):ColumnBase(t){}
    ~Column() {}

    virtual T getValue()= 0;
    virtual void setValue(T) = 0;

    virtual void fromString(const std::string&) =0;
    virtual std::string toString() const =0;

    virtual std::string serialize(){

      std::string out = "";
      out += this->getType();
      out += ":";
      out+=toString();

      return out;

    }
    virtual void deserialize(const std::string& val){

      string s = val.substr(2);
      int n = 0;
      for(n;n<s.size();n++)if(s[n]== ':')break;

      const char* s_size = s.substr(0,n).c_str();
      const char* s_data = s.substr(n).c_str();

      if(s_size ==0)return;

      int size = atoi(s_size);

      this->fromString(std::string(s_data));

    }

} ;
