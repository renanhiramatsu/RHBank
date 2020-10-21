#pragma once

#include <iostream>
#include "LinkNode.h"
#include "LinkList.h"

template <class T>
class Queue : public List<T> {
protected:
	LinkNode<T> *front;
	LinkNode<T> *rear;

public:
	Queue();
	Queue(T);
	bool enQueue(T);
	bool deQueue();
	T Front();
	T Rear();
	bool isEmpty();
	bool empty();
	~Queue();
};

template <class T>
Queue<T>::Queue()
{
	this->front = NULL;
	this->rear = NULL;
	this->count = 0;
}

template <class T>
Queue<T>::Queue(T data) : List<T>(data)
{
	if (this->createList(data)) {
		this->front = this->head;
		this->rear = this->head;
		this->count = 1;
	}
	else {
		std::cout << "\nOverflow\n";
		exit(1);
	}

}

/*************************************************************
enQueue
queues data value into the list
pre:
data - a template data value
post: adds the given data value to the front of the list
return: bool
*************************************************************/
template <class T>
bool Queue<T>::enQueue(T data)
{

	if (this->addDataFront(data))
	{
		front = this->head;
		return true;
	}
	else
	{
		std::cout << "Overflow" << std::endl;
		return false;
	}

}

/*************************************************************
deQueue
dequeues data value from the list
pre:
post: deletes the first data value from the queue list
return: bool
*************************************************************/
template <class T>
bool Queue<T>::deQueue()
{
	if (this->delFirst())
	{
		front = this->head;
		return true;
	}
	else
	{
		std::cout << "Underflow" << std::endl;
		return false;
	}

}

/*************************************************************
Front
finds and returns the front data value
pre:
post: returns the front data value
return: <T>
*************************************************************/
template <class T>
T Queue<T>::Front()
{
	if (front == '\0') {
		std::cout << "Queue is empty. " << std::endl;
	}
	return front->getData();
}

/*************************************************************
Rear
finds and returns the rear data value
pre:
post: returns the rear data value
return: <T>
*************************************************************/
template <class T>
T Queue<T>::Rear()
{
	return rear->getData();
}

/*************************************************************
isEmpty
if the queue is empty, return true
pre:
post: returns true if queue is empty
return: bool
*************************************************************/
template <class T>
bool Queue<T>::isEmpty() {
	if (this->head == NULL && rear == NULL)
		return true;
	return false;
}

/*************************************************************
empty
empties the queue
pre:
post: empties the queue
return: void
*************************************************************/
template <class T>
bool Queue<T>::empty()
{
	this->head = front;
	if (this->emptyList())
	{
		this->head = NULL;
		this->rear = NULL;
		return true;
	}
}

template <class T>
Queue<T> ::~Queue()
{
	empty();
}