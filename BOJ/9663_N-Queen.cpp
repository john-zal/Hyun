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
		//행이 겹치거나 대각선에서 겹치면 패스
		if (isUsed[i] || isUsed2[i + num] || isUsed3[num - i + N - 1]) 
			continue;
		isUsed[i] = true; //행의 배치
		isUsed2[i + num] = true; // x + y  우측 상단 대각선
		isUsed3[num - i + N - 1] = true; // x-y + N 우측 하단 대각선
		
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