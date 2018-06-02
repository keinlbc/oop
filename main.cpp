#include <iostream>
#include "ColInt.h"

using namespace std;




int main()
{

    ColumnBase* array[5];
    ColInt c;
    //ColFloat f;
    c.setValue(23);
    cout << c.getValue() << endl;
    return 0;
}
