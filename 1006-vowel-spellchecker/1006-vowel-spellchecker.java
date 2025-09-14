class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' ||
               c == 'o' || c == 'u';
    }

    private String checkVowels(String[] wordList, String query) {
        String qry = query.toLowerCase();
        char[] q = qry.toCharArray();
        for(String word : wordList) {
            String wrd = word.toLowerCase();
            char[] w = wrd.toCharArray();
            if(q.length != w.length) continue;
            for(int i=0; i<q.length; i++) {
                if((q[i] == w[i]) || (isVowel(q[i]) && isVowel(w[i]))) {
                    if(i == q.length - 1) return word;
                } else break;
            }
        }
        return "";
    }

    private String checkCapita(String[] wordList, String query) {
        String q = query.toLowerCase();
        for(String word : wordList) {
            String w = word.toLowerCase();
            if(w.equals(q)) return word;
        }
        return "";
    }

    public String[] spellchecker(String[] wordlist, String[] queries) {
        // TLE
        // ArrayList<String> str = new ArrayList<>();
        // for(String query : queries) {
        //     if(Arrays.asList(wordlist).contains(query) == true) {
        //         // check 1: exact match
        //         str.add(query);
        //     } else {
        //         // check 2: capitalization
        //         String res = checkCapita(wordlist, query);
        //         if(res != "") str.add(res);
        //         else {
        //             // check 3: vowel errors
        //             res = checkVowels(wordlist, query);
        //             str.add(res);
        //         }
        //     }
        // }
        // return str.toArray(new String[str.size()]);

        ArrayList<String> str = new ArrayList<>();
        HashSet<String> orgSet = new HashSet<>();
        HashMap<String, String> capitaMap = new HashMap<>();
        HashMap<String, String> vowelMap = new HashMap<>();

        for(String word : wordlist) {
            orgSet.add(word);

            String w = word.toLowerCase();
            if(!capitaMap.containsKey(w)) capitaMap.put(w, word);

            char[] arr = w.toCharArray();
            String s = "";
            for(char c : arr) {
                if(isVowel(c)) s += '#';
                else s += Character.toLowerCase(c);
            }
            if(!vowelMap.containsKey(s)) vowelMap.put(s, word);
        }

        for(String query : queries) {
            String q = query.toLowerCase();
            if(orgSet.contains(query)) { // exact match
                str.add(query);
            } else if(capitaMap.containsKey(q)) { // capitalization
                str.add(capitaMap.get(q));
            } else { // vowel errors or else 
                String s = "";
                char[] arr = q.toCharArray();
                for(char c : arr) {
                    if(isVowel(c)) s += '#';
                    else s += Character.toLowerCase(c);
                }
                if (vowelMap.containsKey(s)) str.add(vowelMap.get(s));
                else str.add("");
            }
        }
        return str.toArray(new String[str.size()]);
    }
}