#include <iostream>
#include "Row.h"
#include "CLI.h"
using namespace std;



int main()
{
 CLI cli;

std::cout << "fdasfasd" << std::endl;
while(cli.getState()==true)
{
	cli.printMenu();
	int command;
	cin>>command;
	cli.printexComBranch(command);
}


}
	