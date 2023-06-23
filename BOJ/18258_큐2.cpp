#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Queue 
{
	vector<int> v;
	int head = 0;
	int tail = 0;
};

bool Empty(Queue& q)
{
	//��������� true �ƴϸ� 0
	return (q.tail - q.head) == 0 ? true : false;
}

int Size(Queue& q)
{
	return (q.tail - q.head);
}

void Push(Queue& q, int x)
{
	//push X: ���� X�� ť�� �ִ� �����̴�.
	//���� �� tail�� ������Ų��.
	q.v.push_back(x);
	q.tail += 1;
}

int Pop(Queue& q)
{
	//FIFO�� ��Ģ���� �տ� �ִ� ���ڸ� �����Ѵ�.
	return Empty(q) ? -1 : q.v[q.head++];
}

int Front(Queue& q)
{
	return Empty(q) ? -1 : q.v[q.head];
}

int Back(Queue& q)
{
	return (!(Empty(q)) && q.tail > 0) ? q.v[q.tail - 1] : -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Queue q;
	string answer = "";
	int N = 0;
	cin >> N;
	string s = "";
	for (int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> s;
		if (s == "push")
		{
			cin >> num;
			Push(q, num);
			continue;
		}
		else if (s == "pop")
			answer += to_string(Pop(q));
		else if (s == "size")
			answer += to_string(Size(q));
		else if (s == "empty")
			answer += to_string(Empty(q));
		else if (s == "front")
			answer += to_string(Front(q));
		else if (s == "back")
			answer += to_string(Back(q));

		answer += '\n';
	}

	cout << answer << '\n';
	
	return 0;
}