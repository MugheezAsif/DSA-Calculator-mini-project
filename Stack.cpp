#include "Stack.h"
template <class T>
Stack<T>::Stack()
{
	arr = new T[100];
	maxSize = 100;
	size = 0;
}
template <class T>
Stack<T>::Stack(Stack& obj)
{
	if (arr != nullptr)
		delete[]arr;
	arr = new T[obj.maxSize];
	for (int i = 0; i < obj.size; i++)
		arr[i] = obj.arr[i];
	size = obj.size;
	maxSize = obj.maxSize;
}
template <class T>
Stack<T>& Stack<T>::operator=(Stack & obj)
{
	if (arr != nullptr)
		delete[]arr;
	arr = new T[obj.maxSize];
	for (int i = 0; i < obj.size; i++)
		arr[i] = obj.arr[i];
	size = obj.size;
	maxSize = obj.maxSize;
	return *this;
}
template <class T>
Stack<T>::~Stack()
{
	delete[] arr;
	arr = nullptr;
}
template <class T>
void Stack<T>::push(T a)
{
	arr[size++] = a;
}
template <class T>
T Stack<T>::pop()
{
	T temp = arr[size - 1];
	size--;
	return temp;
}
template <class T>
void Stack<T>::display()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
template <class T>
T Stack<T>::peek()
{
	return arr[size - 1];
}
template <class T>
int Stack<T>::length()
{
	return size + 1;
}
template <class T>
bool Stack<T>::isempty()
{
	if (size == 0)
		return 1;
	return 0;
}
template <class T>
bool Stack<T>::isfull()
{
	if (maxSize == size)
		return 1;
	return 0;
}