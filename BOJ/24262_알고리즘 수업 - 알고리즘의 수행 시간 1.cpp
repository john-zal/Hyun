#include <iostream>

using namespace std;

int main()
{
	int N1, N2, N3, num;
	cin >> N1 >> N2 >> N3 >> num;

	bool check = true;

	if (N3 - N1 < 0)
		check = false;

	for (int i = num; i <= 100; i++)
	{
		if (!check)
			break;

		int sumA = N1 * num + N2;
		int sumB = N3 * num;

		if (!(sumA <= sumB))
			check = false;
	}
	cout << check;
}