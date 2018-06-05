#include "Table.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


void Table::addRow(ColumnBase** data)
{
	Row newRow;

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

    ofstream shandle(this->getName()+".schema");
    shandle.open();

    // ofstream dhandle;
    // dhandle.open( this->getName()+".data", ios::out);

    if(!shandle.is_open()){
        std::cout << "cant open";
    }

    for(int i=0;i<this->schemaSize;i++){
        shandle<<this->schema[i]<<" ";
        std::cout << this->schema[i];
    }

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

void Table::columnFactory(int type){

	switch(type)
		{
			case ColumnBase::TYPE_INT:
			c = new ColInt;
	        cout << "Set int value : "
	        cin >> c->setValue();
			break;

			case ColumnBase::TYPE_FLOAT:
			c = new ColFloat;
	        cout << "Set flaot value : "
	        cin >> c->setValue();
			break;

			case ColumnBase::TYPE_STRING:
			c = new ColInt;
	        cout << "Set char value : "
	        cin >> c->setValue();
			break;
		}
		return 

}
void Table::rowFactory(){

    Row row;

    for(int i=0; i<this->schemaSize(); i++){
	    
	    ColumnBase* c = this->columnFactory(this->schema[i]);

    	row->addColumn(c);

    }
    this->addRow(row);

}

void Table::print(RowNode* topNode = this->top){

	if(topNode == NULL){
	  std::cout << "No rows in the table" << std::end;
	}
	int i = 10;
	do{
		char* input;
		for(i=0; i<this->schemaSize; i++){
			std::cout << "|";
			if(topNode.data[i]){
				std::cout << "NULL";
			}else{
				std::cout << topNode->data[i].getValue();
			}
		}
		std::cout << std::endl;

		topNode = topNode->next;
		i--;

	}while(top_node &&  i>0);

	std::cout << "Press enter to continue...";

	if(cin.get() == '\n')
		this->print(topNode);

}

void Table::select(int n, ColumnBase* column){

	RowNode* topNode;
	topNode = this->top;

	Table tempTable;
	tempTable->setName(table.getName()+"_select");
	tempTable->schema = new int[this->schemaSize];
	tempTable->schemaSize = this->schemaSize;


	while(topNode){
		if(topNode.data[i]){
				continue;
		}else{
			if(topNode->data[n] == column){
				tempTable->addRow(topNode);
			}	
		}
		topNode = topNode->next;
	}

	return tempTable;
}

void Table::update(int s_n, ColumnBase* s_column, int t_n, ColumnBase* t_column){ //this works also with nullptr

	RowNode* topNode;
	topNode = this->top;

	while(topNode){
		
		if(topNode->data[s_n] == column){
			topNode->data[t_n].setValue = t_column->getValue();
		}	
		
		topNode = topNode->next;
	}

}

void Table::delete(int n, ColumnBase* column){

	RowNode* topNode;
	topNode->next = *this->top;

	while(topNode->next){
		
		if(topNode->next->data[n] == column){
			RowNode* save = topNode->next;
			topNode-next = topNode->next->next;
			delete save;

		}else{
			topNode = topNode->next;
		}
		
		
	}

}

void Table::agregate(int s_n, ColumnBase* s_column, int t_n, ColumnBase* t_column, std::string operation)
