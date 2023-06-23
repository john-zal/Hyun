#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int answer = 0;
	int N = 0;
	cin >> N;
	
	while (N--)
	{
		stack<char> stack;
		string s = "";
		
		cin >> s;

		//Ȧ���� ���۴ܾ�
		if (s.size() % 2 == 1)
			continue;

		for (char c : s)
		{
			if (stack.size() > 0)
			{
				//������ üũ�ϱ�
				if (stack.top() == c)
					stack.pop();
				else
					stack.push(c);
			}
			else
				stack.push(c);
		}

		if (stack.empty())
			answer += 1;
	}
	cout << answer << endl;
	return 0;
}