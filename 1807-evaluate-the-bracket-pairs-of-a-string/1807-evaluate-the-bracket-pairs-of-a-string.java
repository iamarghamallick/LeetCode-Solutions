class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        HashMap<String, String> map = new HashMap<>();

        for (List<String> pair : knowledge) {
            map.put(pair.get(0), pair.get(1));
        }

        StringBuilder ans = new StringBuilder();
        int n = s.length();
        int i = 0;

        while (i < n) {
            char ch = s.charAt(i);
            StringBuilder temp = new StringBuilder();
            if (ch == '(') {
                i++;
                while (s.charAt(i) != ')') {
                    temp.append(s.charAt(i));
                    i++;
                }
                ans.append(map.getOrDefault(temp.toString(), "?"));
            } else {
                ans.append(ch);
            }
            i++;
        }

        return ans.toString();
    }
}