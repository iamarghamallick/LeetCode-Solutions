class Solution {
    public List<Integer> findSubstring(String s, String[] words) {

        List<Integer> ans = new ArrayList<>();

        int k = words[0].length();
        int wordCount = words.length;
        int totalLength = k * wordCount;

        if (s.length() < totalLength) {
            return ans;
        }

        HashMap<String, Integer> freq = new HashMap<>();

        for (String word : words) {
            freq.put(word, freq.getOrDefault(word, 0) + 1);
        }

        // Try each possible offset
        for (int offset = 0; offset < k; offset++) {

            int left = offset;
            int right = offset;
            int count = 0;

            HashMap<String, Integer> window = new HashMap<>();

            while (right + k <= s.length()) {

                String word = s.substring(right, right + k);
                right += k;

                // Word doesn't exist in words
                if (!freq.containsKey(word)) {
                    window.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                // Add word to current window
                window.put(word, window.getOrDefault(word, 0) + 1);
                count++;

                // Too many occurrences of this word
                while (window.get(word) > freq.get(word)) {

                    String leftWord = s.substring(left, left + k);
                    window.put(leftWord, window.get(leftWord) - 1);

                    left += k;
                    count--;
                }

                // We have exactly all words
                if (count == wordCount) {
                    ans.add(left);

                    // Move window forward by one word
                    String leftWord = s.substring(left, left + k);
                    window.put(leftWord, window.get(leftWord) - 1);

                    left += k;
                    count--;
                }
            }
        }

        return ans;
    }
}