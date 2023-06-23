#include <iostream>
#include <deque>
using namespace std;

int cnt = 0;

void Remove(deque<int>& deq)
{
	//1. 뽑아내기 -> 맨 앞의 원소를 제거
	deq.pop_front();
}

void FrontToBack(deque<int>& deq)
{
	//2. 시계 이동 -> 맨 앞의 원소를 맨 뒤로 이동
	deq.push_back(deq.front());
	Remove(deq);
	cnt += 1;
}

void BackToFront(deque<int>& deq)
{
	//3. 반시계 이동2 -> 맨 뒤의 원소를 맨 앞으로 이동
	deq.push_front(deq.back());
	deq.pop_back();
	cnt += 1;
}

int CheckDirLength(deque<int> deq, int num, bool& dir)
{
	int size = 0;
	
	for (int i = 0; i < deq.size(); i++)
	{
		if (deq[i] == num)
		{
			size = i;
			break;
		}	
	}

	int size2 = 0;
	for (int i = deq.size() - 1; i > 0; i--)
	{
		if (deq[i] == num)
		{
			size2 = deq.size() - i;
			break;
		}
	}

	if (size > size2)
	{
		dir = true; // 왼쪽이 더 적은 횟수
		size = size2;
	}

	return size;
}

int main()
{
	int queueSize = 0; //큐의 크기
	int extract = 0; //추출할 숫자

	deque<int> deq;
	
	cin >> queueSize;

	for (int i = 1; i <= queueSize; i++)
		deq.push_back(i);

	cin >> extract;
	for (int i = 0; i < extract; i++)
	{
		int num = 0;
		cin >> num;

		if (!(deq[0] == num))
		{
			bool dir = false;
			int size = CheckDirLength(deq, num, dir);
			
			while (size > 0)
			{
				dir ? BackToFront(deq) : FrontToBack(deq);
				size--;
			}
			Remove(deq);
		}
		else
			Remove(deq);

	}

	cout << cnt << endl;
	return 0;
}