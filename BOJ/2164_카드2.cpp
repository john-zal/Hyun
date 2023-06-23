#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N = 0;
	queue<int> Q;
	cin >> N;
	for (int i = 0; i < N; i++)
		Q.push(i + 1);

	while (Q.size() > 1)
	{
		//ī�� ���ֱ�
		Q.pop();

		//ī�� �ڿ� ����
		int num = Q.front();
		Q.push(num);
		Q.pop();
	}

	cout <<Q.front() << '\n';

	return 0;
}