#ifndef DISPLAY_H
#define DISPLAY_H

#include <conio.h>
#include <fstream>
#include "control.h"
#include "block.h"

class Display {
public:
	Display();
	void menu();
	void show(Block block);
	
	// max characters per line;
	int maxLineCharLength = 30;

	void editing(std::string fName);

	void navigation(Block& block);
	void insertion(Block& block);
	void setMaxLineCharLength(Block& block);

	void printFromFile(std::string fName);
	std::string readFromFile(std::string fName);

	Control control;
};

#endif