#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	stack<pair<int, int>> stack; //넘버, 인덱스
	stack.push({ 100000001, 0 });
	cin >> N;
	int num;

	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		//새 탑이 기존 탑보다 클때 기존 탑을 없애버린다.
		while (stack.top().first < num)
			stack.pop();

		cout << stack.top().second << " ";
		stack.push({ num,i });
	}
}