class Solution {
    public int longestBalanced(String s) {
        int ans = 0;

        for(int i=0; i<s.length(); i++) {
            int[] arr = new int[26];
            for(int j=i; j<s.length(); j++) {
                int freq = ++arr[s.charAt(j) - 'a'];
                
                boolean balanced = true;
                for(int k=0; k<26; k++) {
                    if(arr[k] > 0 && arr[k] != freq) {
                        balanced = false;
                        break;
                    }
                }

                if(balanced)
                    ans = Math.max(ans, j - i + 1);
            }
        }

        return ans;
    }
}