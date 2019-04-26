#include "Link.h"

Link::Link(char val) {
	this->val = val;
	n = nullptr;
	p = nullptr;
}

Link::Link(char value, Link* next, Link* prev){
	val = value;
	n = next;
	p = prev;
}

void Link::setPrev(Link* prev) { p = prev; }
Link* Link::getPrev() { return p; }
void Link::setNext(Link* next) { n = next; }
Link* Link::getNext() { return n; }
void Link::setVal(char v) { val = v; }
char Link::getVal(){return val;}
