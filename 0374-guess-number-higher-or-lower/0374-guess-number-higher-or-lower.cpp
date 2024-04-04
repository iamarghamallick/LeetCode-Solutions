/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        
        while(low <= high) {
            int b = low + (high - low)/2;
            int a = guess(b);
            if(a == -1)   high = b-1;
            else if(a == 1)  low = b+1;
            else if(a == 0)  return b;
        }
        
        return 0;
    }
};