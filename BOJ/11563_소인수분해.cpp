#include <iostream>

using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	if (N == 1)
		return 0;

	int i = 2;
	while (i <= N)
	{
		//if������ while������ �ٲ���� �����
		while (!(N % i))
		{
			N /= i;
			cout << i << '\n';
		}
		i++;
	}

}