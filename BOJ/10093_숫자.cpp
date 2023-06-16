#include<iostream>
using namespace std;

int main()
{
	long long A;
	long long B;

	cin >> A;
	cin >> B;

	long long C = min(A, B);
	long long D = max(A, B);

	if (C == D)
		cout << "0" << endl;
	else
		cout<< D - C - 1 << '\n';

	for (long long i = 1; i < D-C; i++)
		cout << C + i << " ";

	return 0;
}