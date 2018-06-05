
#include "CLI.h"

void CLI::closeCli()
{
	this->isOpen = false;
}

bool CLI::getState()const
{
	return this->isOpen;
}

void CLI::printMenu() const
{
	std::cout<<"1) Load"<<std::endl;
	std::cout<<"2) Showtables"<<std::endl;
	std::cout<<"3) Describe"<<std::endl;
	std::cout<<"4) Print"<<std::endl;
	std::cout<<"5) Save"<<std::endl;
	std::cout<<"6) Select"<<std::endl;
	std::cout<<"7) Add Column"<<std::endl;
	std::cout<<"8) Update"<<std::endl;
	std::cout<<"9) Delete"<<std::endl;
	std::cout<<"10) Insert"<<std::endl;
	std::cout<<"11) Inner Join"<<std::endl;
	std::cout<<"12) Rename"<<std::endl;
	std::cout<<"13) Count"<<std::endl;
	std::cout<<"14) Aggregate"<<std::endl<<std::endl;
	std::cout<<"15) Create Table"<<std::endl<<std::endl;
	std::cout<<"0) Quit"<<std::endl<<std::endl;
	std::cout<<"Input command: ";
}

void CLI::printexComBranch(int command)
{
	switch(command)
	{
		case 1:
		{
			std::cout<<"Parameters needed: (1)filename "<<std::endl;
			char* filename = new char[32];
			std::cin>>filename;
			//exec func
			delete [] filename;
			break;
		}
		case 2:
		{
			std::cout<<"Tables:"<<std::endl;
			this->db->showTables();
			break;
		}
		case 3:
		{
			std::cout<<"Parameters needed: (1)tablename "<<std::endl;
			char* tablename= new char[32];
			std::cin>>tablename;
			int x=0;
			if(db->isTable(tablename,x))
			{
				Table& table = this->db->getTable(tablename);
				std::cout<<table.getInfo()<<std::endl;
			}
			delete [] tablename;

			break;
		}
		case 4:
		{
			std::cout<<"Parameters needed: (1)tablename "<<std::endl;
			char* tablename = new char[32];
			std::cin>>tablename;
			//exec func
			delete [] tablename;
			break;
		}
		case 5:
		{
			std::cout<<"Parameters needed: (1)tablename "<<std::endl;
			char* tablename= new char[32];
			std::cin>>tablename;
			int x=0;
			if(db->isTable(tablename,x))
			{
				Table& table = this->db->getTable(tablename);
				table.serialize();
			}
			delete [] tablename;

			break;
		}
		case 6:
		{
		 std::cout<<"Parameters needed: (1)column-n (2)value (3)tablename"<<std::endl;
			int n;
			char* value = new char[32];
			char* tablename = new char[32];
			std::cin>>n;
			std::cin>>value;
			std::cin>>tablename;
			//exec func
			delete [] value;
			delete [] tablename;
			break;
		}
		case 7:
		{
			std::cout<<"Parameters needed: (1)tablename"<<std::endl;
			char* tablename = new char[32];

			std::cin>>tablename;

			int index = 0;
			if(!db->isTable(tablename, index)){
				std::cout << "no such table. exit ....";
				break;
			}

			Table &table = this->db->getTable(tablename);

			int type;
			do {
			    std::cout << "Add column type (1)int, 2(float), 3(string) | 0 for exit .." << std::endl;
			    std::cin >> type;

			    if(type != 0)
			    	table.addColumn(type);
			}
			while( type != 0 );

			//exec func
			delete [] tablename;
			break;
		}
		case 8:
		{
			std::cout<<"Parameters needed: (1)tablename (2)searchcolumn-n"<<std::endl
			<<"(3)searchvalue (4)targetcolumn-n (5)targetvalue"<<std::endl;
			char* tablename = new char[32];
			int sn;
			char* searchvalue = new char[32];
			int tn;
			char* targetvalue = new char[32];
			std::cin>>tablename;
			std::cin>>sn;
			std::cin>>searchvalue;
			std::cin>>tn;
			std::cin>>targetvalue;
			//exec func
			delete [] tablename;
			delete [] searchvalue;
			delete [] targetvalue;
			break;
		}
		case 9:
		{
			std::cout<<"Parameters needed: (1)tablename (2)searchcolumn-n (3)searchvalue"<<std::endl;
			char* tablename = new char[32];
			int n;
			char* searchvalue = new char[32];
			std::cin>>tablename;
			std::cin>>n;
			std::cin>>searchvalue;
			//exec func
			delete [] tablename;
			delete [] searchvalue;
			break;
		}
		case 10:
		{
			std::cout<<"Parameters needed: (1)tablename "<<std::endl;
			char* tablename = new char[32];
			std::cin>>tablename;
			//exec func
			delete [] tablename;
			break;
		}
		case 11:
		{
			std::cout<<"Parameters needed: (1)table1 (2)column1 (3)table2 (4)column2 "<<std::endl;
			char* table1 = new char[32];
			int c1;
			char* table2 = new char[32];
			int c2;
			std::cin>>table1;
			std::cin>>c1;
			std::cin>>table2;
			std::cin>>c2;
			//exec func
			delete [] table1;
			delete [] table2;
			break;
		}
		case 12:
		{
			std::cout<<"Parameters needed: (1)oldname (2)newname "<<std::endl;
			char* oldname = new char[32];
			char* newname = new char[32];
			std::cin>>oldname;
			std::cin>>newname;
			//exec func
			delete [] oldname;
			delete [] newname;
			break;
		}
		case 13:
		{
			std::cout<<"Parameters needed: (1)tablename (2)searchcolumn-n (3)searchvalue "<<std::endl;
			char* tablename = new char[32];
			int n;
			char* searchvalue = new char[32];
			std::cin>>tablename;
			std::cin>>n;
			std::cin>>searchvalue;
			//exec func
			delete [] tablename;
			delete [] searchvalue;
			break;
		}
		case 14:
		{
		 	std::cout<<"Parameters needed: (1)tablename (2)searchcolumn-n (3)searchvalue"
			<<std::endl<<"(4)targetcolumn-n (5)operation "<<std::endl;
		 	char* tablename = new char[32];
			int sn;
			char* searchvalue = new char[32];
			int tn;
			char* operation = new char[32];
			std::cin>>tablename;
			std::cin>>sn;
			std::cin>>searchvalue;
			std::cin>>tn;
			std::cin>>operation;
			//exec func
			delete [] tablename;
			delete [] searchvalue;
			delete [] operation;
			break;
		}
		case 15:
		{
			std::cout<<"Add Table: "<<std::endl;
			char* tablename= new char[32];
			std::cin>>tablename;
			int x=0;
			if(!db->isTable(tablename,x))
			{
				Table& newTable = this->db->addTable();
				newTable.setName(tablename);
			}
			delete [] tablename;

			break;
		}
		case 0: this->closeCli();
	}
}

CLI::CLI()
{
this->db = new Database();
}

CLI::~CLI()
{
delete db;
}
