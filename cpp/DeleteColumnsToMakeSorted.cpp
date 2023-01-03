// Source : https://leetcode.com/problems/delete-columns-to-make-sorted/description/
// Auhtor : Shloka Mahesheka
// Date   : 03-01-2023

/***********************************************************************************

Given arrays of strings. 
Traverse the array coloumn wise.
Count number of columns who are not sorted lexographicaly.
For example: 
str = ["cba","daf","ghi"]

Answer = 1

***********************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********************************************************************************

To find coloumns are not lexographically sorted, we can check whether one character 
is bigger than its right adjacent.

For example, in string "bca" , the character at 1st index(c) is bigger than character 
at 2nd index(a). 
This means that string is not lexographically sorted. 

***********************************************************************************/

int  deleteColoumsToMakeSorted(vector<string> strs){

    int ans=0;
        int flag=0;
        int s = strs[0].size();
        for(int i=0;i<s;++i){
            flag=0;
            for(int j=0;j<strs.size()-1;++j){

                if(strs[j][i]>strs[j+1][i]){
                    flag=1;
                    break;
                }
            }
            if(flag)
            ++ans;
        }

        return ans;
}
int main(){

    vector<string> str;

    str.push_back("cba");
    str.push_back("daf");
    str.push_back("ghi");

    cout<< deleteColoumsToMakeSorted(str);
    return 0;
}