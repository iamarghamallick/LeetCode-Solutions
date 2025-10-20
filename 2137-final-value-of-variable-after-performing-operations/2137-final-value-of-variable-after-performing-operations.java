class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int x = 0;
        for(String operation: operations) {
            char op = operation.charAt(1);
            if(op == '+') x++;
            else x--;
        }
        return x;
    }
}