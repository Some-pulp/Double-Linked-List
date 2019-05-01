//
// Created by Peter on 2019-04-23.
//

#include "TextClass.h"
#include <stdexcept>


TextClass::TextClass()
{
    //Constructor simplified with Double Linked List notes in Moodle
    head = tail = iter = nullptr;
}

void TextClass::insertHead(char val) {
    //If list empty (head == nullptr)
    if (head == nullptr)
        head = tail = new Link(val);
    else {
        //Otherwise, make a new link w/ given value, make n point to head, tail stays nullptr
        Link* tmp = new Link(val, nullptr, head);
        head->setPrev(tmp);
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
    counter--;
    return v;

}


void TextClass::insertTail(char val) {
    //Tail points to nullptr?
    if (tail == nullptr)
        tail = head = new Link(val);
    else {

        Link* tmp = new Link(val, tail, nullptr);
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
    counter--;
    return v;
}

bool TextClass::findKey(char key) {
    Link* tmp = iter;
    
    //If nothing has been found
    if(iter == nullptr){
        iter = head;
        tmp = head;
    }
    else{
        if(iter->getNext() != nullptr) {
            tmp = iter;
            iter = iter->getNext();
            
        }
        else{
            tmp = iter;
            iter = head;
        }
        
    }
    //If the value is found
    if(iter->getVal() == key) {
        return true;
    }
    else{
        iter = iter->getNext();
    }
    
    
    //Until iter reaches it's starting point (tmp)
    while(iter != tmp){
        if(iter->getVal() == key) {
            return true;
        }
        
        //if next is nullptr, wrap back to head
        if(iter->getNext() == nullptr) {
            iter = head;
        }
        
        
        
        iter = iter->getNext();
    }
    iter = nullptr;
    return false;
    
}


//Two cases:
//Middle of list
//Head of list
bool TextClass::insertKey(char key){
    if(iter == nullptr)
        return false;
    
    //Head of list, insert
    if(iter == head) {
        Link* newLink = new Link(key, nullptr, head);
        head->setPrev(newLink);
        head = newLink;
        return true;
    }
    
    //Middle of list, insert
    //Insert at index before iter
    Link* tmp = new Link(key, iter->getPrev(), iter);
    iter->getPrev()->setNext(tmp);
    iter->setPrev(tmp);
    return true;
}

bool TextClass::isEmpty(){return (head && tail);}

bool TextClass::deleteIter(){
    if(iter == nullptr)
        return false;
    //Iter is head
   if(iter == head)
       deleteHead();
    //Iter is tail
    else if(iter == tail)
       deleteTail();
    //Iter is other
    else{
        Link*tmp = iter;
        tmp->getPrev()->setNext(tmp->getNext());
        tmp->getNext()->setPrev(tmp->getPrev());
        delete tmp;
    }
    
    
    
    iter = nullptr;
    return true;
}

//bool deleteKey(char key){}

string TextClass::displayList(){
    ostringstream list;
    Link* tmp = head;
    //While head not nullptr
    while(tmp){
        //Add value to list separated by space
        list << tmp->getVal();
        //Causes head to be nullptr, not good!!!
        
        tmp = tmp->getNext();
    }
    
    
    return list.str();
}
