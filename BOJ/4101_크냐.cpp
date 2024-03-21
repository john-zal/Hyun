#include <iostream>

using namespace std;

int main()
{
	int a = -1, b = -1;
	while (true)
	{
		cin >> a >> b;

		if (!a && !b)
			break;
		cout << (a > b ? "Yes" : "No") << '\n';
	}
}