#pragma once
#include <iostream>;
using namespace std;

template<typename T>
struct Node
{
	T data;
	Node* next;							 //pointer for the next node.
	Node* prev;
	Node(const T& data = T(), Node* prev = nullptr, Node* next = nullptr)
		: data(data), prev(prev), next(next)
	{}
};

template<typename T>
class DList
{
public:
	DList() = default;
	void pushBack(const T& data);
	void pushFront(const T& data);
	void popBack();
	void popFront();
	void deleteList();
	void deleteData(const T& search_data);
	void rotateList();
	void insertBefore(const T& search_data, const T& insert_data);
	void insertAfter(const T& search_data, const T& insert_data);
	size_t replaceData(const T& search_data, const T& insert_data);
	void print()const;
	void printR()const;
	bool isEmpty()const;
	bool checkSameData(const DList& list, const T& data)const;

	DList<T>(const DList<T>& other);       //copy ctor
	DList<T>& operator = (const DList<T> &other);
	DList<T> operator + (const DList<T>& other);
	void operator += (const DList<T>& other);
	DList<T> operator * (const DList<T>& other)const;


	~DList()
	{
		deleteList();
		head = nullptr;
	}

	
private:
	Node<T>* findNode(const T& data);
	Node<T> * head = nullptr, * tail = nullptr;
	size_t size = 0;
};

template<typename T>
inline void DList<T>::pushBack(const T& data)
{
	auto addNode = new Node<T>(data, tail, nullptr);

	if (!isEmpty())
		tail->next = addNode;
	else
		head = addNode;

	tail = addNode;
	++size;
}

template<typename T>
inline void DList<T>::pushFront(const T& data)
{
	auto addNode = new Node<T>(data, nullptr, head);
	if (!isEmpty()){
		head->prev = addNode;
		addNode->next = head;
}
	else {
		head = addNode;
		tail = addNode;
	}
	head = addNode;
	++size;
}

