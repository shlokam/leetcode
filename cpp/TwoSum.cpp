// Source : https://leetcode.com/problems/two-sum/description/
// Auhtor : Shloka Mahesheka
// Date   : 14-01-2023

/***********************************************************************************

Given arrays of integers and one integer target. 
Find two index whose sum is equal to target
For example: 
nums = [2,7,11,15]
target = 9
Answer = [0,1]

nums[0] + nums[1] = 2 + 7 = 9 = target
***********************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********************************************************************************

We store the frequency of array elements in map;
Then traverse map and check for whether target - key exixts in map.
If it exists then we store those values and break the loop.

Then, we loop over array and find respective index for those values.

***********************************************************************************/

vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> m;
        vector<int> ans;

        for(int i=0;i<nums.size();++i)
            m[nums[i]]++;

        int x,y;
        for(auto i:m){
            if(m[target-i.first]>=1){
                x = i.first;
                y = target-i.first;
                break;
            }
        }
        int ind1=-1,ind2=-1;

        for(int i=0;i<nums.size();++i){
            if(nums[i]==x && ind1==-1)
                ind1=i;

            if(nums[i]==y && ind2==-1 && ind1!=i)
                ind2=i;
        }

        ans.push_back(ind1);
        ans.push_back(ind2);

        return ans;
    }
int main(){

    vector<int> nums{2,7,11,15};

   int target = 9;
   vector<int> ans;
    ans  = twoSum(nums,target);

    cout<<ans[0]<<" "<<ans[1]<<"\n";
    return 0;
}