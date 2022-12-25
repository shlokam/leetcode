// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Auhtor : Shloka Mahesheka
// Date   : 25-12-2022

/***********************************************************************************

Given two arrays nums1 and  nums2. 
Find the numbers which intersect them.

Each element in the result must appear as many times as it shows in both arrays.

For example: 
nums1 = [1,2,2,1,5]
nums2 = [2,2,1,3]

Answer = [2,2,1]

***********************************************************************************/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********************************************************************************

To find out the common elements between both the arrays , we store them in two 
different map.
The key of the hashmap will be the array element and the value will be the number
of occurance.

Then we traverse the first map and check if the second map contains that element.
We check this by seeing if second map's value of the key is greater than 1.
( This means that if a map contains an element it's value should be more than 1)

If we find it true, then we store the minimim value of both's map's value 
in a variable.

Then we traverse the stored variable and add the key to our result array.

***********************************************************************************/


vector<int> intersectionOfTwoArray(vector<int> nums1,vector<int> nums2){
        vector<int> result;

        map<int,int> first,second;

        for(int i =0;i<nums1.size();++i)
        first[nums1[i]]++;

        for(int i =0;i<nums2.size();++i)
        second[nums2[i]]++;

        int count=0;
        
        for(auto i:first){
            
            if(second[i.first]>0){
                count=min(i.second,second[i.first]);
                while(count--){
                    result.push_back(i.first);
                }
            }
        }

        return result;

}

void print(vector<int> num){
    
    for(int i=0;i<num.size();++i)
        cout<<num[i]<<" ";
}

int main(){

    int n1[]={1,2,2,1};
    int n2[]={2,2};

     vector<int> num1(n1, n1 + sizeof(n1)/sizeof(int));
     vector<int> num2(n2, n2 + sizeof(n2)/sizeof(int));

     vector<int> result = intersectionOfTwoArray(num1 , num2); 

     print(result);


}