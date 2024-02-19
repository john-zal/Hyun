#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//�������� ������.
/*
	ios::sync_with_stdio(0);
	cin.tie(0);
	�� �ڵ�� ���� ���ְ� �ð��ʰ��� ����
	cout.tie(0); ���� ���༭ ����ߴ�.

	���ڿ��� �˻��Ҷ� �ؽø� ���� (Ű���� ���ڸ� �ǹ̾��µ�)
	�ε����� �˻��Ҷ��� �迭�� ���°� �����̴�.

	isdigit()�Լ��� �˾ư���.
*/

int main()
{
	//���ϸ�
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	unordered_map<string, int> map;
	vector<string> v;
	
	string s = "";
	v.push_back("Mew");
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		map.insert(make_pair(s,i));
		v.push_back(s);
	}

	for (int i = 0; i < M; i++)
	{
		cin >> s;
		//��ȣ�� ã�� 	
		//if(s[0] >= '0' && s[0] <= '9')
		if(isdigit(s[0]))
			cout << v[stoi(s)] << '\n';
		else //�̸����� ã��
			cout << map[s] << '\n';	
	}
}