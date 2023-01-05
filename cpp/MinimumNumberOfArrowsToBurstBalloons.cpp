// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Auhtor : Shloka Mahesheka
// Date   : 25-12-2022

/***********************************************************************************

Given 2-D array of points where points[i] = [x start , x end]
Find number of ranges which are not intersecting.

For example: 
points = [[10,16],[2,8],[1,6],[7,12]]

Answer = 2

Here, (1,6) and (2,8) interesect each other.
(10,16) and (7,12) intersect each other.
Total ranges : 2
***********************************************************************************/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********************************************************************************

#Intuition
    This is a range-interval question. We have to club together as many ranges as possible to reduce the number of arrows shot. This can be done by sorting the array by the first index.

#Approach
    First, we sort the array based on the first index. By doing this clubbing the intervals together become easy. After this, we have one start and end point to denote the range starting and end point.
    Now, we traverse the array.
    If the first index is in the range of start and end, that point is in the range. We update the start as the first index and the end as the minimum of the current end and second index.
    If it is not in range we increase the count and update the start as the first index and the end as the second index.
    As the array is already sorted, the range's first index will be in increasing order.

#Complexity
    Time complexity: O(NlogN)

    Space complexity: O(1)

***********************************************************************************/

 int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int x=points[0][0],y=points[0][1];
        for(int i=1;i<points.size();++i){
                if(points[i][0]>=x && points[i][0]<=y){

                    x = points[i][0];
                    y = min(y,points[i][1]);
            }
            else{
                ++ans;
                x = points[i][0];
                y = points[i][1];
            }
        }
        return ans;
    }



int main(){

     vector<vector<int> > points= {{10,16},{2,8},{1,6},{7,12}};
    
    cout<<findMinArrowShots(points);
}