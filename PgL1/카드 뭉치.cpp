#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool FindCard(vector<string>& cards, string& goal)
{
    bool findCard = false;

    if (!(cards.empty()) && cards[0] == goal)
    {
        cards.erase(cards.begin());
        findCard = true;
    }
    return findCard;
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
        for (int i = 0; i < goal.size(); i++)
        {
            if (!(FindCard(cards1, goal[i])))
                if(!(FindCard(cards2, goal[i])))
                    answer = "No";
        }
        return answer;
}

int main()
{
    vector<string> cards1 = { "i", "water", "drink" };
    vector<string> cards2 = { "want", "to" };
    vector<string> goal = { "i", "want", "to", "drink", "water" };

    cout << solution(cards1, cards2, goal) << endl;
    return 0;
}