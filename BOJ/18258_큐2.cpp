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
	//비어있으면 true 아니면 0
	return (q.tail - q.head) == 0 ? true : false;
}

int Size(Queue& q)
{
	return (q.tail - q.head);
}

void Push(Queue& q, int x)
{
	//push X: 정수 X를 큐에 넣는 연산이다.
	//삽입 후 tail을 증가시킨다.
	q.v.push_back(x);
	q.tail += 1;
}

int Pop(Queue& q)
{
	//FIFO의 원칙으로 앞에 있는 숫자를 제거한다.
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