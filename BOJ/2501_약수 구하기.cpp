#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	
	int answer = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!(N % i))
			K--;

		if (!K) 
		{
			answer = i;
			break;
		}
	}

	cout << answer;
}