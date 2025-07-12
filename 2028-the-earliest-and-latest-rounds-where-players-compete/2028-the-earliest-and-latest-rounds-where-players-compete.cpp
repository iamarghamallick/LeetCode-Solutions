class Solution {
public:
    int N, f, s;
    int mx = INT_MIN, mn = INT_MAX;

    void solve(int mask, int round, int i, int j) {
        if(i >= j) { // increment round and reset the pointer
            solve(mask, round + 1, 0, N);
        }
        else if((mask & (1 << i)) == 0) { // i-th bit is 0, move to i + 1
            solve(mask, round, i + 1, j); 
        }
        else if((mask & (1 << j)) == 0) { // j-th bit is 0, move to j - 1
            solve(mask, round, i, j - 1);
        }
        else if(i == f && j == s) { // firstPlayer & secondPlayer come head-to-head
            mx = max(mx, round);
            mn = min(mn, round);
        }
        else if(i == f || i == s) { // i wins, set the j-th bit to 0
            solve(mask ^ (1 << j), round, i + 1, j - 1);
        }
        else if(j == f || j == s) { // j wins, set the i-th bit to 0
            solve(mask ^ (1 << i), round, i + 1, j - 1);
        }
        else { // anyone can win, try with both
            solve(mask ^ (1 << j), round, i + 1, j - 1);
            solve(mask ^ (1 << i), round, i + 1, j - 1);
        }
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N = n - 1, f = firstPlayer - 1, s = secondPlayer - 1;
        solve((1 << n) - 1, 1, 0, N);
        return { mn, mx };
    }
};