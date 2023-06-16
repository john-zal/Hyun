#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> stack;

	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num = -1;
		cin >> num;
		if (!(stack.empty()) && num == 0)
			stack.pop();
		else
			stack.push(num);
	}

	int sum = 0;
	while(!(stack.empty()))
	{
		sum += stack.top();
		stack.pop();
	}
	cout << sum << '\n';
	return 0;
}