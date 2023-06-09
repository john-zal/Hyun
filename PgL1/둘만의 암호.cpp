#include <iostream>

#include <string>
#include <vector>

using namespace std;



string solution(string s, string skip, int index) {

	string answer = "";
	string table = "abcdefghijklmnopqrstuvwxyz";

	//skip 문자열 제거
	for (int i = 0; i < skip.size(); i++)
		table.erase(find(table.begin(), table.end(), skip[i]));
    
	for (int i = 0; i < s.size(); i++)
	{
		int tableIndex = (int)table.find(s[i]);
		tableIndex += index;
		
		int tableSize = (int)table.size() - 1; // /n빼고

		while(tableIndex > tableSize)
			tableIndex -= tableSize+1;

		answer += table[tableIndex];
	}
    
    return answer;
}

int main()
{
	string s = "z";
	string skip = "abcdefghij";
	int index = 20;
	cout << solution(s, skip, index) << endl;
	return 0;
}