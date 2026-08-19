class Solution {
    public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
        HashMap<Integer, HashSet<Integer>> map = new HashMap<>();

        for (int[] seat : reservedSeats) {
            map.computeIfAbsent(seat[0], k -> new HashSet<>()).add(seat[1]);
        }

        int ans = (n - map.size()) * 2;

        for (HashSet<Integer> reserved : map.values()) {
            boolean left = true;
            boolean middle = true;
            boolean right = true;

            for (int seat = 2; seat <= 5; seat++) {
                if (reserved.contains(seat)) {
                    left = false;
                    break;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (reserved.contains(seat)) {
                    middle = false;
                    break;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (reserved.contains(seat)) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                ans += 2;
            } else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
}