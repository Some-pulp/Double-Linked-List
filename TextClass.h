#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Link.h"

using namespace std;

class TextClass {
private:
	Link* head;
	Link* tail;
	Link* iter = nullptr;//Last item fount
	int counter = 0;
public:
	TextClass();
	void insertHead(char val);
	char deleteHead();
	void insertTail(char val);
	char deleteTail();
	bool isEmpty();
	//Test section 2
	//
	bool findKey(char key);
	bool insertKey(char key);

	bool deleteIter();
	bool deleteKey(char key);

	string displayList();



};
