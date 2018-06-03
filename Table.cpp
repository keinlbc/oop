#include "Table.h"

Table::Table()
{
	this->schema = NULL;
	this->schemaSize = 0;


	this->rows = NULL;
	this->count = 0;
	this->capacity = 1;
}

Table& Table::operator= (const Table& table)
{
	if(this != &table)
	{
		destroy();
		copy(table);
	}
	return *this;
}

void Table::copy(const Table& table)
{
	this->rows = new Row[table.capacity];

	for(size_t i = 0; i < table.count; ++i)
	{
		this->rows[i] = table.rows[i];
	}
	this->capacity = table.capacity;
	this->count = table.count;
}

void Table::destroy()
{
	delete[] this->rows;
	delete[] this->schema;
}

Table::~Table(){
    destroy();
}

Table::Table(const Table& table)
{
	copy(table);
}




bool Table::addColumn(ColumnBase column)
{


	int* temp = new int[this->schemaSize + 1];

	for(size_t i=0; i<this->schemaSize; i++){

		temp[i] = this->schema[i];
	}
	temp[this->schemaSize++] = column.getType();

	delete[] this->schema;
	this->schema = temp;

	//now add the column to all existing rows
    for(size_t i=0; i<this->count; i++){

        this->rows[i].addColumn(column);
	}
	return true;
}

void Table::resize()
{
	Row* temp = new Row[this->capacity*2];
	for(size_t i = 0; i < this->capacity; ++i)
	{
		temp[i] = this->rows[i];
	}

	delete [] this->rows;
	this->rows = temp;
	this->capacity *=2;


}
