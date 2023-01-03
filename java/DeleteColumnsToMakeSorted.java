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


class Solution{

    
    public static void main(String[] args) {
        String[] str = new String[]{"cba","daf","ghi"};

    
        System.out.println(deleteColoumsToMakeSorted(str)); 
    }

    
/***********************************************************************************

To find coloumns are not lexographically sorted, we can check whether one character 
is bigger than its right adjacent.

For example, in string "bca" , the character at 1st index(c) is bigger than character 
at 2nd index(a). 
This means that string is not lexographically sorted. 

***********************************************************************************/

    public static int deleteColoumsToMakeSorted(String[] strs){

        int s = strs[0].length();
        int answer=0;
    
        for(int i=0;i<s;++i){
            for(int j=0;j<strs.length-1;++j){
                if(strs[j].charAt(i)> strs[j+1].charAt(i)){
                    ++answer;
                    break;
                }
            }
        }
    
        return answer;
        
    }
}
