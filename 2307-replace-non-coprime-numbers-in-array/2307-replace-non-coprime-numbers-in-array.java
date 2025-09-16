class Solution {
    private int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public List<Integer> replaceNonCoprimes(int[] nums) {
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        Stack<Integer> st = new Stack<>();
        st.push(nums[0]);
        
        for(int i=1; i<n; i++) {
            int cur = nums[i];
            while (!st.isEmpty()) {
                int gcd = findGCD(st.peek(), cur);
                if (gcd == 1) break;  // coprime, stop merging
                cur = (int)((long)st.peek() * cur / gcd); // lcm
                st.pop();
            }
            st.push(cur);
        }

        while(!st.isEmpty()) {
            ans.add(st.peek());
            st.pop();
        }

        Collections.reverse(ans);

        return ans;
    }
}