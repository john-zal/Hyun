#include <iostream>

using namespace std;

int main()
{
	//총 금액, 물건 종류, 물건 가격, 물건 개수
	int X, N, a, b;
	cin >> X >> N;

	int sum = 0;

	while (N--)
	{
		cin >> a >> b;
		sum += a * b;
	}

	cout << (sum == X ? "Yes\n" : "No\n");

	return 0;
}