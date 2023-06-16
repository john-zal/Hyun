#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<string> vec;
	
	
	for (int i = 1; i <= N; i++)
	{
		string s = "";
		for (int j = 0; j < N - i; j++)
			s += " ";
			
		for (int j = 0; j < (i *2)-1; j++)
			s += "*";
		
		cout << s << '\n';
		vec.push_back(s);
	}

	for (int i = N - 2; i >= 0; i--)
		cout << vec[i] << '\n';


}