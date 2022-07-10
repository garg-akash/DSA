#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int checkPairwise(const stack<int>& s)
{
	int isPairwise = 1;
	stack<int> temp(s);
	queue<int> q;
	int count = 0;
	while(!temp.empty())
	{
		q.push(temp.top());
		temp.pop();
		count++;
	}
	stack<int> sNew;
	while(!q.empty())
	{
		sNew.push(q.front()); // reversing the original stack
		q.pop();
	}
	int run = count/2;
	cout << "count: " << count << "run: " << run << "\n";
	if(count%2 == 1)
		sNew.pop();
	for (int i = 0; i < run; ++i)
	{
		int x = sNew.top();
		sNew.pop();
		int y = sNew.top();
		cout << "run " << i << ": x,y : " << x << " " << y << "\n"; 
		sNew.pop();
		if(abs(x-y) != 1)
		{
			isPairwise = 0;
			return isPairwise;
		}
	}
	return isPairwise;
}

int main(int argc, char const *argv[])
{
	stack<int> s;

	s.push(20);
	s.push(6);
	s.push(5);
	s.push(10);
	s.push(11);
	s.push(-3);
	s.push(-2);
	s.push(5);
	s.push(4);

	int status = checkPairwise(s);
	cout << "status: " << status << "\n";

	return 0;
}