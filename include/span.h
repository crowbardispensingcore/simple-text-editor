#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <sstream>

class Span {
public:
	Span();
	Span(std::string str);
	Span(const Span& rhs);
	void set(std::string str);
	std::string getString();
	void insert(Span* span, int index);

	Span* prev;
	Span* next;
	std::string piece;
	// the original idea is to use piece as a pointer
	//int offset;
	int length;
};

#endif