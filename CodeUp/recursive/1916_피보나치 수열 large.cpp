#include <iostream>

using namespace std;

int g_Data[201] = {};

int Fibo(int n)
{
	if (n == 1 || n == 2)
	{
		g_Data[n] = 1;
		return g_Data[n];
	}
		
	if (g_Data[n])
		return g_Data[n];

	g_Data[n] = (Fibo(n - 1) + Fibo(n - 2)) % 10009;
	return g_Data[n];
}

int main()
{
	int N;
	cin >> N;
	cout << Fibo(N) << '\n';
}