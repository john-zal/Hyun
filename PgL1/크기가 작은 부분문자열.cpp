#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    
    int answer = 0;
    int tSize = t.size();
    int pSize = p.size();

    for(int i =0; i<tSize; i++)
    {
        if(i+pSize > tSize)
            break;
        
        if(t.substr(i, pSize) <= p)
            answer++;
    }

    return answer;
}