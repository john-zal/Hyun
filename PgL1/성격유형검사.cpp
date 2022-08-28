#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<char, int> Survey_Score;
// R T C F J M A N

void InitMap() 
{
    Survey_Score.insert(make_pair('R', 0));
    Survey_Score.insert(make_pair('T', 0));
    Survey_Score.insert(make_pair('C', 0));
    Survey_Score.insert(make_pair('F', 0));
    Survey_Score.insert(make_pair('J', 0));
    Survey_Score.insert(make_pair('M', 0));
    Survey_Score.insert(make_pair('A', 0));
    Survey_Score.insert(make_pair('N', 0));
}

string Result() 
{    
    string answer;

    Survey_Score['R'] >= Survey_Score['T'] ? answer += 'R' : answer += 'T';
    Survey_Score['C'] >= Survey_Score['F'] ? answer += 'C' : answer += 'F';
    Survey_Score['J'] >= Survey_Score['M'] ? answer += 'J' : answer += 'M';
    Survey_Score['A'] >= Survey_Score['N'] ? answer += 'A' : answer += 'N';

    return answer;
}

void SetSurveyScore(char a, char b, int choice) 
{
    if (choice < 4) //매우 비동의~약간 비동의
    {
        int temp = Survey_Score[a]+(4-choice);
        Survey_Score[a] = temp;
    }

    else if (choice > 4)
    {
        int temp = Survey_Score[b] + (choice%4);
        Survey_Score[b] = temp;
    }   
}


string solution(vector<string> survey, vector<int> choices) {
    //질문 판단 배열 survey "RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA"
    //선택지 choice

    InitMap();

    //설문조사
    for (int i = 0; i < survey.size(); i++)
    {
        char tempA = survey[i].front();
        char tempB = survey[i].back();

        SetSurveyScore(tempA, tempB, choices[i]);
    }

    //결과
    return Result();
}

int main() 
{
    vector<string> v;

    v.push_back("AN");
    v.push_back("CF");
    v.push_back("MJ");
    v.push_back("RT");
    v.push_back("NA");

    vector<int> v2;

    v2.push_back(5);
    v2.push_back(3);
    v2.push_back(2);
    v2.push_back(7);
    v2.push_back(5);
    string a = "";

    a = solution(v, v2);
    cout << a << endl;
    return 0;
}