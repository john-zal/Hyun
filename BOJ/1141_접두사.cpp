#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	//h hello hi rerun run running
	
	int answer = N;

	vector<string> vec(N);

	while(N--)
		cin >> vec[N];

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size()-1; i++)
	{		
		for (int j = i+1; j < vec.size(); j++)
		{
			string prefix = vec[j].substr(0, vec[i].size());

			if (vec[i] == prefix)
			{
				answer--;
				break;
			}
		}
	}
	cout << answer;
}