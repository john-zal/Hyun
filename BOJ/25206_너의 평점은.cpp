#include <iostream>
#include <string>
#include <vector>
using namespace std;

double ConvertGrade(string& s)
{
	double value = 0.f;
	if (s == "A+")
		value = 4.5f;
	else if (s == "A0")
		value = 4.0f;
	else if (s == "B+")
		value = 3.5f;
	else if (s == "B0")
		value = 3.0f;
	else if (s == "C+")
		value = 2.5f;
	else if (s == "C0")
		value = 2.0f;
	else if (s == "D+")
		value = 1.5f;
	else if (s == "D0")
		value = 1.0f;
	else if (s == "F")
		value = 0.f;
	else if (s == "P")
		value = -1.f;

	return value;
}

int main()
{
	vector<double> score;
	vector<double> grade;

	string s;

	for (int i = 0; i < 20; i++)
	{
		getline(cin, s);
		for (int i = (int)s.size()-1; i > 0; i--)
		{
			if (s[i] == ' ')
			{
				s = s.substr(i - 3, s.size());
				score.push_back((double(s[0] - '0')));
				s = s.substr(4, s.size());
				grade.push_back(ConvertGrade(s));
				break;
			}			
		}
	}

	double scoreSum = 0.f;
	double totalSum = 0.f;
	for (int i = 0; i < 20; i++)
	{
		if (grade[i] < 0.f) //pÇÐÁ¡
			continue;

		totalSum += score[i] * grade[i];
		scoreSum += score[i];
	}
	cout << totalSum / scoreSum;
}