class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunk = numBottles;
        int empty = numBottles;
        int full = 0;
        while(empty + full >= numExchange) {
            drunk += full;
            empty += full;
            full = 1;
            empty -= numExchange;
            numExchange++;
        }
        return drunk + full;
    }
}