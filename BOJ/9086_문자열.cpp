#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    string s;
    cin >> num;
    while (num--)
    {
        cin >> s;
        cout << s[0] << s[s.size() - 1] << endl;
    }

    return 0;
}