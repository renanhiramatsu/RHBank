#pragma once

#include <iostream>
#include <string>
#include "LinkNode.h"

template <class T>
class List
{
protected:
	int count;
	LinkNode<T> *head;
	std::string sortType;
public:
	List();
	List(T);
	bool createList(T);

	bool addDataEnd(T);
	bool addDataFront(T);
	bool addDataSd(T);
	bool addDataSa(T);

	bool delData(T);
	bool delLast();
	bool delFirst();

	LinkNode<T>* findData(T);
	int getCount();
	bool emptyList();
	void printData();

	~List();
};



template <class T>
List<T>::List() {
	count = 0;
	head = NULL;
}



template <class T>
List<T>::List(T data) {
	count = 0;
	createList(data);
}



template <class T>
bool List<T>::createList(T data) {
	head = new LinkNode<T>(data);
	if (!head) {
		std::cout << "\nHeap Overflow\n";
		return false;
	}
	count = 1;
}



/*************************************************************
addDataEnd
adds data at the end of the list
pre:
data - a template data value
post: adds the given data value to the node at the end of the list
return: bool
*************************************************************/
template <class T>
bool List<T>::addDataEnd(T data) {
	bool status;
	if (head == '\0') {
		if (createList(data))
			return true;
	}
	else {
		LinkNode<T> *ptr = head;
		while (ptr->getNext() != '\0') {
			ptr = ptr->getNext();
		}
		ptr->setNext(new LinkNode<T>(data));
		if (!ptr->getNext()) {
			std::cout << "\nHeap Overflow\n";
			return false;
		}
		ptr = ptr->getNext();
		ptr->setNext('\0');
		count++;
	}
}



/*************************************************************
addDataFront
adds data at the front of the list
pre:
data - a template data value
post: adds the given data value to the node at the front of the list
return: bool
*************************************************************/
template <class T>
bool List<T>::addDataFront(T data) {
	if (head == '\0' && createList(data))
		return true;
	else {
		LinkNode<T> *ptr = head;
		if (!ptr) {
			std::cout << "\nHeap Overflow\n";
			return false;
		}
		head = new LinkNode<T>(data);
		head->setNext(ptr);
	}
	count++;
	return true;

}



/*************************************************************
addDataSd
adds data in sorted descending order
pre:
data - a template data value
post: adds the given data value to a node in descending order
in the list
return: bool
*************************************************************/
template <class T>
bool List<T>::addDataSd(T data) {
	if (head == '\0' && createList(data)) {
		return true;
	}
	else
	{
		LinkNode<T> *ptr = head;
		LinkNode<T> *ptrPrev = head;

		// if first pos value is less than data value, place data value in front
		if (ptr->getData() <= data)
		{
			LinkNode<T> *ptr = head;
			head = new LinkNode<T>(data);
			if (!head) {
				std::cout << "\nHeap Overflow\n";
				return false;
			}
			head->setNext(ptr);
			count++;

		}
		// if first pos value is greater than data value, place data value in end
		else if (ptr->getData() >= data && ptr->getNext() == '\0')
		{
			ptr->setNext(new LinkNode<T>(data));
			if (!ptr->getNext()) {
				std::cout << "\nHeap Overflow\n";
				return false;
			}
			ptr = ptr->getNext();
			count++;
		}
		else
		{
			while (ptr->getData() >= data && ptr->getNext() != '\0')
			{
				ptrPrev = ptr;
				ptr = ptr->getNext();
			}
			if (ptr->getData() >= data && ptr->getNext() == '\0')
			{
				ptrPrev = ptr;
				ptr = ptr->getNext();
			}


			ptrPrev->setNext(new LinkNode<T>(data));
			if (!ptrPrev->getNext()) {
				std::cout << "\nHeap Overflow\n";
				return false;
			}
			ptrPrev = ptrPrev->getNext();
			ptrPrev->setNext(ptr);
			count++;
		}
	}
}



/*************************************************************
addDataSa
adds data in sorted ascending order
pre:
data - a template data value
post: adds the given data value to a node in ascending order
in the list
return: bool
*************************************************************/
template <class T>
bool List<T>::addDataSa(T data) {
	if (head == '\0' && createList(data)) {
		return true;
	}
	else
	{
		LinkNode<T> *ptr = head;
		LinkNode<T> *ptrPrev = head;

		// if first pos value is greater than data value, place data value in the front
		if (ptr->getData() >= data)
		{
			LinkNode<T> *ptr = head;
			head = new LinkNode<T>(data);
			if (!head) {
				std::cout << "\nHeap Overflow\n";
				return false;
			}
			head->setNext(ptr);
			count++;
		}
		// if first pos value is greater than data value, place data value in end
		else if (ptr->getData() <= data && ptr->getNext() == '\0')
		{
			ptr->setNext(new LinkNode<T>(data));
			if (!ptr->getNext()) {
				std::cout << "\nHeap Overflow\n";
				return false;
			}
			ptr = ptr->getNext();
			count++;
		}
		else
		{
			while (ptr->getData() <= data && ptr->getNext() != '\0')
			{
				ptrPrev = ptr;
				ptr = ptr->getNext();
			}
			if (ptr->getData() <= data && ptr->getNext() == '\0')
			{
				ptrPrev = ptr;
				ptr = ptr->getNext();
			}


			ptrPrev->setNext(new LinkNode<T>(data));
			if (!ptrPrev->getNext()) {
				std::cout << "\nHeap Overflow\n";
				return false;
			}
			ptrPrev = ptrPrev->getNext();
			ptrPrev->setNext(ptr);
			count++;
		}
	}
}



