#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    //벽의 길이 n 롤러의 길이 m 안칠한 숫자

    bool check = false;
    
    while (!section.empty())
    {
        int startIndex = section.front();
        while ((startIndex + m - 1) > n)
            startIndex--;
        //
        for (int i = startIndex; i < startIndex+m; i++)
        {
            if (!(section.empty()) && i == section.front())
            {
                section.erase(section.begin());
                check = true;
            }
        }
        if (check)
        {
            answer++;
            check = false;
        }
    }
    return answer;
}

int main()
{
    int n = 5;
    int m = 4;
    vector<int> section = { 1, 3 };

    cout<< solution(n, m, section) << endl;

	return 0;
}