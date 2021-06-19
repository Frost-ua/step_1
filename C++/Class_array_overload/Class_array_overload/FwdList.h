#pragma once
#include <iostream>;
using namespace std;

template<typename T>
struct Node_1   
{
	T data;
	Node_1* next;												  //pointer for the next node.
	Node_1(const T& data = T(), Node_1* next = nullptr)
		: data(data), next(next)
	{}
};

template<typename T>
class FwdList
{
public:
	bool isEmpty()const;
	size_t getSize()const;
	void pushFront(const T& data);
	void print()const;
	void popFront();
	void eraseAfter(const T& data);
	void InsertAfter(const T& data, const T& new_data);
	void clear();
	~FwdList();


private:
	Node_1<T>* findNode(const T& data);
	Node_1<T>* head = nullptr;
	size_t size = 0;

};

template<typename T>
inline bool FwdList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline size_t FwdList<T>::getSize() const
{
	return size;
}

template<typename T>
inline void FwdList<T>::pushFront(const T& data)
{
	Node_1<T>* addNode = new Node_1<T>(data, head);							//create node with info-part "data". Next after this node.
	head = addNode;														//moved pointer to 1-st element of addNode.
	size++;
}

template<typename T>
inline void FwdList<T>::print() const
{
	Node_1<T>* tmp = head;
	cout << "\nList:\n";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;												 //moved to the next node.
	}
	cout << endl;
}

template<typename T>
inline void FwdList<T>::popFront()
{
	if (!isEmpty())
	{
		Node_1<T>* tmp = head; // remember head -- address of 1-st node, which we delete
		head = head->next;// now the head of list is 2-d node
		delete tmp;  // delete 1-st
		--size;
	}
	else
	{
		throw logic_error("popFront() : List is empty!");
	}
}

template<typename T>
inline void FwdList<T>::eraseAfter(const T& data)
{
	auto searchNode = findNode(data);
	if (searchNode == nullptr)
	{
		cout << "Node " << data << " not found\n";
		return;
	}
	if (searchNode->next == nullptr)
	{
		return;
	}
	auto delNode = searchNode->next; // must be deleted
	searchNode->next = delNode->next; // = searchNode->next->next;
	delete delNode;
}

template<typename T>
inline void FwdList<T>::InsertAfter(const T& searchData, const T& new_data)
{
	auto searchNode = findNode(searchData);

	if (searchNode == nullptr)
	{
		cout << "Insert after no found data.\n";
		return;
	}

	auto addNode = new Node_1<T>(new_data, searchNode->next);
	searchNode->next = addNode;
	size++;


}

template<typename T>
inline void FwdList<T>::clear()
{
	while (!isEmpty())
	{
		this->popFront();
	}
}

template<typename T>
inline FwdList<T>::~FwdList()
{
	clear();
}

template<typename T>
inline Node_1<T>* FwdList<T>::findNode(const T& data)
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)  // while we have elements or we found the data
	{
		tmp = tmp->next; //move up
	}
	return tmp; // address or nullptr


	return tmp;
}
