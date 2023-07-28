#include <iostream>
#include <math.h>
using namespace std;

/*
1. 가장 아래에 있는 원판을 맨 끝으로 옮기기 위해서
나머지 원판들이 가운데 있어야 한다.

2. 가장 아래에 있는 원판을 맨 끝으로 옮긴다.

3. 가운데 있는 나머지 원판들을 맨 끝으로 옮긴다.

*/
//하노이탑 이동 최소 횟수는 2^n-1

/*
시작 - 경유
시작 - 도착
경유 - 도착

패턴으로 재귀
*/
//숫자, 시작, 경유지, 도착지
void Hanoi(int num, char fromA, char midB, char toC)
{
	if (num == 1)
	{
		//A를 C로 옮긴다.
		cout << fromA << " " << toC << '\n';
		return;
	}

	//n-1개 ~ 1개를 A에서 (C를 거쳐) B로 옮긴다. 
	Hanoi(num - 1, fromA, toC, midB);

	cout << fromA << " " << toC << '\n';

	//n-1개 ~ 1개를 A로보터 옮긴 B에서 (A를 거쳐) C로 옮긴다.
	Hanoi(num - 1, midB, fromA, toC);
}

int main()
{
	int N;
	cin >> N;
	cout << ((int)pow(2, N)) - 1 << '\n';
	Hanoi(N, '1', '2', '3');
}