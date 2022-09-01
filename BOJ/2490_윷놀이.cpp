#include <bits/stdc++.h>
using namespace std;
char result(int cnt) 
{
	switch (cnt)
	{
	case 3:
		//도
		return 'A';
		break;

	case 2:
		//개
		return 'B';
		break;

	case 1:
		//걸
		return 'C';
		break;

	case 0 :
		//윷 0 0 0 0
		return 'D';
		break;

	case 4:
		//모
		return 'E';
		break;
	}
}
int main() {
	int cnt = 0;
	int arr[3][4] = { 0 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cnt += arr[i][j];
		}
		cout << result(cnt) << "\n";
		//cnt 초기화
		cnt = 0;
	}
	return 0;
}