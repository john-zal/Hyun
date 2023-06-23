#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct deque
{
	vector<int> v;
	int center = 0;
	int head = 0;
	int tail = 0;
};

bool Empty(deque& deq)
{
	return deq.head == deq.tail ? true : false;
}

int Size(deque& deq)
{
	return deq.tail - deq.head;
}

void Push_front(deque& deq, int num)
{
	//��ĭ �ڷ� �а� ����
	deq.v[--deq.head] = num;
}
void Push_back(deque& deq, int num)
{
	//�����ϰ� �� ĭ �б�
	deq.v[deq.tail++] = num;
}

int Front(deque& deq)
{
	return Empty(deq) ? -1 : deq.v[deq.head];
}
int Back(deque& deq)
{
	return Empty(deq) ? -1 : deq.v[deq.tail-1];
}

int Pop_front(deque& deq)
{
	//���� �������� �ε��� �ű�
	return Empty(deq) ? -1 : deq.v[deq.head++];
}
int Pop_back(deque& deq)
{
	return Empty(deq) ? -1 : deq.v[--deq.tail];
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);

	int N = 0;
	cin >> N;

	string answer = "";

	//N�� ���� ����
	int size = (N * 2) + 1;
	deque deq;
	deq.v.resize(size);
	deq.center = N;
	deq.head = N;
	deq.tail = N;

	string s = "";
	for (int i = 0; i < N; i++)
	{	
		s = "";
		cin >> s;
		if (s == "push_front")
		{
			int num = 0;
			cin >> num;
			Push_front(deq, num);
			continue;
		}
		else if (s == "push_back")
		{
			int num = 0;
			cin >> num;
			Push_back(deq, num);
			continue;
		}
		else if (s == "pop_front")
			answer += to_string(Pop_front(deq));
		else if (s == "pop_back")
			answer += to_string(Pop_back(deq));
		else if (s == "size")
			answer += to_string(Size(deq));
		else if (s == "empty")
			answer += to_string(Empty(deq));
		else if (s == "front")
			answer += to_string(Front(deq));
		else if (s == "back")
			answer += to_string(Back(deq));

		answer += '\n';
	}

	cout << answer << '\n';
	return 0;
}