#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    // Code here

    queue<pair<string, int>> q;
    q.push({startWord, 1});

    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while (!q.empty())
    {

        string word = q.front().first;
        int steps = q.front().second;

        q.pop();

        // word= hit...

        for (int i = 0; i < word.size(); i++)
        {

            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // if exists in the steps
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }

            word[i] = original;
        }

        if (word == targetWord)
            return steps;
    }
    return 0;
}

int main()
{
    return 0;
}