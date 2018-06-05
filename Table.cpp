#include "Table.h"
#include <string>
#include <fstream>
using namespace std;


  void Table::addRow(ColumnBase** data)
	{
		Row newRow;

		for(int i=0;i<schemaSize;i++)
			newRow.addColumn(data[i]);

		RowNode* newNode = new RowNode();
		newNode->next = this->top;
		newNode->data = newRow;
		this->top = newNode;

	}
std::string Table::getName() const
{
	return this->name;
}


void Table::serialize()
{

	string path = "./DB";
	std::ofstream shandle (path + "/"+ this->getName()+".schema", std::ofstream::out);
	std::ofstream dhandle (path +"/"+this->getName()+".data", std::ofstream::out);

for(int i=0;i<this->schemaSize;i++)
	shandle<<this->schema[i]<<" ";

	RowNode* temp = this->top;
	while(temp)
	{
		ColumnBase** data = temp->data.getColumns();

		for(int i =0;i<this->schemaSize;i++)
		{
			if(data[i])
			dhandle<<data[i]->serialize()<<std::endl;
			else dhandle<<schema[i]<<":"<<0<<":"<< std::endl;
		}


		temp = temp->next;
	}

    shandle.close();
	dhandle.close();

	std::cout << "db and schema was saved" << std::endl;

}
void Table::deserialize()
{

	destroy(); //make sure table doesn't exist

string path = "./DB";
std::ifstream shandle (path+"/"+this->getName()+".schema",std::ifstream::in);
std::ifstream dhandle (path+"/"+this->getName()+".data",std::ifstream::in);

while(!shandle.eof())
{
	int entry;
	shandle>>entry;
	updateSchema(entry);
}



shandle.close();
dhandle.close();

}
void Table::setName(const std::string& name)
{
	this->name = name;
}

Table::Table()
{
	this->schema = NULL;
	this->schemaSize = 0;

}

Table& Table::operator= (const Table& table)
{
		copy(table);

	return *this;
}

void Table::copy(const Table& table)
{
	if(this == &table)return;
	destroy();

	this->setName(table.getName()+"_copy");
	this->schema = new int[table.schemaSize];
	this->schemaSize = table.schemaSize;
	for(int i=0;i<schemaSize;i++)
	schema[i] = table.schema[i];

	RowNode* top_node = table.top;
	RowNode** cursor = &this->top;

	while(top_node){

	 (*cursor) = new RowNode();
	 (*cursor)->data = top_node->data;
		cursor = &((*cursor)->next);

		(*cursor)->data = top_node->data;

		top_node = top_node->next;
	}


}

void Table::destroy()
{
	RowNode* temp = NULL;
	while(this->top)
	{
		temp = this->top->next;
		delete this->top;
		this->top = temp;
	}

	delete[] schema;

}

Table::~Table(){
    destroy();
}

Table::Table(const Table& table)
{
	copy(table);
}

  void Table::updateSchema(int entry)
	{
		int* temp = new int[this->schemaSize + 1];

		for(size_t i=0; i<this->schemaSize; i++){

			temp[i] = this->schema[i];
		}
		temp[this->schemaSize++] =entry;

		delete[] this->schema;
			this->schema = temp;
	}


void Table::addColumn(int type)
{

	updateSchema(type);

	RowNode* cursor = this->top;

	while(cursor)
	{

			cursor->data.addColumn(NULL);

			cursor = cursor->next;
	}


}


  int* Table::getSchema() const
	{
		return this->schema;
	}
  int Table::getSchemaSize() const
	{
		return this->schemaSize;
	}
const string Table::getInfo() const{

string out = "";
for(int i=0;i<this->schemaSize;i++)
{

	switch(this->schema[i])
	{
		case ColumnBase::TYPE_INT:
		out+= "INTEGER |";
		break;

		case ColumnBase::TYPE_FLOAT:
		out+= "FLOAT |";
		break;

		case ColumnBase::TYPE_STRING:
		out+= "STRING |";
		break;
		default: out+= "UNKNOWN |";

	}

}


return out;
}
