class Solution {
public:
    int compare(int a, int b) {
        if(a > b)   return 1;
        if(a < b)   return -1;
        return 0;
    }
    
    int compareVersion(string v1, string v2) {
        int m = v1.size();
        int n = v2.size();
        int i = 0, j = 0;
        int num1 = 0, num2 = 0;
        
        while(i < m || j < n) {
            while(i < m && v1[i] != '.') {
                num1 = num1 * 10 + (v1[i] - '0');
                i++;
            }
            
            while(j < n && v2[j] != '.') {
                num2 = num2 * 10 + (v2[j] - '0');
                j++;
            }
            
            int res = compare(num1, num2);
            if(res != 0)
                return res;
            
            i++; j++;
            num1 = 0; num2 = 0;
        }
        
        return 0;
    }
};