#include<iostream>
#include"DListNode.h"
#include"LockDlistNode.h"

using namespace std;

template<typename T>
LockDListNode<T>::LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n):DListNode<T>(i,p,n)
{
	
	lock = false;
}
template<typename T>
void LockDListNode<T>::golock()
{
	lock = true;
}
template<typename T>
bool LockDListNode<T>::getlock()
{
	return lock;
}