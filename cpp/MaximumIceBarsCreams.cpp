// Source : https://leetcode.com/problems/maximum-ice-cream-bars/description/
// Auhtor : Shloka Mahesheka
// Date   : 06-01-2023

/***********************************************************************************

Given arrays of costs of ice-creams and coins.
Find maximum number of ice-creams that can be bought with given number of coins.
For example: 
costs = [1,3,2,4,1], coins = 7

Answer = 4
We can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.

***********************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

/***********************************************************************************

We can check every subsequence and find the maximum number. That will take 
exponential time. 
To reduce that, we can approach this greedily.
We sort costs. After that we traverse and start adding the costs.
The index where sum crosses the coins, we break and that index is our answer.

***********************************************************************************/

int maxIceCream(vector<int>& costs, int coins) {
        
        sort(costs.begin(),costs.end());
        int ans=0;
        int currentSum=0;

        for(int i=0;i<costs.size();++i){
            currentSum = currentSum + costs[i];

            if(currentSum<=coins)
            ++ans;

            else
            break;
        }

        return ans;
    }
int main(){

    vector<int> costs={1,3,2,4,1};

    int coins = 7;

    cout<< maxIceCream(costs,coins);
    return 0;
}