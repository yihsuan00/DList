#ifndef LOCKDLIST_H
#define LOCKDLIST_H

#include "DListNode.h"
#include"LockDlistNode.h"


template<typename T>
class LockDList :public DList<T>
{
protected:
	DListNode <T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) override;

public:
	LockDList();
	void lockNode(DListNode<T>* node);
	void remove(DListNode<T>* node) override;//�ˬd�O�_�Ƽg���\
	
};
#endif

