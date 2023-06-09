vector<int> solution(string s) {
    vector<int> answer;
    //abcde fghij klmno pqrst uvwxy z
    vector<int> alphabet(26, -2);
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - a;
        if (alphabet[idx] == -2)
        {
            alphabet[idx] = i;
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - alphabet[idx]);
            alphabet[idx] = i;
        }
    }
    return answer;
}