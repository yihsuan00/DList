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
		
		node->golock();//利用虛擬函數讓父類別指標可以指到子類別的函式
	}

}
template<typename T>
void LockDList<T>::remove(DListNode<T>* node)
{
	if (node == NULL)
		return;
	else if (node->getlock() == true)//利用虛擬函數讓父類別可以指到子類別的東西
		return;
	else {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	delete node;
	node = 0;//避免編譯錯誤;
	size--;}
	
}
