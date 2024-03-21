#include <iostream>
#include <string>
#include <vector>
#define INT_MAX 2147483647

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer;
	answer.push_back(0);
	answer.push_back(INT_MAX);

	for (int i = 0; i < sequence.size(); i++)
	{
		if (sequence[i] > k)
			break;

		int sum = 0;
		for (int j = i; j < sequence.size(); j++)
		{
			sum += sequence[j];

			if (sum == k && j - i < answer[1] - answer[0])
			{
				answer[0] = i;
				answer[1] = j;
				i = j -1;
				break;
			}
			else if (sum > k)
				break;
		}
	}
	return answer;
}

int main()
{
	vector<int> v = { 2, 2, 2, 2, 2 };
	int k = 6;

	vector<int> answer = solution(v, k);

	for (int a : answer)
		cout << a << " ";
}