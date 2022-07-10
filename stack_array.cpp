#include<iostream>

using namespace std;

#define MAXSIZE 10

// struct StackArray
// {
// 	int top;
// 	int capacity;
// 	int* array
// };

class StackArray
{
	int top;
	public:
	StackArray() {top = -1; }
	int array[MAXSIZE];
	void push(int x)
	{
		if(top > (MAXSIZE-1))
			cout << "Stack overflow\n";
		else
		{
			cout << "Pushed " << x << "\n";
			array[++top] = x;
		}
	}

	void pop()
	{
		if(top < 0)
			cout << "Stack underflow\n";
		else
		{
			cout << "Poped " << array[top--] << "\n";
		}
	}

	void print()
	{
		if(top < 0)
			cout << "Stack is empty\n";
		else
		{
			cout << "Stack is as follows\n";
			for (int i = 0; i <= top; ++i)
			{
				cout << array[i] << "\n";
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	StackArray sa;
	sa.push(10);
	sa.push(20);
	sa.push(30);
	sa.print();
	sa.pop();
	sa.print();
	return 0;
}