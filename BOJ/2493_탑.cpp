#include <iostream>
#include <stack>

using namespace std;
int main()
{
	int N = 0;

	cin >> N;

	//높이, 인덱스
	stack<pair<int, int>> stack;

	for (int i = 0; i < N; i++)
	{
		int height = 0;
		cin >> height;
		
		if((N > 0) && (i == 0))
			stack.push({ height, i + 1 });


		//더 낮은 애들은 사용하지 않는다.

	}

	return 0;
}