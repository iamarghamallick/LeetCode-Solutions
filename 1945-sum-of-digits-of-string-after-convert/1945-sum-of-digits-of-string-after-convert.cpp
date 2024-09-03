class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(char c : s) {
            int index = c - 'a' + 1;
            if(index < 10)
                num += index;
            else {
                num += index % 10 + index / 10;
            }
        }
        k--;
        while(k) {
            int temp = 0;
            while(num) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
            k--;
        }
        
        return num;
    }
};