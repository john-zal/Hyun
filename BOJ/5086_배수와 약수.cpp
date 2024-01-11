#include <iostream>

using namespace std;

int main()
{
	int A = -1;
	int B = -1;

	while (!((A==0) && (B==0)))
	{
		cin >> A >> B;

		if (A > 0 && B > 0)
		{
			if (A==B || A < B) //약수
				B % A ? cout << "neither" << '\n' : cout << "factor" << '\n';
			else if (A > B) // 배수
				A % B ? cout << "neither" << '\n' : cout << "multiple" << '\n';
		}
		else
			break;

	}
}