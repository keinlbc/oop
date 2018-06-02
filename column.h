#pragma once



class ColumnBase{

protected:
    int type;
public:

    static const int TYPE_INT= 1;
    static const int TYPE_FLOAT = 2;
    static const int TYPE_STRNG = 3;

    ColumnBase();
    ColumnBase(int t){
        this->type  = t;
    }

    int getType(){
        return this->type;
    }

    virtual ~ColumnBase() = 0;
};

template <typename T>
class Column:public ColumnBase{


protected:
    std::string name;
    T value;
public:

    Column(int t):ColumnBase(t){}
    virtual ~Column() = 0;

    virtual T getValue()= 0;
    virtual void setValue(const T t) = 0;

} ;
