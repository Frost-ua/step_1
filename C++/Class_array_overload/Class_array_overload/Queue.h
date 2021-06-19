#pragma once
#include<string>
#include <tuple>
#include <vector>


template<class T>
class Queue
{
public:
	Queue(const size_t& capacity = DEFAULT_CAPACITY);
	void print()const;
	void push(const T  &data);
	void pop();
	bool isEmpty()const;
	size_t getSize()const;
	const T& front() const;
	~Queue();
private:
	bool isFull()const;
	size_t real_size = 0;
	static const size_t DEFAULT_CAPACITY = 5;
	T* buffer;
};

template<class T>
inline Queue<T>::Queue(const size_t& capacity)
{
	buffer = new T[capacity]{};
}

template<class T>
inline void Queue<T>::print() const
{
	if (real_size > 0)
	{
		for (size_t i = 0; i < real_size; i++)
		{
			cout << buffer[i] << "\t";
		}
		cout << "\n\n";
	}
	else
	{
		throw out_of_range("Queue is empty!\n\n");
	}
}

template<class T>
inline size_t Queue<T>::getSize() const
{
	return real_size;
}

template<class T>
inline const T& Queue<T>::front() const
{
	if (!isEmpty())
	{
		return buffer[0];
	}
	else
	{
		throw out_of_range("Queue is empty!\n\n");
	}
}

template<class T>
inline Queue<T>::~Queue()
{
	if (buffer != nullptr)
	{
		delete[] buffer;
		buffer = nullptr;
	}
}

template<class T>
inline bool Queue<T>::isFull() const
{
	return real_size == DEFAULT_CAPACITY;
}

template<class T>
inline void Queue<T>::push(const T &data)
{
	if (isFull())
	{
		throw out_of_range("Queue is full!\n\n");
	}
	buffer[real_size] = data;
	++real_size;
}

template<class T>
inline void Queue<T>::pop()
{
	if (!isEmpty())
	{
		for (size_t i = 0; i < real_size - 1; i++)
		{
			buffer[i] = buffer[i + 1];
		}
		--real_size;
	}
	else
	{
		throw out_of_range("Queue is empty!\n\n");
	}
}

template<class T>
inline bool Queue<T>::isEmpty() const
{
	return real_size == 0;
}

