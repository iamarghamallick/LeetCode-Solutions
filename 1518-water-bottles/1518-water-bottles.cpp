class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange)    return numBottles;
        return numExchange + numWaterBottles(numBottles - numExchange + 1, numExchange);
    }
};