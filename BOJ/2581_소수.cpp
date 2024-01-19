#include <iostream>

using namespace std;
const int g_max = 10001;
bool arr[g_max];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int M, N;
	int primeSum = 0;
	int primeMin = -1;

	cin >> M >> N;

	//�����佺�׳׽�
	arr[0] = true; //0�� �Ҽ��� �ƴϴ�.
	arr[1] = true; //1�� �Ҽ��� �ƴϴ�.
	arr[2] = false; //2�� �Ҽ��̴�.
	for (int i = 2; i < g_max; i++)
	{
		if (arr[i])
			continue;

		int cnt = 2;
		while (i * cnt <= g_max)
		{
			arr[i * cnt] = true;
			cnt++;
		}
	}

	for (int i = M; i <= N; i++)
	{
		arr[i] ? primeSum : primeSum += i;

		if (primeSum > 0 && primeMin == -1)
			primeMin = i;
	}

	if (primeSum)
		cout << primeSum << '\n' << primeMin;
	else
		cout << -1;
}