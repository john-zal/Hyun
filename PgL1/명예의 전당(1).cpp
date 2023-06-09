#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int i, int j)
{
    return j < i;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> slot;
    
    for(int i = 0; i<score.size(); i++)
    {
        slot.push_back(score[i]);

        sort(slot.begin(), slot.end(), compare);
        
        if(slot.size() > k)
            slot.pop_back();
        
        answer.push_back(slot.back());
    }
    
    return answer;
}