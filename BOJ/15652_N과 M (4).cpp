#include <iostream>

using namespace std;

int N, M;
int arr[9];

void Recursive(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++)
	{
		arr[cnt] = i;
		
		//���� ���� ���, �񳻸�����(�� ��庸�� ū ���� x)
		Recursive(i, cnt + 1);
	}
}

int main()
{
	cin >> N >> M;
	Recursive(1, 0);
}