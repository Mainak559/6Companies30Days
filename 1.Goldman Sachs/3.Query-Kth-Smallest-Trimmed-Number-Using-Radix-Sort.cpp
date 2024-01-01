#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        priority_queue<vector<int>> pq; // priority queue to sort by rightmost and kth;
        for (int i = 0; i < queries.size(); ++i)
            pq.push({-queries[i][1], -queries[i][0], i}); // -rightmost, -kth, loc

        vector<int> ans(queries.size(), -1); // create it for random access later

        vector<vector<int>> temp(10); // from 0 to 9 => the nums index is recorded.
        int len = nums[0].size(), rm = 1;
        while (!pq.empty())
        {                // still have query left
            if (rm == 1) // initiate the vector first
                for (int i = 0; i < nums.size(); ++i)
                    temp[nums[i][len - rm] - '0'].push_back(i);
            else
            { // this is the radix sort
                vector<vector<int>> temp2(10);
                for (auto &a : temp)
                    for (auto &i : a)
                        temp2[nums[i][len - rm] - '0'].push_back(i);
                temp.swap(temp2);
            }
            int i = 0, ps = 0; // since kth is sorted as well, we save it for next query.
            while (!pq.empty() && pq.top()[0] == -rm)
            {
                auto a = pq.top();
                pq.pop();
                while (-a[1] - ps > temp[i].size()) // find the exact vector
                    ps += temp[i++].size();
                ans[a[2]] = temp[i][-a[1] - ps - 1];
            }
            ++rm; // next rightmost
        }
        return ans;
    }
};