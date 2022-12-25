#include<iostream>
#include<vector>
#include<map>
using namespace std;

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