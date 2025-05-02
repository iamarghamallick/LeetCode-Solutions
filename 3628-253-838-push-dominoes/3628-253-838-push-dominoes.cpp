class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        vector<int> indexes(N+2);
        vector<char> symbols(N+2);
        int len = 1;
        indexes[0] = -1;
        symbols[0] = 'L';

        for (int i = 0; i < N; ++i)
            if (dominoes[i] != '.') {
                indexes[len] = i;
                symbols[len++] = dominoes[i];
            }

        indexes[len] = N;
        symbols[len++] = 'R';

        string ans = dominoes;
        for (int index = 0; index < len - 1; ++index) {
            int i = indexes[index], j = indexes[index+1];
            char x = symbols[index], y = symbols[index+1];
            char write;
            if (x == y) {
                for (int k = i+1; k < j; ++k)
                    ans[k] = x;
            } else if (x > y) { // RL
                for (int k = i+1; k < j; ++k)
                    ans[k] = k-i == j-k ? '.' : k-i < j-k ? 'R' : 'L';
            }
        }

        return ans;
    }
};