#pragma once

template <class T>
class LinkNode
{
protected:
	T data;
	LinkNode<T> *next;
public:
	LinkNode(T);

	void setData(T);
	T getData();
	LinkNode<T> *getNext();
	void setNext(LinkNode<T>*);
};


template <class T>
LinkNode<T>::LinkNode(T d) {
	data = d;
}

/*************************************************************
getData
returns data value
pre:
post: returns data value
return: <T>
*************************************************************/
template <class T>
T LinkNode<T>::getData() {
	return data;
}


/*************************************************************
setData
changes data value
pre: <T>
post: changes data value to given data value (d)
return: void
*************************************************************/
template <class T>
void LinkNode<T>::setData(T d) {
	data = d;
}


/*************************************************************
getNext
returns next value
pre:
post: returns next value
return: <T>*
*************************************************************/
template <class T>
LinkNode<T>* LinkNode<T>::getNext() {
	return next;
}



/*************************************************************
setNext
changes next value
pre: <T>*
post: changes next value to given next value (n)
return: void
*************************************************************/
template <class T>
void LinkNode<T>::setNext(LinkNode<T>* n) {
	next = n;
}