#include "../include/block.h"

Block::Block()
	: head(nullptr)
	, tail(nullptr)
	, prev(nullptr)
	, next(nullptr)
	, length(0)
	, cursor(0) {

}

std::string Block::getString() {
	std::string s;
	Span* nextSpan;
	nextSpan = head;
	while (nextSpan != nullptr) {
		s.append(nextSpan->getString());
		nextSpan = nextSpan->next;
	}
	return s;
}

void Block::append(Span* s) {
	// if the insert point is at the end of a block
	length += s->length;
	// if block is empty
	if (head == nullptr) {
		head = s;
		tail = s;
		cursor = cursor + s->length - 1;
		return;
	}

	tail->next = s;
	s->prev = tail;
	tail = s;

	cursor = cursor + s->length - 1;
	return;
}

void Block::insert_middle(Span* s) {
	// insert in the middle of a span
	Span* targetSpan = findCursorSpan();
	targetSpan->insert(s, findCursorSpanIndex());
	length += s->length;
	cursor = cursor + s->length;
}

Span* Block::findCursorSpan() {
	// find the span the current cursor belongs to

	if (head == nullptr) {
		return nullptr;
	}

	Span* span = head;
	int currentLength = 0;

	while (currentLength < cursor || span != nullptr) {
		currentLength += span->length;
		if (currentLength > cursor) {
			return span;
		}
		span = span->next;
	}
	return span;
}

int Block::findCursorSpanIndex() {
	Span* targetSpan = findCursorSpan();
	if (head == nullptr || targetSpan == nullptr) {
		return 0;
	}
	
	int prevLength = 0;
	Span* span = head;
	while (span != targetSpan && span != nullptr) {
		prevLength += span->length;
		span = span->next;
	}

	int offset = cursor - prevLength;
	
	return offset;
}