#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

//그지같은 문제다.
/*
	ios::sync_with_stdio(0);
	cin.tie(0);
	이 코드로 까지 해주고 시간초과가 나고
	cout.tie(0); 까지 해줘서 통과했다.

	문자열로 검색할땐 해시를 쓰고 (키값이 숫자면 의미없는듯)
	인덱스로 검색할때는 배열로 쓰는게 관건이다.

	isdigit()함수도 알아가자.
*/

int main()
{
	//포켓몬
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
		//번호로 찾기 	
		//if(s[0] >= '0' && s[0] <= '9')
		if(isdigit(s[0]))
			cout << v[stoi(s)] << '\n';
		else //이름으로 찾기
			cout << map[s] << '\n';	
	}
}