#include<iostream>
using namespace std;

class Solution {
    vector<vector<int>> results;
    vector<int> path;

    vector<int> findCandidates(vector<int>& numbers, int target, int nodeValue)
    {
        vector<int> candidates;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (numbers[i] <= target && nodeValue <= numbers[i])
            {
                candidates.push_back(numbers[i]);
            }
        }
        return candidates;
    }

    vector<int> copyPath(vector<int> path)
    {
        vector<int> sol;
        for (int i = 0; i < path.size(); i++)
        {
            sol.push_back(path[i]);
        }
        return sol;
    }

    void backtracking(vector<int>& numbers, int target, int nodeValue)
    {
        if (target == 0)
        {
            vector<int> sol = copyPath(path);
            results.push_back(sol);
            return;
        }
        vector<int> candidates = findCandidates(numbers, target, nodeValue);
        for (int i = 0; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            backtracking(numbers, target-candidates[i], candidates[i]);
            path.pop_back();
        }
        
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0);

        return results;
    }
};


