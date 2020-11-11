#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include "span.h"

class Block {
public:
	Block();
	std::string getString();

	void append(Span* s);
	void insert_middle(Span* s);

	Span* findCursorSpan();
	int findCursorSpanIndex();

	Span* head;
	Span* tail;
	// for chained blocks
	Block* prev;
	Block* next;
	int length;

	int cursor;
};

#endif