#include <iostream>

using namespace std;

int N, M; //nCr
int arr[9];

void Comb(int dep, int start) //������� ���� ���� ����, ������ ������ ���� �ε���
{
	if (dep == M)
	{
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++)
	{
			arr[dep] = i;
			//�ߺ����� ���� �Ƿ��� ���� ��尡 ���� ��� ���� ũ�� �ȵȴ�.
			Comb(dep + 1, i +1); // ���� �ε����� ���� �÷��ش�.
	}
}

int main()
{
	cin >> N >> M;
	Comb(0, 1);
}