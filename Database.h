#pragma once
#include "Table.h"
#include <iostream>
#include <string.h>

class Database
{

private:

int maxTab;
Table* tables;
int tableCount;

public:

Table& addTable();

Table& getTable(char*)const;

bool isTable(char*,int&)const;

Database();

~Database();

void showTables()const;

};

