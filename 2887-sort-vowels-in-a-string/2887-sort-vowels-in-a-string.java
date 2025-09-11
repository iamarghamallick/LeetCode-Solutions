class Solution {
    private boolean isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        
        return false;
    }

    public String sortVowels(String s) {
        char[] arr = s.toCharArray();
        ArrayList<Character> vowels = new ArrayList<>();

        for(char c : arr) {
            if(isVowel(c)) {
                vowels.add(c);
            }
        }

        Collections.sort(vowels);
        int index = 0;

        for(int i=0; i<arr.length; i++) {
            if(isVowel(arr[i])) {
                arr[i] = vowels.get(index);
                index++;
            }
        }

        return new String(arr);
    }
}