#include "../include/span.h"

Span::Span()
	: prev(nullptr)
	, next(nullptr)
	, piece("")
	, length(0) {
}

Span::Span(std::string str)
	: prev(nullptr)
	, next(nullptr) {
	piece = str;
	length = str.length();
}

Span::Span(const Span& rhs) {
	prev = rhs.prev;
	next = rhs.next;
	piece = rhs.piece;
	//offset = rhs.offset;
	length = rhs.length;
}

void Span::set(std::string str) {
	prev = nullptr;
	next = nullptr;
	piece = str;
	//offset = 0;
	length = str.length();
}

std::string Span::getString() {
	std::stringstream ss;
	for (int i = 0; i < length; i++) {
		ss << piece[i];
	}
	return ss.str();
}

void Span::insert(Span* span, int index) {
	std::string firstHalf;
	std::string secondHalf;
	// the first half of the original string
	for (int i = 0; i < index; i++) {
		firstHalf.push_back(piece[i]);
	}
	// the second half of the original string
	for (int i = index; i < length; i++) {
		secondHalf.push_back(piece[i]);
	}

	// create a new span for the second half of the string
	Span* newSpan = new Span(secondHalf);
	newSpan->prev = span;
	newSpan->next = next;

	// the current span will be the leading span
	piece = firstHalf;
	length = firstHalf.length();
	next = span;


	span->prev = this;
	span->next = newSpan;
}