#include "TextClass.h"
#include <stdexcept>


TextClass::TextClass()
{
	//Constructor simplified with Double Linked List notes in Moodle
	head = tail = iter = nullptr;
}

void TextClass::insertHead(char val) {
	//If list empty (head == nullptr)
	if (!head)
		head = tail = new Link(val);
	else {
		//Otherwise, make a new link w/ given value, make n point to head, tail stays nullptr
		Link* tmp = new Link(val, head, nullptr);
		//set p to tmp
		head->setPrev(tmp);
		//make head point to tmp
		head = tmp;
	}
	counter++;
}


char TextClass::deleteHead() {
	if (!head)
		throw std::underflow_error("the list is empty");
	
	Link* tmp = head;
	//Placeholder for val being removed
	char v = tmp->getVal();

	//Update next for head
	head = head->getNext();

	//If the list is empty return to empty state
	if (!head)
		tail = nullptr;
	else
		//if not empty, update head to make it the first link
		head->setPrev(nullptr);

	delete tmp;
	return v;

}


void TextClass::insertTail(char val) {
	//Tail points to nullptr?
	if (!tail)
		tail = head = new Link(val);
	else {
		//Symmetric with insertHead in arguments
		Link* tmp = new Link(val, nullptr, tail);
		tail->setNext(tmp);
		tail = tmp;
	}
	counter++;
}


char TextClass::deleteTail() {
	if (!tail)
		throw std::underflow_error("the list is empty");

	Link* tmp = tail;
	char v = tmp->getVal();
	tail = tail->getPrev();

	if (!tail)
		head = nullptr;
	else
		tail->setNext(nullptr);

	delete tmp;
	return v;
}

//////////////////Iter Test/////////////////////
bool TextClass::findKey(char key) {
	int flag = 0;

	Link* tmp = head;
	while (flag < counter) {
		
		//if the link value equals key, iter points to tmp, true
		if (iter != nullptr)
			tmp = iter->getNext();

		if (tmp->getVal() == key) {
			iter = tmp;
			//delete tmp;
			return true;
		}
		if (tmp->getNext() == tail)
			tmp = head;
		tmp = tmp->getNext();
		flag++;
	}
	delete tmp;
	return false;

	//if found, iter points to selected Link, set next to next link
	//else, iter == nullptr, return false


	
}

bool TextClass::insertKey(char key) {
	//If p is nullptr, do nothing and return
	if (!iter->getPrev())
		return false;
	else {
		Link* inserted = iter->getPrev();
		inserted->setVal(key);
		return true;
	}
}

bool TextClass::isEmpty() { return (head && tail); }

bool deleteIter() {}

bool deleteKey(char key) {}

string TextClass::displayList() {
	ostringstream list;
	//While head not nullptr
	while (head) {
		//Add value to list separated by space
		list << head->getVal();
		head = head->getNext();
	}
	return list.str();
}
