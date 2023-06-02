#include <iostream>
using namespace std;
#include <vector>

int answer = 0;

void CheckHamburger(vector<int>& vec)
{
	//빵(1) 야채(2) 고기(3)
	//뒤에서부터 체크하니 빵 - 고기 - 야채 - 빵 순으로 체크
	// 1 3 2 1
	int size = (int)vec.size();
	if (vec[size - 1] == 1 && vec[size - 2] == 3
		&& vec[size - 3] == 2 && vec[size - 4] == 1)
	{
		for (int i = 0; i < 4; i++)
			vec.pop_back();

		answer++;

		if (vec.back() == 1)
			CheckHamburger(vec);
	}
}

int solution(vector<int> ingredient) {
	
	vector<int> vecCheck;

	for (int i = 0; i < ingredient.size(); i++)
	{
		vecCheck.push_back(ingredient[i]);

		if (vecCheck.size() >= 4)
			CheckHamburger(vecCheck);

	}
	return answer;
}

int main()
{
	vector<int> v = { 1, 3, 2, 1, 2, 1, 3, 1, 2 };

	cout << solution(v) << endl;
	return 0;
}