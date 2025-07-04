class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k = k - ((long long)1 << t);
            if (operations[t]) {
                ans++;
            }
        }
        return 'a' + (ans % 26);

        // TLE
        // string s = "a";
        // int opIdx = 0;
        // while(s.size() < k) {
        //     if(operations[opIdx] == 0) 
        //         s += s;
        //     else {
        //         string temp = "";
        //         for(long long i=0; i < min((long long)s.size(), k - (long long)s.size()); i++) {
        //             temp += char((s[i] - 'a' + 1) + 97);
        //         }
        //         s += temp;
        //     }

        //     opIdx++;
        // }

        // return s[k-1];
    }
};