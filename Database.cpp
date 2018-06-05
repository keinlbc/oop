#include "Database.h"

bool Database::isTable(char* tablename, int& index)const
{
if(tableCount>0)
{
	for(int i=0; i<tableCount; i++)
	{
		if(strcmp(tablename,tables[i].getName().c_str())==0)
		{
			index = i;
			return true;
		}
	}
	return false;
}
else return false;
}

Table& Database::getTable(char* tablename)const
{
	int index=0;
	if(!isTable(tablename,index))
	{

	}else
	{
		return tables[index];
	}
}

Table& Database::addTable()
{
	if(tableCount == maxTab)
	{
		Table* temp = tables;
		tables = new Table[maxTab*2];
		for(int i=0; i<tableCount; i++)
		{
			tables[i] = temp[i];
		}
		maxTab *= 2;
		delete [] temp;
	}

	tables[tableCount++] = Table();

	return tables[tableCount-1];
}

Database::Database()
{
 maxTab = 8;
 tables = new Table[maxTab];
 tableCount = 0;
}

Database::~Database()
{
	delete [] tables;
}

void Database::showTables()const
{
	for(int i=0; i<tableCount;i++)
		cout<<this->tables[i].getName()<<std::endl;
}


