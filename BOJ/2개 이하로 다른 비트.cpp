#include <iostream>

using namespace std;

int main()
{
	int N = 5;
	int num;
	int answer = 0;
	while (N--)
	{
		cin >> num;
		num < 40 ? num = 40 : num;
		answer += num;
	}
	cout << answer / 5;
}