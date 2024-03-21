#include <iostream>

using namespace std;

int main()
{
	//평균은 무조건 올림이므로  24에서 1을 빼준 값을 38과 곱해주고 이 식에서 1을 더해준다.
	//(23) * 38 = x;
	int x, y;
	cin >> x >> y;
	cout << x * (y - 1) + 1;
}