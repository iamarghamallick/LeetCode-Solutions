class Solution {
    public int numberOfBeams(String[] bank) {
        int prev = 0, ans = 0;
        
        for(String floor: bank) {
            int count = 0;
            
            for(int i=0; i<floor.length(); i++) {
                if(floor.charAt(i) == '1')
                    count++;
            }
            
            if(count != 0) {
                ans += prev * count;
                prev = count;
            }
        }
        
        return ans;
    }
}