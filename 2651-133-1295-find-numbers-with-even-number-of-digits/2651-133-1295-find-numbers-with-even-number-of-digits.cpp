class Solution {
public:
    int countDigit(int num) {
        if(num >= 0 && num <= 9)  return 1;
        if(num >= 10 && num <= 99)  return 2;
        if(num >= 100 && num <= 999)  return 3;
        if(num >= 1000 && num <= 9999)  return 4;
        if(num >= 10000 && num <= 99999)  return 5;
        if(num >= 100000 && num <= 999999)  return 6;
        return 0;
    }

    int findNumbers(vector<int>& nums) {
        int count = 0;

        for(int num : nums)
            if(countDigit(num) % 2 == 0)
                count++;
        
        return count;
    }
};