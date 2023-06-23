#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool isReverse = false;

void R(deque<int>& deq)
{
	//배열에 있는 수의 순서를 뒤집는 함수
	isReverse = !isReverse;
}
bool D(deque<int>& deq)
{
	// 배열이 비었는데 사용하면 에러
	if (deq.empty())
		return true; //true시 error반환
	else
		isReverse ? deq.pop_back() : deq.pop_front();

	return false;
}

void Parse(string& s, deque<int>& deq)
{
	string str = "";
	for (char c : s)
	{
		if (c == '[' || c == ',' || c == ']')
		{
			if (!(str == ""))
			{
				int num = stoi(str);
				deq.push_back(num);
				str = "";
			}
			continue;
		}
		else
			str += c;
	}
}

string AddPrint(bool isFail, deque<int>& deq, string& answer)
{
	//버퍼에 추가한다.
	if (isFail)
		answer += "error\n";
	else
	{
		answer += '[';

		if (!isReverse)
		{
			for (int i = 0; i < deq.size(); i++)
			{
				answer += to_string(deq[i]);
				if(!(i == deq.size()-1))
					answer += ',';
			}
		}
		else
		{
			for (int i = deq.size()-1; i >= 0; i--)
			{
				answer += to_string(deq[i]);
				if (!(i == 0))
					answer += ',';
			}
		}
		answer += "]\n";
	}

	return answer;
}

int main()
{
	string answer = "";

	//테스트 케이스 개수 T
	int T = 0;
	
	cin >> T;
	while (T--)
	{
		deque<int> deq;

		//수행할 함수 명령 RD ~100000
		string operation = "";
		cin >> operation;

		//배열 개수 입력
		int arrSize = 0;
		cin >> arrSize;

		//배열 입력 받음
		string strArr = "";
		cin >> strArr;

		Parse(strArr, deq);
		
		bool isFail = false;
		for (char c : operation)
		{
			switch (c)
			{
			case 'R':
				R(deq);
				break;
			case 'D':
				if (D(deq))
					isFail = true;
				break;
			}

			if (isFail)
				break;
		}
		AddPrint(isFail, deq, answer);
		isReverse = false;
	}

	cout << answer << endl;
	return 0;
}