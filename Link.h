#pragma once
class Link {
private:
	char val;
	Link* n;
	Link* p;
public:
	Link(char val);
	Link(char val, Link* next, Link* prev);
	void setPrev(Link* prev);
	Link* getPrev();
	void setNext(Link* next);
	Link* getNext();
	void setVal(char v);
	char getVal();
};
