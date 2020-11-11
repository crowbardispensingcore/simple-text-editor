#include "../include/display.h"

Display::Display() {

}

void Display::menu() {
	char key;
	
	printFromFile("./resource/welcomescreen.txt");
	std::cout << "Press any key to continue. . .";
	(void)_getch();

	system("cls");
	printFromFile("./resource/instruction.txt");
	std::cout << "Press any key to continue. . .";
	(void)_getch();

	system("cls");
	printFromFile("./resource/mainmenu.txt");
	std::cout << "Enter your choice: ";
	std::cin >> key;
	// input error checking
	while (!std::cin) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid choice: please reenter a choice.\n";
		std::cin >> key;
	}
	while (key != 'q' && key != 'Q') {
		system("cls");
		switch (key) {
		case '1':
			editing("./resource/sampletext.txt");
			break;
		default:
			break;
		}

		system("cls");
		printFromFile("./resource/mainmenu.txt");
		std::cout << "Enter your choice: ";
		std::cin >> key;
		// input error checking
		while (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice: please reenter a choice.\n";
			std::cin >> key;
		}
	}

}

void Display::show(Block block) {
	system("cls");
	//std::cout << std::endl;
	//std::cout << block.cursor << "\n";
	std::string s;
	s = block.getString();
	int lineCharCount = 0;
	// if cursor is at the end
	if (block.cursor == (block.length - 1)) {
		for (int i = 0; i < block.length; i++) {
			std::cout << s[i];
			lineCharCount++;
			if (lineCharCount == maxLineCharLength) {
				std::cout << "\n";
				// reset character count
				lineCharCount = 0;
			}
		}
		std::cout << "\033[32m" << "|" << "\033[0m";
		return;
	}

	for (int i = 0; i <= block.cursor; i++) {
		std::cout << s[i];
		lineCharCount++;
		if (lineCharCount == maxLineCharLength) {
			std::cout << "\n";
			// reset character count
			lineCharCount = 0;
		}
	}
	std::cout << "\033[32m" << "|" << "\033[0m";
	for (int i = block.cursor + 1; i < block.length; i++) {
		std::cout << s[i];
		lineCharCount++;
		if (lineCharCount == maxLineCharLength) {
			std::cout << "\n";
			// reset character count
			lineCharCount = 0;
		}
	}
}

void Display::editing(std::string fName) {
	char usrInput;
	Block block_1;

	std::string string_1 = readFromFile(fName);
	Span* span_1 = new Span(string_1);
	
	block_1.append(span_1);

	// editing menu
	show(block_1);
	std::cout << "\n\n\n\n";
	std::cout << "==========================\n";
	std::cout << "1. Navigation mode\n";
	std::cout << "2. Insert\n";
	std::cout << "3. Define the amount of characters per line (default: 30)\n";
	std::cout << "Enter Q to exit.\n";
	std::cout << "Enter your choice: ";
	std::cin >> usrInput;
	while (!std::cin) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid choice: please reenter a choice.\n";
		std::cin >> usrInput;
	}
	while (usrInput != 'q' && usrInput != 'Q') {
		switch (usrInput) {
		case '1':
			navigation(block_1);
			break;
		case '2':
			insertion(block_1);
			break;
		case '3':
			setMaxLineCharLength(block_1);
			break;
		default:
			break;
		}
		
		// editing menu
		system("cls");
		show(block_1);
		std::cout << "\n\n\n\n";
		std::cout << "==========================\n";
		std::cout << "1. Navigation mode\n";
		std::cout << "2. Insert\n";
		std::cout << "3. Define the amount of characters per line (default: 30)\n";
		std::cout << "Enter Q to exit.\n";
		std::cout << "Enter your choice: ";
		std::cin >> usrInput;
		while (!std::cin) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice: please reenter a choice.\n";
			std::cin >> usrInput;
		}
	}
	
}

void Display::navigation(Block& block) {
	system("cls");
	show(block);

	std::cout << "\n\n\n\n\n";
	std::cout << "(Press Q to exit navigation mode)\n";

	char key = 'm';
	bool cont = control.moveCursor(block, key);

	while (cont) {
		key = _getch();
		system("cls");
		show(block);
		std::cout << "\n\n\n\n\n";
		std::cout << "(Press Q to exit navigation mode)\n";
		cont = control.moveCursor(block, key);
	}
}

void Display::insertion(Block& block) {
	system("cls");
	show(block);

	std::cout << "\n\n\n";
	std::cout << "Enter text to insert:\n";
	std::cout << "----------------------\n";
	
	std::string newString;
	std::cin >> newString;

	Span* newSpan = new Span(newString);
	block.insert_middle(newSpan);
}

void Display::setMaxLineCharLength(Block& block) {
	system("cls");
	show(block);

	std::cout << "\n\n\n";
	std::cout << "Enter the amount of characters to display per line: ";

	std::cin >> maxLineCharLength;
}

void Display::printFromFile(std::string fName) {
	std::ifstream input(fName);
	std::string nextLine;
	while (std::getline(input, nextLine)) {
		std::cout << nextLine << "\n";
	}
	input.close();
}

std::string Display::readFromFile(std::string fName) {
	std::ifstream input(fName);
	std::string content((std::istreambuf_iterator<char>(input))
		, (std::istreambuf_iterator<char>()));
	return content;
}