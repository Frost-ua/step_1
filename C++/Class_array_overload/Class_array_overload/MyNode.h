#pragma once
#include<string>
#include"Violetion.h"
#include<vector>

using std::string;
using std::vector;

class MyNode
{
public:
	MyNode(const string& car_number,const Violetion &new_violetion, MyNode* parent, MyNode* left, MyNode* right);
	string car_number = "AA 0000 AA";
	vector<Violetion> violetion;
	MyNode* left = nullptr, * right = nullptr, * parent = nullptr;
	void setCarNumber(const string& car_number);
};

inline MyNode::MyNode(const string& car_number,const Violetion &new_violetion, MyNode* parent = nullptr, MyNode* left = nullptr, MyNode* right = nullptr)
{
	setCarNumber(car_number);
	this->violetion.push_back(new_violetion);
	this->parent = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}

inline void MyNode::setCarNumber(const string& car_number)
{
	!car_number.empty() ? this->car_number = car_number : "AA0000AA";
}

