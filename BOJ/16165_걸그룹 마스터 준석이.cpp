#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	//�ɱ׷� N, ���� �� M
	int N, M, memberCount;
	unordered_map<string, vector<string>> girlGroup;
	string s;
	vector<string> answer;
	cin >> N >> M;

	while (N--)
	{
		cin >> s;

		cin >> memberCount;
		vector<string> vec(memberCount);
		while (memberCount--)
			cin >> vec[memberCount];

		sort(vec.begin(), vec.end());

		girlGroup.insert(make_pair(s, vec));
	}
	//����
	while (M--)
	{
		//0�� �ɱ׷��� �־����� ��� �����ؼ� ����ϱ�
		//1�� ����� �־����� ����� ���� �ɱ׷� Ž���ϱ�
		bool quiz;
		cin >> s >> quiz;

		if (quiz)
		{
			unordered_map<string, vector<string>>::iterator iter = girlGroup.begin();
			auto iterEnd = girlGroup.end();

			for (; iter != iterEnd; iter++)
			{
				vector<string> vec = (*iter).second;
				for (string str : vec)
				{
					if (str == s)
					{
						answer.push_back((*iter).first);
						break;
					}
				}
			}
		}
		else
		{
			vector<string> vec = girlGroup[s];
			for (string str : vec)
				answer.push_back(str);
		}
	}

	for (string str : answer)
		cout << str << '\n';

}