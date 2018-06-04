#pragma once
#include "Column.h"
class Row{

private:

   	ColumnBase* columns;
	size_t count;
	size_t capacity;
	void resize();
	void copy(const Row& row);
	void destroy();

public:

	Row();
	Row(const Row& Row);
	Row& operator= (const Row& row);
	~Row();
	bool addColumn(ColumnBase col);

    ColumnBase* getColumns();

};
