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
	if (num == M) //모든 칸이 찼으면 출력
	{
		//M개를 모두 선택한 후
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

			//cout << "재귀 전 출력 : \n";
			//print();

			Recursive(num + 1); //재귀
			isUsed[i] = false;
			//arr[num] = -1; //확인용

			//cout << "재귀 후 출력 : \n";
			//print();
		}
	}
}

int main()
{
	cin >> N >> M;
	Recursive(0);
}