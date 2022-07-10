#include <iostream>
#include <queue>

using namespace std;

void interleaving(queue<int>& q)
{
	queue<int> temp(q);
	queue<int> first, second, dest;
	int count = 1;
	while(!q.empty())
	{
		q.pop();
		count++;
	}
	int i = count;
	while(i--)
	{
		if( i > count/2)
		{
			first.push(temp.front());
			temp.pop();
		}
		else
		{
			second.push(temp.front());
			temp.pop();
		}
	}
	while(!first.empty())
	{
		dest.push(first.front());
		dest.push(second.front());
		first.pop();
		second.pop();
	}

	cout << "Dest queue:\n";
	while(!dest.empty())
	{
		cout << dest.front() << "\n";
		dest.pop();
	}
}

int main(int argc, char const *argv[])
{
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	q.push(20);
	interleaving(q);
	return 0;
}