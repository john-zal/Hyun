#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int Calc[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int DayToNum(int month, int day)
{
	int num = 0;

	for (int i = 1; i < month; i++)
		num += Calc[i];

	num += day;

	return num;
}

int main()
{
	int N;
	int answer = 0;
	vector<pair<int, int>> vec;
	
	cin >> N;
	while (N--)
	{
		int arr[4] = {};
		for (int i = 0; i < 4; i++)
			cin >> arr[i];

		vec.push_back({ DayToNum(arr[0], arr[1]), 
						DayToNum(arr[2], arr[3])});
	}
	sort(vec.begin(), vec.end());

	int startDay = DayToNum(3, 1);
	int endDay = DayToNum(12, 1);
	int useIndex = 0;
	while (true)
	{
		bool isChange = false; //for문 변화 없을 시
		for (int i = useIndex; i < vec.size(); i++)
		{
			if (vec[i].first <= startDay && vec[i].second > startDay)
			{	
				if (!isChange)
				{
					isChange = true;
					answer += 1;
					useIndex = i;
					continue;
				}
				
				//같은 시작점인데 더 긴거 있으면 교체
				else if (isChange && vec[i].second - startDay >
					vec[useIndex].second - startDay) 
					useIndex = i;
			}
		}

		//for문 종료 후 todo
		if (isChange)
			startDay = vec[useIndex].second;
		else
		{
			cout << 0;
			return 0;
		}

		if (startDay >= endDay)
		{
			cout << answer;
			return 0;
		}
	}

}