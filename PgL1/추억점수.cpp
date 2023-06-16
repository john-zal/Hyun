#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> uMap;
    
    for(int i= 0; i< yearning.size(); i++)
        uMap.insert(make_pair(name[i], yearning[i]));
    
    for(int i = 0; i<photo.size(); i++)
    {
        int sum = 0;
        vector<string> photoName = photo[i]; 
        for(int j = 0; j<photoName.size(); j++)
        {
            unordered_map<string, int>::iterator iter = uMap.find(photoName[j]);
            
            if(iter == uMap.end())
                continue;
            else
                sum+=iter->second;
        }
        answer.push_back(sum);
    }
    return answer;
}