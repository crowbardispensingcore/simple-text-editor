#include <iostream>
#include <string>

#include "../include/block.h"
#include "../include/control.h"
#include "../include/display.h"

using namespace std;

int main()
{
	Display display;

	display.menu();

	/*string p1 = "000";
	string p2 = "12345";
	string p3 = "aaaa";
	string p4 = "He had done everything right. "
		"There had been no mistakes throughout the entire process. "
		"It had been perfection and he knew it without a doubt, "
		"but the results still stared back at him with the fact "
		"that he had lost.";

	Span* s1 = new Span(p1);
	Span* s2 = new Span(p2);
	Span* s3 = new Span(p3);
	Span* s4 = new Span(p4);

	Span* spanPtr;

	Block b1;
	display.show(b1);
	b1.append(s2);
	display.show(b1);
	b1.append(s3);
	display.show(b1);
	
	b1.cursor = 5;
	display.show(b1);
	b1.insert_middle(s1);
	display.show(b1);
	b1.cursor = 3;
	display.show(b1);
	b1.insert_middle(s4);
	display.show(b1);*/
}