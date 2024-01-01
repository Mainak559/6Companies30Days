#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void f(int i, string &s, string &temp, vector<string> &ans, unordered_map<int, string> &mpp)
    {

        if (i == s.size())
        {
            ans.push_back(temp);
            return;
        }

        string str = mpp[s[i]];

        for (int j = 0; j < str.size(); j++)
        {
            temp.push_back(str[j]);
            f(i + 1, s, temp, ans, mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        string temp;

        unordered_map<int, string> mpp;

        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        if (digits.size() > 0)
            f(0, digits, temp, ans, mpp);
        return ans;
    }
};