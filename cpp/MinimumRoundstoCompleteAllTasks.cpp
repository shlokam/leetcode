// Source : https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/description/
// Auhtor : Shloka Mahesheka
// Date   : 04-01-2023

/***********************************************************************************

Given arrays of integers .
Group same numbers in size of 2 or 3.
Groups of size 1 cannot be formed.
Find the minimum number of groups that can be formed.

For example: 
array = [2,2,2,7,7,7,7,7]

Answer = 3
Groups: (2,2,2) , (7,7,7) , (7,7)

***********************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********************************************************************************

#Intuition
We have to take group 2 or 3 elements. So, we need to store frequency of each element in the array.

#Approach
Iterate over array and store in map. If frequency of element less than 2, we return 1.
Now, we have to group elements either in 2 or 3.

We can do so by adding our answer with frequency/3 and the remainder.
When we divide any number by 3, the remainders can be 0,1,2.

Remainder==0
No remaining elements left.
Remainder==1
One element left. We can't group 1 element together. But we can have another approach as that can dealt with grouping it using 2.
Let's say we have 4. When we divide it by 3 quotient 1, remainder 1.
Total: 1 + 1 = 2.
Another approcan is we group by (2,2). So, 2 groups formed.
Total= 2.
Result in both cases will remain same.
Reaminder==2
We can group remaining element in one group of 2.

#Complexity
Time complexity:O(n)

Space complexity:O(n)

***********************************************************************************/
int minimumRounds(vector<int> tasks) {
        map<int,int> m;
        int answer=0;

        for(int i=0;i<tasks.size();++i)
        m[tasks[i]]++;

        for(auto i:m){
            if(i.second<2)
            return -1;
            else{
                answer = answer + i.second/3;
                if(i.second%3!=0)
                ++answer;
            }
        }
        return answer;
    }
int main(){

    vector<int> v ={2,2,3,3,2,4,4,4,4,4};

    cout<< minimumRounds(v);
    return 0;
}