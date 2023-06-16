#include<iostream>

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    unordered_map<string, int> mapName;
    unordered_map<int, string> mapRank;

    for (int i = 0; i < players.size(); i++)
    {
        mapName.insert(make_pair(players[i], i + 1));
        mapRank.insert(make_pair(i+1, players[i]));
    }

    for (int i = 0; i < callings.size(); i++)
    {
        //위로 올라갈 선수
        unordered_map<string, int>::iterator find = mapName.find(callings[i]);

        int rank = find->second;
        //윗 선수 정보
        unordered_map<int, string>::iterator findUpRank = mapRank.find(rank -1);

        //위로 올라갈 선수 정보
        unordered_map<int, string>::iterator findDownRank = mapRank.find(rank);
        
        string tempName = findUpRank->second;
        findUpRank->second = find->first;
        findDownRank->second = tempName;
        
        unordered_map<string, int>::iterator find2 = mapName.find(tempName);
        find2->second = rank;
        find->second = rank - 1;
    }

    for (int i = 1; i <= players.size(); i++)
    {
        string name = mapRank.find(i)->second;
        answer.push_back(name);
    }

    return answer;
}

int main()
{
    vector<string> players = { "mumu", "soe", "poe", "kai", "mine" };
    vector<string> callings = { "kai", "kai", "mine", "mine" };
    vector<string> answer = solution(players, callings);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " " << endl;
    }
}