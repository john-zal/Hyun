#include <string>
#include <vector>
#include <iostream>

using namespace std;
int solution(string s) {

    //같은 개수 구하기
    int answer = 0;
    int sameCount = 0;
    int diffCount = 0;
    char c = s[0];
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
            sameCount++;
        else
            diffCount++;

        if (sameCount == diffCount)
        {
            sameCount = 0;
            diffCount = 0;
            answer += 1;
            if (i + 1 <= s.size())
                c = s[i + 1];
        }
        else if (i == s.size() - 1)
            answer += 1;
    }

    return answer;
}

int main()
{
    cout << solution("aaabbaccccabba") << endl;
    return 0;
}