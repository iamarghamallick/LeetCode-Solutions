class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int low = 0, high = tokens.size() - 1;
        
        int score = 0;
        
        while(low <= high) {
            // when we have enough power, play lowest token face-up
            if(power >= tokens[low]) {
                score++;
                power -= tokens[low];
                low++;
            
            // else if we don't have enough power to play a token face-up
            // if there is at least one token remaining,
            // and we have enough score, play highest token face-down
            } else if(low < high && score > 0) {
                score--;
                power += tokens[high];
                high--;
                
            // else we don't have enough score, power, or tokens 
            // to play face-up or down and increase our score
            } else 
                return score;
        }
        
        return score;
    }
};