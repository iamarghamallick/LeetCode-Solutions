class Solution {
    public List<String> readBinaryWatch(int turnedOn) {
        List<String> list = new ArrayList<>();
        for(int h=0; h<12; h++) {
            for(int m=0; m<60; m++) {
                if(Integer.bitCount(h) + Integer.bitCount(m) == turnedOn) {
                    list.add((m>=10)?(Integer.toString(h) + ":" + Integer.toString(m)):(Integer.toString(h) + ":0" + Integer.toString(m)));
                }
            }
        }
        return list;
    }
}