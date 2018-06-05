#pragma once
#include "Row.h"
#include<string>

struct RowNode{

RowNode* next = NULL;
Row data;


};
class Table{

private:
    std::string name;
    int* schema;
    int schemaSize;

	RowNode* top = NULL;


	void copy(const Table& table);
	void destroy();

public:

	Table();
	Table(const Table& Table);
	Table& operator= (const Table& table);
	~Table();

	void addColumn(int);

	std::string getName() const;
    void setName(const std::string&);

	RowNode* getRowIterator();
    void addRow(ColumnBase**);

    void updateSchema(int);
    const std::string getInfo()const;

    int* getSchema() const;
    int getSchemaSize() const;



    void serialize();
    void deserialize();

};
