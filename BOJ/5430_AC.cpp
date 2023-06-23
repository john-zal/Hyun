#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool isReverse = false;

void R(deque<int>& deq)
{
	//�迭�� �ִ� ���� ������ ������ �Լ�
	isReverse = !isReverse;
}
bool D(deque<int>& deq)
{
	// �迭�� ����µ� ����ϸ� ����
	if (deq.empty())
		return true; //true�� error��ȯ
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
	//���ۿ� �߰��Ѵ�.
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

	//�׽�Ʈ ���̽� ���� T
	int T = 0;
	
	cin >> T;
	while (T--)
	{
		deque<int> deq;

		//������ �Լ� ��� RD ~100000
		string operation = "";
		cin >> operation;

		//�迭 ���� �Է�
		int arrSize = 0;
		cin >> arrSize;

		//�迭 �Է� ����
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