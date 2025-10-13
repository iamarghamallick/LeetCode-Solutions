class Solution {
    public List<String> removeAnagrams(String[] words) {
        List<String> ans = new ArrayList<>();
        String prev = "";
        for(int i=0; i<words.length; i++) {
            String word = words[i];
            char[] charArray = word.toCharArray();
            Arrays.sort(charArray);
            String curr = new String(charArray);
            if(i == 0) {
                ans.add(word);
                prev = curr;
            } else {
                if(!prev.equals(curr)) ans.add(word);
                prev = curr;
            }
        }
        return ans;
    }
}