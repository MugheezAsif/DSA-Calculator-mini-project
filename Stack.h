#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack
{
	T* arr;
	int size;
	int maxSize;
public:
	Stack();
	Stack(Stack& obj);
	Stack& operator=(Stack& obj);
	void push(T a);
	T pop();
	void display();
	T peek();
	int length();
	bool isempty();
	bool isfull();
	~Stack();
};
