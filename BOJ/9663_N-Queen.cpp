#include <iostream>

using namespace std;
int cnt = 0;
int N;

int isUsed[15];
int isUsed2[30];
int isUsed3[30];


void Recursive(int num)
{
	if (num == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		//���� ��ġ�ų� �밢������ ��ġ�� �н�
		if (isUsed[i] || isUsed2[i + num] || isUsed3[num - i + N - 1]) 
			continue;
		isUsed[i] = true; //���� ��ġ
		isUsed2[i + num] = true; // x + y  ���� ��� �밢��
		isUsed3[num - i + N - 1] = true; // x-y + N ���� �ϴ� �밢��
		
		Recursive(num + 1);

		isUsed[i] = false;
		isUsed2[i + num] = false;
		isUsed3[num - i + N - 1] = false;
	}
}

int main()
{
	cin >> N;
	Recursive(0);
	cout << cnt;
}