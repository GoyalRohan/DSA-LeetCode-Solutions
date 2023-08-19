class Solution {
public:
    
    int total;
    bool visited[16];

    bool dfs(int start, int group, int sum, int k, vector<int>& nums)
    {
        bool ret;
        if(sum > total/k)
            return false;
        if(group == k)
            return true;

        if(sum == total/k)
            return dfs(0, group+1, 0, k, nums);

        for(int i = start; i< nums.size();i++)
        {
            if(visited[i] == true)
                continue;
            visited[i] = true;
            ret = dfs(i+1, group, sum + nums[i], k, nums);

            visited[i] = false;
            if(ret == true)
                return true;

        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        total = accumulate(nums.begin(), nums.end(), 0);
        if(total%k !=0)
            return false;
        return dfs(0, 0, 0, k, nums);
    }

};