/*************************************************************
delData
deletes data in the List
pre:
data - a template data value
post: deletes ONE data value in the list based on the given data value
return: void
*************************************************************/
template <class T>
bool List<T>::delData(T data) {
	LinkNode<T> *ptrPrev = head;
	LinkNode<T> *ptrNext = head;
	LinkNode<T> *ptr = head;
	bool deleted = 1;
	if (head == NULL) {
		return false;
	}
	else if (head->getNext() == '\0' && head->getData() == data)
	{
		delete head;
		count--;
		head = NULL;
		return true;
	}
	// if data is first value
	else if (ptr->getData() == data)
	{
		ptrNext = ptr->getNext();

		delete ptr;

		head = ptrNext;
		count--;
		return true;
	}
	else {
		while (ptr->getNext() != '\0' && deleted) {
			if (ptr->getData() != data)
			{
				ptrPrev = ptr;
				ptr = ptr->getNext();
				ptrNext = ptr->getNext();
			}
			else
			{
				delete ptr;
				ptrPrev->setNext(ptrNext);
				ptr = ptrPrev;
				count--;
				deleted = 0;
				return true;
			}
		}
		if (ptr->getData() == data)
		{
			delete ptr;
			ptrPrev->setNext(ptrNext);
			ptr = ptrPrev;
			count--;
			return true;
		}
	}
}



/*************************************************************
delLast
deletes the last data value in the List
pre:
post: deletes the last data value in the list based on the given data
value
return: void
*************************************************************/
template <class T>
bool List<T>::delLast() {
	if (head->getNext() == '\0') {
		delete head;
		head = NULL;
		count--;
		return true;
	}
	else if (head == NULL)
		return false;
	else {
		LinkNode<T> *ptr = head;
		while (ptr->getNext() != '\0') {
			ptr = ptr->getNext();
		}
		delete ptr;
		count--;
		return true;
	}

}



/*************************************************************
delFirst
deletes the first data value in the List
pre:
post: deletes the first data value in the list based on the given data
valueg
return: void
*************************************************************/
template <class T>
bool List<T>::delFirst() {
	if (head == NULL)
		return false;
	else if (getCount() == 1) {
		delete head;
		head = NULL;
		count--;
		return true;
	}
	else {
		LinkNode<T> *ptr = head;
		head = ptr->getNext();
		delete ptr;
		count--;
		return true;
	}
}



template <class T>
int List<T>::getCount() {
	return count;
}

/*************************************************************
findData
finds Data in the List
pre:
data - a template data value
post: looks for a given data value in the list and returns that data
value if found
return: a located data value in the list
*************************************************************/
template <class T>
LinkNode<T>* List<T>::findData(T data) {
	LinkNode<T> *ptr = head;
	LinkNode<T> *locNode = '\0';
	if (head == '\0') {
	}
	else if (head->getNext() == '\0') {
		if (head->getData() == data) {
			return head;
		}
		else
			return locNode;
	}
	else
	{
		while (ptr->getNext() != '\0') {
			if (ptr->getData() == data) {
				locNode = ptr;
			}
			ptr = ptr->getNext();
		}
	}
	return locNode;
}



/*************************************************************
emptyList
empties the list
pre:
post: empties the list by deleting every node in the list
return: void
*************************************************************/
template <class T>
bool List<T>::emptyList() {
	if (head == NULL)
		return false;
	else {
		LinkNode<T> *ptrPrev = head;
		LinkNode<T> *ptr = head;
		while (ptr->getNext() != '\0') {
			ptr = ptr->getNext();
			delete ptrPrev;
			ptrPrev = ptr;
		}
		delete ptr;
		head = NULL;
		count = 0;
		return true;
	}
}



/*************************************************************
printData
print the data in the list
pre:
post: prints every node's data in the list
return: void
*************************************************************/
template <class T>
void List<T>::printData() {
	LinkNode<T> *ptr = head;
	int n = 1;
	if (head == NULL) {
		std::cout << "No Data" << std::endl;
	}
	else {
		while (ptr->getNext() != '\0') {
			std::cout << n << ": " << ptr->getData() << std::endl;
			ptr = ptr->getNext();
			n++;
		}
		std::cout << n << ": " << ptr->getData() << std::endl;
	}
}
template <class T>
List<T>::~List() {
	emptyList();
}