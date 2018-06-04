#pragma once
#include "Row.h"



class Table{

private:
    std::string name;
    int* schema;
    int schemaSize;

	Row* rows;
	size_t count;
	size_t capacity;
	void resize();
	void copy(const Table& table);
	void destroy();

public:

	Table();
	Table(const Table& Table);
	Table& operator= (const Table& table);
	~Table();
	bool addColumn(ColumnBase col);
	std::string getName();

	Row* getRows();

    void serialize();
    void deserialize();

};
