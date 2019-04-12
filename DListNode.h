/**
*  A DListNode is a node in a DList (doubly-linked list).
*/

#ifndef DLISTNODE_H
#define DLISTNODE_H


template<typename T>
class DList;

template<typename T>
class LockDList;


template<typename T>
class DListNode {
	/**
	*  item references the item stored in the current node.
	*  prev references the previous node in the DList.
	*  next references the next node in the DList.
	*
	*  DO NOT CHANGE THE FOLLOWING FIELD DECLARATIONS.
	*/

protected:
	DListNode<T>* prev;
	DListNode<T>* next;
	friend class DList<T>;
	friend class LockDList<T>;

public:
	T item;

	/**
	*  DListNode() constructor.
	*  @param i the item to store in the node.
	*  @param p the node previous to this node.
	*  @param n the node following this node.
	*/
	DListNode(const T& i, DListNode<T>* p, DListNode<T>* n);

	/**
	*  golock() lock the node to keep it from being deleted;
	*/
	virtual void golock() { ; }
	/**
	*  getlock() to return the lock to see whether the node is lock;
	*/
	virtual bool  getlock() { return false; }
};

#endif
