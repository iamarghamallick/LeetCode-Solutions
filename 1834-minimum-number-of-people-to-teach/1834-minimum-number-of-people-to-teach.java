class Solution {
    private int countCommonLanguages(int[] language1, int[] language2) {
        int count = 0;
        for (int i = 0; i < language1.length; i++) {
            for (int j = 0; j < language2.length; j++) {
                if (language1[i] == language2[j]) {
                    count++;
                }
            }
        }
        return count;
    }

    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        HashSet<Integer> sadUsers = new HashSet<>();

        // Identify sad users (who cannot communicate with friends)
        for (int[] f : friendships) {
            int u = f[0], v = f[1];
            if (countCommonLanguages(languages[u - 1], languages[v - 1]) == 0) {
                sadUsers.add(u);
                sadUsers.add(v);
            }
        }

        // Count which language is most common among sad users
        HashMap<Integer, Integer> langMap = new HashMap<>();
        int mostPopularLang = 0;

        for (int sadUser : sadUsers) {
            for (int lang : languages[sadUser - 1]) {
                langMap.put(lang, langMap.getOrDefault(lang, 0) + 1);
                mostPopularLang = Math.max(mostPopularLang, langMap.get(lang));
            }
        }

        // Teach the rest
        return sadUsers.size() - mostPopularLang;
    }
}