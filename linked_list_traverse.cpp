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

// struct LinkedList
// {
// 	Node* head;
// 	LinkedList ()
// 	{
// 		head = NULL;
// 	}

// 	void push(int data)
// 	{
// 		Node* temp = new Node(data);
// 		temp->next = head;
// 		head = temp;
// 	} 

// 	void print()
// 	{
// 		cout << "List is as follows\n";
// 		int count = 0;
// 		Node* temp = head;
// 		while(temp!=NULL)
// 		{
// 			cout << temp->data << "\n";
// 			temp = temp->next;
// 		}
// 	}
// };

void print(Node* head)
{
	cout << "List is as follows\n";
	int count = 0;
	Node* temp = head;
	while(temp!=NULL)
	{
		cout << temp->data << "\n";
		temp = temp->next;
	}
}

int main(int argc, char const *argv[])
{
	// LinkedList ll;
	// ll.push(10);
	// ll.push(20);
	// ll.push(30);
	// ll.push(40);
	// ll.print();
	
	Node* first = NULL;
	Node* second = NULL;
	Node* third = NULL;
	Node* fourth = NULL;

	first = new Node(10);
	second = new Node(20);
	third = new Node(30);
	fourth = new Node(40);

	first->next = second;
	second->next = third;
	third->next = fourth;

	print(first);
	
	return 0;
}