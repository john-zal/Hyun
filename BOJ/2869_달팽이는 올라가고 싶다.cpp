#include <iostream>

using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	int answer = 1;
	V -= A;

	answer += V / (A - B);
	if (V % (A - B))
		answer += 1;

	cout << answer;
}