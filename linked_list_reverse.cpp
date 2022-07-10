#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

struct LinkedList
{
	Node* head;
	LinkedList() {head = NULL;}
	void reverse()
	{
		Node* cur = head;
		Node *prev = NULL, *next = NULL; 
		while(cur != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}
		head = prev;
	}
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	void push (int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;

	}
};

int main(int argc, char const *argv[])
{
	LinkedList ll;
	ll.push(20);
	ll.push(50);
	ll.push(1);

	cout << "\nInput LinkedList is: \n";
	ll.print();

	ll.reverse();

	cout << "\nReverse LinkedList is: \n";
	ll.print();

	return 0;
}