#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N, B;
	cin >> N >> B;
	
	string answer = "";
	//n진수 * (B진법^)
	int div = N;
	while (div != 0)
	{
		int value = div % B;
		if (value > 9 && value < 36)
		{
			char c = (char)(55 + value);
			answer += c;
		}
		else
			answer += to_string(value);

		div /= B;
	}
	for (int i = answer.size()-1; i >= 0; i--)
		cout << answer[i];
}