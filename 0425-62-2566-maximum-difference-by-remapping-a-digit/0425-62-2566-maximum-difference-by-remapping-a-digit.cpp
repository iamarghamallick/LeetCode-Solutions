class Solution {
public:
    int minMaxDifference(int num) {
        int maxVal = 0, minVal = 0;
        vector<int> arr;
        int temp = num;

        while(temp) {
            arr.push_back(temp % 10);
            temp /= 10;
        }

        reverse(arr.begin(), arr.end());

        int flag = -1;
        for(int i=0; i<arr.size(); i++) {
            if(flag == -1 && arr[i] < 9) {
                flag = arr[i];
                maxVal = maxVal * 10 + 9;
            } else if(arr[i] == flag) {
                maxVal = maxVal * 10 + 9;
            } else {
                maxVal = maxVal * 10 + arr[i];
            }
        }

        flag = -1;
        for(int i=0; i<arr.size(); i++) {
            if(flag == -1 && arr[i] > 0) {
                flag = arr[i];
                minVal = minVal * 10 + 0;
            } else if(arr[i] == flag) {
                minVal = minVal * 10 + 0;
            } else {
                minVal = minVal * 10 + arr[i];
            }
        }

        return maxVal - minVal;
    }
};