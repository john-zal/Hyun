#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool isUsed[10];

void print()
{
	for (int i = 1; i <= N; i++)
		isUsed[i] ? cout << "T" : cout << "F";

	cout << endl;

	for (int i = 0; i < M; i++)
		cout << arr[i] << ' ';

	cout << endl;
}

void Recursive(int num)
{
	if (num == M) //��� ĭ�� á���� ���
	{
		//M���� ��� ������ ��
		for (int i = 0; i < M; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) //1~4
	{
		if (!isUsed[i])
		{
			arr[num] = i;
			isUsed[i] = true;

			//cout << "��� �� ��� : \n";
			//print();

			Recursive(num + 1); //���
			isUsed[i] = false;
			//arr[num] = -1; //Ȯ�ο�

			//cout << "��� �� ��� : \n";
			//print();
		}
	}
}

int main()
{
	cin >> N >> M;
	Recursive(0);
}