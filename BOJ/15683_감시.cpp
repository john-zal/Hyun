#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/*
* 3은 직각 
CCTV 1	2	3	4	5
	 →  ↔   ↑→ ←↑→  +
*/

//상, 하, 좌, 우
pair<int, int> DIR[4] = { {-1,0}, {1,0}, {0, -1}, {0, 1} };
#define x first
#define y second 

class Camera
{
public:
	Camera() {};
	~Camera() {};

	vector<pair<int, int>> camDir;

	//카메라, Default는 위
	void SetCamDir(int num)
	{
		switch (num-1)
		{
		case 1: //1번 카메라
			camDir.push_back(DIR[num]);
			break;
		case 2: //2번 카메라 상, 하
			camDir.push_back(DIR[0]); 
			camDir.push_back(DIR[1]);
			break;
		case 3: //3번 카메라 상, 우
			camDir.push_back(DIR[0]);
			camDir.push_back(DIR[3]);
			break;
		case 4: //4번 카메라 상, 좌, 우
			camDir.push_back(DIR[0]);
			camDir.push_back(DIR[2]);
			camDir.push_back(DIR[3]);
			break;
		case 5: //5번 카메라 상, 하, 좌, 우
			camDir.push_back(DIR[0]);
			camDir.push_back(DIR[1]);
			camDir.push_back(DIR[2]);
			camDir.push_back(DIR[3]);
			break;
		default:
			break;
		}
	}

	void ChangeCamDir(int count)
	{

	}

	void ResetCamDir()
	{
		for (int i = 0; i < 4; i++)
			camDir[i] = { 0, 0 };
	}
};


int main()
{
	int N, M;
	cin >> N >> M;
}
