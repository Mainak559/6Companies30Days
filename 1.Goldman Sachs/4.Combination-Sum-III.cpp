#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void f(int i, int k, int n, int sumTillNow, vector<int> &subSet, vector<vector<int>> &ans)
    {
        if (k < 0)
            return;
        if (sumTillNow > n)
            return;

        if (k == 0)
        {
            if (sumTillNow == n)
                ans.push_back(subSet);

            return;
        }

        if (i == 10)
            return;

        subSet.push_back(i);
        // take
        f(i + 1, k - 1, n, sumTillNow + i, subSet, ans);

        subSet.pop_back();
        // notTake
        f(i + 1, k, n, sumTillNow, subSet, ans);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> subSet;
        vector<vector<int>> ans;
        f(1, k, n, 0, subSet, ans);
        return ans;
    }
};