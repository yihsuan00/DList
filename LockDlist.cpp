#include<iostream>
#include"DList.h"
#include"DListNode.h"
#include"LockDlistNode.h"
#include"LockDlist.h"

using namespace std;

template<typename T>
LockDList<T>::LockDList()
{ ; }

template<typename T>
DListNode <T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) 
{
	return new LockDListNode<T>(item, prev, next);
}

template<typename T>
 void LockDList<T>::lockNode(DListNode<T>* node)
{
	if (node == NULL)
		return;
	else {
		
		node->golock();//�Q�ε�������������O���Хi�H����l���O���禡
	}

}
template<typename T>
void LockDList<T>::remove(DListNode<T>* node)
{
	if (node == NULL)
		return;
	else if (node->getlock() == true)//�Q�ε�������������O�i�H����l���O���F��
		return;
	else {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
	node = 0;//�קK�sĶ���~;
	size--;}
	
}
