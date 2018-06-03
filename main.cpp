#include <iostream>
#include "Table.h"
#include "ColInt.h"
using namespace std;




int main()
{


    ColInt c;


    //ColFloat f;
    c.setValue(23);

    Table t;
    t.addColumn(c);
    cout << "alabala" << endl;
    cout << c.getValue() << endl;
    return 0;
}
