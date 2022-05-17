// L1F20BSCS0539
// MUGHEEZ ASIF
// TASK 2
// INFIX TO PREFIX
#include <iostream>
#include "LinkStack.h"
using namespace std;

int checkop(char a);
template <class T>
void reverse(Stack<T>& obj);
char* infix_to_postfix(const char* temp);
int char_convert(char a);
char* infix_to_prefix(char* temp);
float evaluation(char* temp);
int main()
{
	
	char* temp = new char[100];
	cout << "This is the code to convert infix into prefix!" << endl;
	cout << "************************************************" << endl;
	cout << "Please Enter the expression only operators, oprends, or spaces!" << endl;
	cout << "Enter the expression : ";
	cin.getline(temp, 100);
	cout << "The prefix expression is : ";
	temp = infix_to_prefix(temp);
	cout << temp << endl;
	cout << "The evaluation result is : ";
	cout << evaluation(temp) << endl;

	return 0;
}


char* infix_to_postfix(const char* temp)
{
	Stack<char> obj1;
	Stack<char> obj2;
	int size = strlen(temp);
	for (int i = 0; i < size; i++)
	{
		if (temp[i] != ' ')
		{
			bool flag = true;
			if (temp[i] > 47 && temp[i] < 58)
				obj1.push(temp[i]);
			else
			{

				char pk = obj2.peek();
				if (temp[i] == '(')
				{
					obj2.push(temp[i]);
					flag = false;
				}
				else if (temp[i] == ')')
				{

					while (obj2.peek() != '(')
					{
						obj1.push(obj2.pop());
					}
					obj2.pop();
					flag = true;
				}
				else if (checkop(pk) >= checkop(temp[i]) && flag)
				{
					while (1)
					{
						obj1.push(obj2.pop());
						pk = obj2.peek();
						if (checkop(pk) < checkop(temp[i]))
							break;

					}
					obj2.push(temp[i]);
				}
				else
					obj2.push(temp[i]);
			}
		}
	}
	for (int i = 0; i < obj2.length(); i++)
		obj1.push(obj2.pop());

	reverse<char>(obj1);
	char* arr = new char[100];
	int i = 0;
	for (i; !obj1.isempty(); i++)
		arr[i] = obj1.pop();
	arr[i] = '\0';
	return arr;
}

template <class T>
void reverse(Stack<T> & obj)
{
	Stack<char> temp;
	while (!obj.isempty())
		temp.push(obj.pop());
	obj = temp;
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

int char_convert(char a)
{
	int temp = a -= 48;
	return temp;
}

char* infix_to_prefix(char* temp)
{
	Stack<char> obj;
	int size = strlen(temp);
	for (int i = 0; i < size; i++)
		obj.push(temp[i]);
	for (int i = 0; i < size; i++)
	{
		if (obj.peek() == '(')
		{
			temp[i] = ')';
			obj.pop();
		}
		else if (obj.peek() == ')')
		{
			temp[i] = '(';
			obj.pop();
		}
		else
			temp[i] = obj.pop();
	}
	temp = infix_to_postfix(temp);
	size = strlen(temp);
	for (int i = 0; i < size; i++)
		obj.push(temp[i]);
	for (int i = 0; i < size; i++)
		temp[i] = obj.pop();
	return temp;
}

float evaluation(char* temp)
{
	Stack<float> result;
	int size = strlen(temp);
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