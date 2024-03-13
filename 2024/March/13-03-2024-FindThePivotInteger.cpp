// Question link: https://leetcode.com/problems/find-the-pivot-integer/description/

/*Given a positive integer n, find the pivot integer x such that:
The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input. 

Example 1:
Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21
Example 2:
Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.
Example 3:
Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
*/
// My approach uses two pointers concept with time complexity O(n)
class Solution {
public:
    int pivotInteger(int n) {
        int i=1,j=n;
        int lsum=i,rsum=n;
        while(i<=j) {
            if(lsum<rsum) {
                i++;
                lsum+=i;
            }
            else if(lsum>rsum) {
                j--;
                rsum=rsum+j;
            }
            else {
                    if(i==j) {
                        return i;
                    }
                    i++;
                    j--;
                    if(i==j) {
                        return i;
                    }
                    lsum+=i;
                    rsum+=j;
            }
        }
        return -1;
    }
};

//A better approach was there that had a complexity of O(1) that uses arithmetic progression
class Solution {
 public:
  int pivotInteger(int n) {
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
};

