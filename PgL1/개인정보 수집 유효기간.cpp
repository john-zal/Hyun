#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void StrToMap(vector<string> terms, unordered_map<char, int>& map)
{
    for (int i = 0; i < terms.size(); i++)
    {
        int num = stoi(terms[i].substr(2, terms[i].size()));
        map.insert(make_pair(terms[i][0], num));
    }
}

string CalcPrivacies(string privacies, unordered_map<char, int> map)
{
    string endDay = "";
    
    int addDay = map.find(privacies.back())->second * 28;

    string YYMMDD = privacies.substr(0, 10);
    int year = stoi(YYMMDD.substr(0, 4));
    int month = stoi(YYMMDD.substr(5, 2));
    int day = stoi(YYMMDD.substr(8, 2));

    day += addDay -1;

    while (day > 28)
    {
        day -= 28;
        month += 1;
    }

    while (month > 12)
    {
        month -= 12;
        year += 1;
    }

    string strMonth = to_string(month);
    string strDay = to_string(day);

    if (strMonth.size() == 1)
        strMonth = "0" + to_string(month);
    if (strDay.size() == 1)
        strDay = "0" + to_string(day);

    endDay = to_string(year) + "." + strMonth + "." + strDay;
     return endDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    unordered_map<char, int> map;
    StrToMap(terms, map);

    for (int i = 0; i < privacies.size(); i++)
    {
        string destroyDay = CalcPrivacies(privacies[i], map);
        string todays = today;

        todays.erase(remove(todays.begin(), todays.end(), '.'), todays.end());
        destroyDay.erase(remove(destroyDay.begin(), destroyDay.end(), '.'), destroyDay.end());

        int todayNum = stoi(todays);
        int destroyNum = stoi(destroyDay);

        //°á°ú
        if (destroyNum < todayNum)
            answer.push_back(i+1);
    }

    return answer;
}

int main()
{
    string today = "2020.01.01";
    vector<string> terms = { "Z 3", "D 5" };
    vector<string> privacies = { 
        "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" };
    vector<int> v = solution(today, terms, privacies);
    
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}