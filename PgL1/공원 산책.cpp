#include <iostream>

#include <string>
#include <vector>

using namespace std;

int startPoint[2] = { 0, 0 }; //��������
int rightBottom[2] = { 0, 0 }; // �� ��
vector<vector<int>> vecPark;

void CheckMove(string& coord)
{
    char dir = coord[0];
    int move = stoi(coord.substr(2, coord.size()));

    int tempPoint[2] = { startPoint[0], startPoint[1]};
    for (int i = 0; i < move; i++)
    {      
            switch (dir)
            {
            case 'E': //����, j +1
                tempPoint[1] += 1;
                break;
            case 'N': //����, i +1
                tempPoint[0] -= 1;
                break;
            case 'W': //����, j -1
                tempPoint[1] -= 1;
                break;
            case 'S'://����, i - 1
                tempPoint[0] += 1;
                break;
            }

            //�������� �����, ��ֹ��� �΋H����
            if ((tempPoint[0] > rightBottom[0] || tempPoint[0] < 0)
                || (tempPoint[1] > rightBottom[1] || tempPoint[1] < 0)
                || (vecPark[tempPoint[0]][tempPoint[1]] == 1))
            {
                tempPoint[0] = startPoint[0];
                tempPoint[1] = startPoint[1];
                break;
            }
    }

    startPoint[0] = tempPoint[0];
    startPoint[1] = tempPoint[1];
}

vector<int> solution(vector<string> park, vector<string> routes) {
    
    vector<int> answer;
    rightBottom[0] = (int)park.size() -1;
    rightBottom[1] = (int)park[0].size() -1;

    //���� �迭 ����
    for (int i = 0; i < rightBottom[0]+1; i++)
    {
        vector<int> v;
        vecPark.push_back(v);
        for (int j = 0; j < rightBottom[1]+1; j++)
        {
            switch (park[i][j])
            {
            case 'S':
                startPoint[0] = i;
                startPoint[1] = j;
                vecPark[i].push_back(0);
                break;
            case 'O':
                vecPark[i].push_back(0);
                break;
            case 'X':
                vecPark[i].push_back(1);
                break;
            }
        }
    }
    
    // �̵���� üũ
    for (int i = 0; i < routes.size(); i++)
        CheckMove(routes[i]);

    answer.push_back(startPoint[0]);
    answer.push_back(startPoint[1]);

    return answer;
}

int main()
{
    vector<string> park = { "SOO","OOO","OOO" };
    vector<string> routes = { "E 2","S 2","W 1" };
    vector<int> result = solution(park, routes);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}