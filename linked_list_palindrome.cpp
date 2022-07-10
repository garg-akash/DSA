#define MAXSIZE 10

#include <iostream>
#include <cstring>
#include <stack>
using namespace std;


class LinkedList
{
public:
	int data;
	LinkedList* next;
	LinkedList(int x) {data = x; next = NULL;}
};

// class StackArray
// {
// public:
// 	int top;
// 	int array[MAXSIZE];
// 	StackArray() {top = -1;}
// 	void push(int x)
// 	{
// 		if(top > MAXSIZE-1)
// 			cout << "Stack overflow;\n"
// 		else
// 		{
// 			array[++top] = x;
// 			cout << "Pushed " << x << " \n";
// 		}
// 	}
// };

int checkPalindrome(LinkedList* head)
{
	stack<int> st;
	LinkedList* temp = head;
	while(temp!=NULL)
	{
		st.push(temp->data);
		temp = temp->next;
	}

	while(head!=NULL)
	{
		if(head->data != st.top())
			return false;
		st.pop();
		head = head->next;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	// char s[4] = {'a','b','b', 'a'};
	LinkedList* first = new LinkedList(1);
	LinkedList* second = new LinkedList(2);
	LinkedList* third = new LinkedList(2);
	LinkedList* fourth = new LinkedList(2);

	first->next = second;
	second->next = third;
	third->next = fourth;
	int status = checkPalindrome(first);
	if(status)
	{
		cout << "Palindrome\n";
	}
	else
	{
		cout << "Not a palindrome\n";
		return 1;	
	}
	return 0;
}