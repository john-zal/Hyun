#include <iostream>

using namespace std;

int isCalc[15][15] = { 0 };

int SuperSum(int k, int n)
{
	//base case
	if (k == 0)
	{
		isCalc[k][n] = n;
		return n;
	}
	if (isCalc[k][n])
		return isCalc[k][n];

	for (int i = 1; i <= n; i++)
	{
		isCalc[k][n] += SuperSum(k - 1, i);
	}
	return isCalc[k][n];
}

int main()
{
	int K, N;

	while (scanf_s("%d %d", &K, &N) != EOF)
	{
		//cin >> K >> N;
		SuperSum(K, N);
		cout << isCalc[K][N] << "\n";
	}
		
}