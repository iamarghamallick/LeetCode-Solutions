class Solution {
    public int longestBalanced(String s) {
        char[] c = s.toCharArray();
        int n = c.length;

        int cur_a = 0, cur_b = 0, cur_c = 0;
        int max_a = 0, max_b = 0, max_c = 0;

        for (int i = 0; i < n; i++) {
            if (c[i] == 'a') {
                cur_a = (i > 0 && c[i - 1] == 'a') ? cur_a + 1 : 1;
                max_a = Math.max(max_a, cur_a);
            } else if (c[i] == 'b') {
                cur_b = (i > 0 && c[i - 1] == 'b') ? cur_b + 1 : 1;
                max_b = Math.max(max_b, cur_b);
            } else {
                cur_c = (i > 0 && c[i - 1] == 'c') ? cur_c + 1 : 1;
                max_c = Math.max(max_c, cur_c);
            }
        }

        int res = Math.max(Math.max(max_a, max_b), max_c);

        res = Math.max(res, find2(c, 'a', 'b'));
        res = Math.max(res, find2(c, 'a', 'c'));
        res = Math.max(res, find2(c, 'b', 'c'));

        res = Math.max(res, find3(c));

        return res;
    }

    private int find2(char[] c, char x, char y) {
        int n = c.length, max_len = 0;
        int[] first = new int[2 * n + 1];
        Arrays.fill(first, -2);

        int clear_idx = -1, diff = n;
        first[diff] = -1;

        for (int i = 0; i < n; i++) {
            if (c[i] != x && c[i] != y) {
                clear_idx = i;
                diff = n;
                first[diff] = clear_idx;
            } else {
                if (c[i] == x)
                    diff++;
                else
                    diff--;

                if (first[diff] < clear_idx) {
                    first[diff] = i;
                } else {
                    max_len = Math.max(max_len, i - first[diff]);
                }
            }
        }

        return max_len;
    }

    private int find3(char[] c) {
        long state = Long.MAX_VALUE / 2;
        Map<Long, Integer> first = new HashMap<>();
        first.put(state, -1);

        int max_len = 0;

        for (int i = 0; i < c.length; i++) {
            if (c[i] == 'a')
                state += 1_000_001;
            else if (c[i] == 'b')
                state -= 1_000_000;
            else
                state--;

            if (first.containsKey(state)) {
                max_len = Math.max(max_len, i - first.get(state));
            } else {
                first.put(state, i);
            }
        }

        return max_len;
    }
}

// class Solution {
//     public int longestBalanced(String s) {
//         int n = s.length();
//         int ans = 0;

//         for(int i = 0; i < n; i++) {
//             int countA = 0, countB = 0, countC = 0;

//             for(int j = i; j < n; j++) {

//                 char ch = s.charAt(j);
//                 if(ch == 'a') countA++;
//                 else if(ch == 'b') countB++;
//                 else countC++;

//                 // Count how many characters are present
//                 int distinct = 0;
//                 if(countA > 0) distinct++;
//                 if(countB > 0) distinct++;
//                 if(countC > 0) distinct++;

//                 int len = j - i + 1;

//                 // Balanced condition:
//                 if(distinct == 1 ||
//                    (distinct == 2 && 
//                     (countA == countB || countA == countC || countB == countC)) ||
//                    (distinct == 3 && countA == countB && countB == countC)) {

//                     ans = Math.max(ans, len);
//                 }
//             }
//         }

//         return ans;
//     }
// }
