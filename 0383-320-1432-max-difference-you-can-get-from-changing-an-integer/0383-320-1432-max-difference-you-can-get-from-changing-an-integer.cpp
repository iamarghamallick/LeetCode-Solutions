class Solution {
public:
    int maxDiff(int num) {
        vector<int> arr;
        while(num) {
            arr.push_back(num % 10);
            num /= 10;
        }
        reverse(arr.begin(), arr.end());

        int a = 0, b = 0;
        int digitToReplace = -1, replaceWith = -1;
        for(int i=0; i<arr.size(); i++) {
            if(digitToReplace == -1 && arr[i] < 9) {
                digitToReplace = arr[i];
                replaceWith = 9;
                a = a * 10 + replaceWith;
            } else if(arr[i] == digitToReplace) {
                a = a * 10 + replaceWith;
            } else {
                a = a * 10 + arr[i];
            }
        }

        digitToReplace = -1, replaceWith = -1;
        bool flag = false;
        for(int i=0; i<arr.size(); i++) {
            if(i == 0 && arr[i] == 1) {
                // skip
                flag = true;
                b = b * 10 + arr[i];
                continue;
            } else if(i == 0 && arr[i] > 1) {
                digitToReplace = arr[i];
                replaceWith = 1;
            } else if(i == 0) {
                digitToReplace = arr[i];
                replaceWith = 0;
            }
            
            if(digitToReplace == -1 && arr[i] > (flag ? 1 : 0)) {
                digitToReplace = arr[i];
                replaceWith = 0;
                b = b * 10 + replaceWith;
            } else if(arr[i] == digitToReplace) {
                b = b * 10 + replaceWith;
            } else {
                b = b * 10 + arr[i];
            }
        }

        return a - b;
    }
};