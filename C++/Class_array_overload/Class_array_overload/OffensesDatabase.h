#pragma once
#include <string>
#include <vector>
#include"Violetion.h"
#include"MyNode.h"

using std::string;
using std::vector;

class OffensesDatabase
{
public:
	OffensesDatabase() = default;
	bool isEmpty() { return root == nullptr; };
	void add(const string& car_number, const Violetion& violetion);
	void printAll()const;
	void printSpecificCar(const string &car_number)const;
	void printRange(const string& from, const string& till)const;                  
	void printRange(const string& from, const string& till, MyNode* node)const;
	void clear();
	~OffensesDatabase();
private:
	void clear(MyNode* node);
	void print(MyNode * node)const;
	void printAll(MyNode * node)const;
	MyNode* root = nullptr;
	size_t size = 0;
};

inline  void OffensesDatabase::add(const string& car_number, const Violetion& new_violetion)
{
	MyNode* addNode = new MyNode(car_number, new_violetion);
	if (isEmpty())
	{
		root = addNode;
		return;
	}
	
	MyNode* tmp = root;
	while (true)
	{
		if (car_number == tmp->car_number)
		{
			tmp->violetion.push_back(new_violetion);
			break;
		}
		else if (car_number < tmp->car_number)
		{
			if (tmp->left == nullptr)
			{
				tmp->left = addNode;
				addNode->parent = tmp;
				break;
			}
			else
				tmp = tmp->left;
		}
		else if (car_number > tmp->car_number)
		{
			if (tmp->right == nullptr)
			{
				tmp->right = addNode;
				addNode->parent = tmp;
				break;
			}
			else
				tmp = tmp->right;
		}
	}
}

inline void OffensesDatabase::printAll() const
{
	printAll(root);
}

inline void OffensesDatabase::printSpecificCar(const string& car_number) const
{
	bool found = false;
	auto tmp = root;
	while (tmp != nullptr)
	{
		if (car_number == tmp->car_number)
		{
			print(tmp);
			found = true;
			break;
		}
		else if (car_number < tmp->car_number)
				tmp = tmp->left;
		else if(car_number > tmp->car_number)
			tmp = tmp->right;
	}
	if (!found)
	{
		cout << "Car with number " << car_number << " not found!\n";
	}
}

inline void OffensesDatabase::printRange(const string& from, const string& till, MyNode* node) const
{
	if (node != nullptr)
	{
		printRange(from, till, node->left);
		if (node->car_number >= from && node->car_number <= till)
			print(node);
		printRange(from, till, node->right);
	}
}

inline void OffensesDatabase::printRange(const string& from, const string& till)const
{
	MyNode* tmp = root;
	string tmp_till = till;
	tmp_till[0]++;
	printRange(from, tmp_till, tmp);
}

inline void OffensesDatabase::clear(MyNode* node)
{
	if (node != nullptr)
	{
		clear(node->left);
		clear(node->right);
		delete node;
	}
}

inline void OffensesDatabase::print(MyNode* node) const
{
	cout << "---------------------------------------------------------------\n";
	cout << "Number of car: \t\t ---=== " << node->car_number << " ===--- \n" << "Violations: \t\t\t" << node->violetion.size() << "\n";
	for (size_t i = 0; i < node->violetion.size(); i++)
	{
		cout << "---------------------------------------------------------------\n";
		node->violetion[i].printViolation();
		cout << "---------------------------------------------------------------\n";
	}
	cout << endl << endl;
}

inline void OffensesDatabase::printAll(MyNode* node) const
{
	if (node != nullptr)
	{
		printAll(node->left);
		print(node);
		printAll(node->right);
	}
}

inline void OffensesDatabase::clear()
{
	clear(root);
	root = nullptr;
}

inline OffensesDatabase::~OffensesDatabase()
{
	clear();
	root = nullptr;
}


