#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	string answer = "";

	while (N--)
	{
		stack<char> stack;
		string s = "";
		cin >> s;
		if (s.size() % 2 == 1)
		{
			answer += "NO\n";
			continue;
		}
		
		for (char c : s)
		{
			if (!(stack.empty()))
			{
				if (stack.top() != c)
					stack.pop();
				else
					stack.push(c);
			}
			else
			{
				if (c == ')')
				{
					stack.push('F'); // Fail
					break;
				}		
				stack.push(c);
			}				
		}
		if (stack.empty())
			answer += "YES\n";
		else
			answer += "NO\n";
	}

	cout << answer << endl;
	return 0;
}