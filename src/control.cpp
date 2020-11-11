#include "../include/control.h"

bool Control::moveCursor(Block& block, char key) {
	if (key == 'q' || key == 'Q') {
		return false;
	}
	
	switch (key) {
	case 'a':
	case 'A':
		// std::cout << "Left arrow\n";
		if (block.cursor > 0) {
			block.cursor--;
		}
		// std::cout << block.cursor << "\n";
		break;
	case 'd':
	case 'D':
		// std::cout << "Right arrow\n";
		if (block.cursor < block.length - 1) {
			block.cursor++;
		}
		// std::cout << block.cursor << "\n";
		break;
	default:
		break;
	}

	return true;;
}