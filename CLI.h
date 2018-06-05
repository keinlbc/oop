#pragma once
#include <iostream>
#include "Database.h"

class CLI
{
private:
	bool isOpen = true;
	Database* db;

public:
	bool getState() const;

	void closeCli();

	void printMenu() const;

	void printexComBranch(int command);

	CLI();

	~CLI();

};