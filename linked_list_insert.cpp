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

void insert(int position, int data, Node** head)
{
	if(position == 1)
	{
		Node* temp = new Node(data);
		temp->next = *head;
		*head = temp;

	}
	else
	{
		int count = 0;
		Node* iter = NULL;
		Node* prev = NULL;
		iter = *head;
		while(count < position-1)
		{
			prev = iter;
			iter = iter->next;
			count++;
		}
		Node* temp = new Node(data);
		prev->next = temp;
		temp->next = iter;
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

	insert(3, 0, &first);

	print(first);
	
	return 0;
}