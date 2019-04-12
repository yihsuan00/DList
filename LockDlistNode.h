#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
template<typename T>
class DListNode;

template<typename T>
class LockDList;

template<typename T>
class DList;

template<typename T>
class LockDListNode :public DListNode<T>
{
protected:
	bool lock;
	friend class LockDList<T>;
	friend class DList<T>;
public:
	LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n);

	/**
	*  golock() lock the node to keep it from being deleted;
	*/

	void   golock()override;

	/**
	*  getlock() to return the lock to see whether the node is lock;
	*/
	bool   getlock()override;
};

#endif

