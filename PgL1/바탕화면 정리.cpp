#include <iostream>

#include <string>
#include <vector>

using namespace std;

struct coord
{
    int left = -1; //���� ���� ���� i
    int top = -1; // ���� ���� ���� j
    int right = -1;//���� ū ���� i
    int bottom = -1; //���� ū ���� j
};

void CalcCoord(coord& coord, int i, int j)
{
    if (coord.left < 0 || coord.left > i)
        coord.left = i;
    if (coord.top < 0 || coord.top > j)
        coord.top = j;
    if (coord.right < i)
        coord.right = i;
    if (coord.bottom < j)
        coord.bottom = j;
}

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    coord data;

    //����ȭ�� �迭 ����
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
                CalcCoord(data, i, j);
        }
    }

    answer.push_back(data.left);
    answer.push_back(data.top);
    answer.push_back(data.right+1);
    answer.push_back(data.bottom+1);

    return answer;
}

int main()
{
    vector<string> wallpaper = { ".#...", "..#..", "...#." };
    vector<int> ans = solution(wallpaper);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
	return 0;
}