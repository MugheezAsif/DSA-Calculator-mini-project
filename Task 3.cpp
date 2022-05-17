// L1F20BSCS0539
// MUGHEEZ ASIF
// TASK 3
// POSTFIX TO PREFIX AND EVALUATION


#include <iostream>
#include <string>
#include "LinkStack.h"
using namespace std;

int checkop(char a);
template <class T>
void reverse(Stack<T>& obj);
int char_convert(char a);
string postfix_to_prefix(string arr);
float evaluation(string temp);


int main()
{
	
	string arr;
	cout << "This is the code to convert postfix into prefix!" << endl;
	cout << "************************************************" << endl;
	cout << "Please Enter the expression only operators, oprends, or spaces!" << endl;
	cout << "Enter postfix expression : ";
	cin >> arr;
	cout << "The prefix expression is : ";
	cout << postfix_to_prefix(arr) << endl;
	cout << "The evaluation result is : ";
	cout << evaluation(postfix_to_prefix(arr)) << endl;
	
	return 0;
}
int checkop(char a)
{
	if (a == '/')
		return 4;
	else if (a == '*')
		return 4;
	else if (a == '+')
		return 2;
	else if (a == '-')
		return 2;
	else
		return 0;
}
template <class T>
void reverse(Stack<T> & obj)
{
	Stack<T> temp;
	while (!obj.isempty())
		temp.push(obj.pop());
	obj = temp;
}
int char_convert(char a)
{
	int temp = a -= 48;
	return temp;
}
string postfix_to_prefix(string arr)
{
	Stack<string> obj;
	int size = arr.length();
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 47 && arr[i] < 58)
		{
			string a = "";
			a += arr[i];
			obj.push(a);
		}
		else if (checkop(arr[i]))
		{

			string temp = arr[i] + obj.pop() + obj.pop();
			obj.push(temp);
		}
	}

	reverse(obj);
	string prefix;
	for (int i = 0; i < obj.length(); i++)
	{
		prefix += obj.pop();
	}
	return prefix;
}

float evaluation(string temp)
{
	Stack<float> result;
	int size = temp.length();
	for (int i = size - 1; i >= 0; i--)
	{
		if (temp[i] > 47 && temp[i] < 58)
		{
			result.push(char_convert(temp[i]));
		}
		else if (checkop(temp[i]))
		{
			if (temp[i] == '+')
				result.push(result.pop() + result.pop());
			else if (temp[i] == '-')
			{
				int a = result.pop();
				result.push(result.pop() - a);
			}
			else if (temp[i] == '*')
				result.push(result.pop() * result.pop());
			else if (temp[i] == '/')
			{
				int a = result.pop();
				result.push(result.pop() / a);
			}
		}

	}
	return result.pop();
}