class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0;
        int carry = 0;
        int exchange = 0;
        while(numBottles + carry >= numExchange) {
            drink += numBottles;
            exchange = (numBottles + carry) / numExchange;
            carry = (numBottles + carry) % numExchange;
            numBottles = exchange;
        }
        return drink + numBottles;
    }
}