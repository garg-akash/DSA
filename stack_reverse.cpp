#include <iostream>
#include <stack>

using namespace std;

stack<int> st;

void insert(int x)
{
	st.push(x);
}

void reverse()
{
	if(st.size() > 0)
	{
		int x = st.top();
		st.pop();
		reverse();

		insert(x);
	}
}

int main(int argc, char const *argv[])
{
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	reverse();
	cout << "Reversed\n";
	while(st.size())
	{
		cout << st.top() << "\n";
		st.pop();
	}
	return 0;
}