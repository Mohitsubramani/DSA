// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.

//1.loops
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    
                }
            }
        }
        return ans;
        
    }
};


//2.map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int wanted=target-nums[i];
            if(mpp.find(wanted)!=mpp.end())
            {
                return {mpp[wanted],i};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};

//3.two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>>num;//used pair to perserve the index if already sorted not needed.
       for(int i=0;i<nums.size();i++)
       {
        num.push_back({nums[i],i});
       }
       sort(num.begin(),num.end());
       int left=0,right=num.size()-1;
       while(left<right)
       {
        int sum=num[left].first+num[right].first;
        if(sum==target)
        {
            return {num[left].second,num[right].second};
        }
        if(sum<target)
        {
            left++;
        }
        if(sum>target)
        {
            right--;
        }
       }
       return {-1,-1};
    }
};