template<typename T>
inline void DList<T>::popBack()
{
	if (!isEmpty())
	{
		Node<T> *tmp = tail;
		if (tail == head)
		{
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
		delete tmp;
		--size;
	}
}

template<typename T>
inline void DList<T>::popFront()
{
	Node<T>* tmp = head;
	if (head == tail)
	{
		tail = nullptr;
		head = nullptr;
	}
	else
	{
		head = head->next;
		head->prev = nullptr;
	}
	delete tmp;
	--size;
}

template<typename T>
inline void DList<T>::deleteList()
{
	Node<T>* tmp = head;
	for (size_t i = 0; i < size; i++)
	{
		if (tail == head)
		{
			delete head;
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			tmp = head->next;
			delete head;
			head = tmp;
		}	
	}
	size = 0;
}

template<typename T>
inline void DList<T>::deleteData(const T& search_data)
{
	auto searchNode = findNode(search_data);
	if (searchNode == nullptr)
	{
		cout << "Data isn't found!\n";
		return;
	}
	if (searchNode == head)
	{
		popFront();
		return;
	}
	if (searchNode == tail)
	{
		popBack();
		return;
	}
	searchNode->prev->next = searchNode->next;
	searchNode->next->prev = searchNode->prev;
	--size;
}

template<typename T>
inline void DList<T>::rotateList()                      //        ??????????????????????????????????????
{
	Node<T> *tmp = head; 
	head = tail; 
	tail = tmp;
	Node<T> *p = head; 

	while (p != nullptr) 
	{ 
		tmp = p->next; 
		p->next = p->prev; 
		p->prev = tmp; 
		p = p->next;
	}
}

template<typename T>
inline void DList<T>::print() const
{
	Node<T> *tmp = head;
	cout << "List in direct order:\t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
	cout << endl;
}

template<typename T>
inline void DList<T>::printR() const
{
	Node<T> *tmp = tail;
	cout << "List in revert order:\t";
	while (tmp != nullptr)
	{
		cout << tmp->data << "\t";
		tmp = tmp->prev;
	}
	cout << endl;
}

template<typename T>
inline bool DList<T>::isEmpty() const
{
	return head == nullptr;
}

template<typename T>
inline DList<T>::DList<T>(const DList& other)                              // copy ctor
{
	Node<T>* tmp = other.head;
	for (size_t i = 0; i < other.size; i++)
	{
		this->pushBack(tmp->data);
		tmp = tmp->next;
	}
}

template<typename T>
inline DList<T> &DList<T>::operator=(const DList<T>& other)
{
	//DList<T> result;
	Node<T>* tmp = other.head;
	
	for (size_t i = 0; i < other.size; i++)
	{
		this->pushBack(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}

template<typename T>
inline DList<T> DList<T>::operator+(const DList& other)
{
	DList<T> result;// (*this);

	result = *this;
	Node<T>* tmp = other.head;
	for (size_t i = 0; i < other.size; i++)
	{
		result.pushBack(tmp->data);
		tmp = tmp->next;
	}

	/*result.tail->next = other.head;
	result.tail = other.tail;
	result.size = this->size + other.size;*/
	return result;
}

template<typename T>
inline void DList<T>::operator+=(const DList& other)
{
	Node<T>* tmp = other.head;
	for (size_t i = 0; i < other.size; i++)
	{
		this->pushBack(tmp->data);
		tmp = tmp->next;
	}

/*
	this->tail->next = other.head;
	other.head->prev = this->tail;
	this->tail = other.tail;
	this->size += other.size;
*/
}

template<typename T>
inline DList<T> DList<T>::operator*(const DList& other) const
{
	DList<T> result;
	Node<T>* tmp = head;
	Node<T>* otherTmp = other.head;
	for (size_t i = 0; i < size; i++)
	{
		if (tmp != nullptr)
		{
			if (!checkSameData(result, tmp->data))
			{
				for (size_t i = 0; i < other.size; i++)
				{
					if (tmp->data == otherTmp->data)
					{
						result.pushBack(tmp->data);
						break;
					}
					otherTmp = otherTmp->next;
				}
			}
		}
		tmp = tmp->next;
		otherTmp = other.head;
	}
	return result;
}

template<typename T>
inline bool DList<T>::checkSameData(const DList & list,const T& data)const {

	Node<T>* fantomTmp = list.head;

	for (size_t i = 0; i < list.size; i++)
	{
		if (data == fantomTmp->data)
		{
			return true;
		}
		fantomTmp = fantomTmp->next;
	}
	return false;
}

template<typename T>
inline void DList<T>::insertBefore(const T& search_data, const T& insert_data)
{
	auto searchNode = findNode(search_data);
	if (searchNode == nullptr)
	{
		cout << "Data isn't found!\n";
		return;
	}
	if (searchNode == head)
	{
		pushFront(insert_data);
		return;
	}
	auto insertNode = new Node<T>(insert_data, searchNode->prev, searchNode);
	searchNode->prev->next = insertNode;
	searchNode->prev = insertNode;
	++size;
}

template<typename T>
inline void DList<T>::insertAfter(const T& search_data, const T& insert_data)
{
	auto searchNode = findNode(search_data);
	if (searchNode == nullptr)
	{
		cout << "Data isn't found!\n";
		return;
	}
	if (searchNode == tail)
	{
		pushBack(insert_data);
		return;
	}
	auto insertNode = new Node<T>(insert_data, searchNode, searchNode->next);
	searchNode->next->prev = insertNode;
	searchNode->next = insertNode;
	++size;
}

template<typename T>
inline size_t DList<T>::replaceData(const T& search_data, const T& insert_data)
{
	size_t counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		auto searchNode = findNode(search_data);
		if (searchNode != nullptr)
		{
			searchNode->data = insert_data;
			++counter;
		}
	}
	if (counter == 0)
	{
		cout << "Data isn't found!\n";
		return 0;
	}
	return counter;
}

template<typename T>
inline Node<T>* DList<T>::findNode(const T& data)
{
	auto tmp = head;
	while (tmp != nullptr && tmp->data != data)
	{
		tmp = tmp->next;
	}
	return tmp;
}


