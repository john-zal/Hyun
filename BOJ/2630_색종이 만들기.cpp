#include <iostream>
#include <algorithm>

using namespace std;

int arr[128][128];
int answer[2]; //[0 white] [1 blue]

bool CheckRect(int n, int UD, int LR)
{
	//ù ��ǥ�� �ٸ� ���ڰ� ���� �� (���簢�� �ƴ� ��) false ��ȯ
	for (int i = UD; i < UD + n; i++)
		for (int j = LR; j < LR + n; j++)
			if (arr[i][j] != arr[UD][LR])
				return false;
			
	return true;
}

void ReCUTsive(int n, int UD, int LR)
{
	//Ż������: size * size �� ���ڰ� ��� ���� ��
	//�ּ� 1x1 Ÿ���� �Ǹ� ������ Ż��
	if (CheckRect(n, UD, LR))
	{
		answer[arr[UD][LR]]++;
		return;
	}

	//4�������� ���
	ReCUTsive(n / 2, UD + (0 * (n / 2)), LR + (0 * (n / 2)));
	ReCUTsive(n / 2, UD + (0 * (n / 2)), LR + (1 * (n / 2)));
	ReCUTsive(n / 2, UD + (1 * (n / 2)), LR + (0 * (n / 2)));
	ReCUTsive(n / 2, UD + (1 * (n / 2)), LR + (1 * (n / 2)));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	ReCUTsive(N, 0, 0);

	cout << answer[0] << '\n' << answer[1] << '\n';
	return 0;
}