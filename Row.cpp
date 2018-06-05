#include "Row.h"


Row::Row()
{
	this->columns = new ColumnBase*[1];
	this->count = 0;
	this->capacity = 1;
}
void Row::destroy()
{
	for(int i=0;i<count;i++)
	{
		delete columns[i];
	}
	delete[] columns;
}

Row::Row(const Row& row)
{
	copy(row);
}

Row::~Row(){
    destroy();
}

Row& Row::operator= (const Row& row)
{
	if(this != &row)
	{
		destroy();
		copy(row);
	}
	return *this;
}
void Row::copy(const Row& row)
{
	this->columns = new ColumnBase*[row.capacity];

	for(size_t i = 0; i < row.count; ++i)
	{
		this->columns[i] =  Row::createCopy(row.columns[i]);
	}
	this->capacity = row.capacity;
	this->count = row.count;
}





void Row::resize()
{
	ColumnBase** temp = new ColumnBase*[this->capacity*2];
	for(size_t i = 0; i < this->capacity; ++i)
	{
		temp[i] = this->columns[i];
	}

	delete[] this->columns;

	this->columns = temp;
	this->capacity *=2;


}

bool Row::addColumn(const ColumnBase* column = NULL)
{


	if (count+1 >= capacity)
	{
		resize();
	}
if(!column)this->columns[count++] = NULL;
else
	this->columns[count++] = Row::createCopy(column);
	return true;
}

ColumnBase** Row::getColumns(){
    return this->columns;
};
