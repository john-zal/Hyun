#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int N;
	cin >> N >> s;
	
	N = 0;
	for (char c : s)
		N += c - '0';

	cout << N << '\n';
	return 0;
}