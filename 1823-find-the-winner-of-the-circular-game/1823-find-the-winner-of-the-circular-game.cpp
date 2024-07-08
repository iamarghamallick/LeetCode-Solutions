class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n);
        for(int i=0; i<n; i++)  arr[i] = i+1;
        int start = 0;
        while(arr.size() > 1) {
            int remove = (start + k - 1) % arr.size();
            arr.erase(arr.begin() + remove);
            start = remove;
        }
        
        return arr.front();
    }
};