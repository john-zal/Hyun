#include <iostream>
#include <string>
#include <vector>
#define ASCII_A 65

using namespace std;
vector<int> vecAlpha(26, -1);

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    for (int i = 0; i < keymap.size(); i++)
    {
        for (int j = 0; j < keymap[i].size(); j++)
        {
            char alphabet = keymap[i][j];

            //입력이 되는 키거나 기존 입력횟수보다 적으면 
            if (vecAlpha[alphabet - ASCII_A] == -1
                || vecAlpha[alphabet - ASCII_A] > j)
                vecAlpha[alphabet - ASCII_A] = j + 1;
        }
    }

    //타겟 검출
    for (int i = 0; i < targets.size(); i++)
    {
        int sum = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            char alphabet = targets[i][j];
            if (vecAlpha[alphabet - ASCII_A] == -1)
            {
                sum = -1;
                break;
            }
            else
                sum += vecAlpha[alphabet - ASCII_A];
        }
        answer.push_back(sum);
    }

    return answer;
}

int main()
{
    vector<string> keymap = { "ABACD", "BCEFD" };
    vector<string> targets = { "ABCD","AABB"};
    vector<int> answer = solution(keymap, targets);
    for (int i = 0; i < targets.size(); i++)
        cout << answer[i] << endl;

    return 0;
}