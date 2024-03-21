#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	vector<int> vecPlus;
	int vecZero = 0;
	vector<int> vecMinus;
	int num;

	int answer = 0;

	cin >> N;
	while (N--)
	{
		cin >> num;
		if (num > 0)
			vecPlus.push_back(num);
		else if (num == 0)
			vecZero++;
		else
			vecMinus.push_back(num);
	}
		
	sort(vecPlus.begin(), vecPlus.end());
	sort(vecMinus.begin(), vecMinus.end());

	int i = 0;
	if ((int)vecPlus.size() % 2)
	{
		i = 1;
		answer += vecPlus[0];
	}

	for (i; i < vecPlus.size(); i += 2)
		answer += max(vecPlus[i] * vecPlus[i + 1],
			vecPlus[i] + vecPlus[i + 1]); //둘이 곱한것보다 더한게 더 클수도 있음
		
	int size = (int)vecMinus.size();
	if (size % 2)
	{
		size--;
		if (!vecZero)
			answer += vecMinus[size];
	}

	for (int i = 0; i < size; i+=2)
		answer += vecMinus[i] * vecMinus[i + 1];

	cout << answer;
}