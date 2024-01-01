#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {

        vector<int> ans;
        for (auto it : queries)
        {
            int n = nums.size();
            vector<pair<string, int>> v;
            for (int j = 0; j < nums.size(); j++)
            {
                string sub = nums[j].substr(nums[j].size() - it[1]); // queries[i][1]
                v.push_back({sub, j});
            }
            sort(v.begin(), v.end());
            int k = it[0] - 1;
            ans.push_back(v[k].second);
        }

        return ans;
    }
};