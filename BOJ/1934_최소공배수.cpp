#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	//a는 더 큰 수, b는 더 작은 수로 배치했다.
	//a%b를 했을때 결과가 0이 나온다면 그 수가 최소공배수이다.
	/*
	ex) 6, 10 
	10 % 6  -> 나머지 했던 6을 left로 보내고 나머지로 나온 4를 right에 둔다.
	6 % 4	-> 나머지 했던 4을 left로 보내고 나머지로 나온 2를 right에 둔다.
	4 % 2	-> 나머지 했던 2를 left로 보내고 나머지로 나온 0를 right에 둔다.
	-> b(right)가 0이 되었으므로 현재 left인 2를 반환한다.

	(원본a * 원본b) / 최대공약수 = 최소공배수이다.
	*/
	return b ? gcd(b, a % b) : a;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int a, b ,answer;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		answer = (a * b) / gcd(max(a, b), min(a, b));
		cout << answer << '\n';	
	}
}