/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
class SolutionA
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        throw invalid_argument("Invalid argument.");
    }
};

class SolutionB
{
    //The solution below doesn't handle situations with duplicate numbers.
    //Since the test cases in problem one don't include case with duplicate numbers, this solution is accepted.
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int, size_t> numMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            numMap.insert(make_pair(nums[i], i));
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            int residual = target - nums[i];
            if (numMap.find(residual) != numMap.end() && numMap[residual] != i)
            {
                res.push_back(i);
                res.push_back(numMap[residual]);
                return res;
            }
        }
        throw invalid_argument("Invalid argument.");
    }
};

class SolutionC
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int, size_t> numMap;
        for (int i = 0; i < nums.size(); ++i)
        {
            int residual = target - nums[i];
            if (numMap.find(target - nums[i]) != numMap.end())
            {
                res.push_back(i);
                res.push_back(numMap[residual]);
                return res;
            }
            numMap.insert(make_pair(nums[i], i));
        }
        throw invalid_argument("Invalid argument.");
    }
};
