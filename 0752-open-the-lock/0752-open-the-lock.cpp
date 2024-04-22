class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> nextSlot = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };
        unordered_map<char, char> prevSlot = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
        
        // Hash set to store visited and dead-end combinations.
        unordered_set<string> visited(deadends.begin(), deadends.end());
        
        // BFS
        queue<string> q;
        
        int count = 0; // answer
        
        // If the starting combination is itself a dead-end, 
        // then we can't move from the starting combination.
        if(visited.find("0000") != visited.end())
            return -1;
        
        // Otherwise start the BFS with start "0000"
        q.push("0000");
        visited.insert("0000");
        
        while(!q.empty()) {
            // explore
            for(int i=q.size(); i>0; i--) {
                string curr = q.front(); q.pop();
                
                // if we reached to the target
                if(curr == target)
                    return count;
                
                // Otherwise explore all possible new combinations
                // by turning each wheel in both directions.
                for(int j=0; j<4; j++) {
                    // generate new combination
                    // by turning wheel to the next-slot
                    string newComb = curr;
                    newComb[j] = nextSlot[newComb[j]];
                    
                    // if the new combination is not a dead-end
                    // and not visited befour
                    if(visited.find(newComb) == visited.end()) {
                        // add it to the queue
                        // and mark as visited
                        q.push(newComb);
                        visited.insert(newComb);
                    }
                    
                    // Again,
                    // generate new combination
                    // by turning wheel to the prev-slot
                    newComb = curr;
                    newComb[j] = prevSlot[newComb[j]];
                    
                    // if the new combination is not a dead-end
                    // and not visited befour
                    if(visited.find(newComb) == visited.end()) {
                        // add it to the queue
                        // and mark as visited
                        q.push(newComb);
                        visited.insert(newComb);
                    }
                }
            }
            // will visit the next level of combinations
            count++;
        }
        // we never reached the target combination.
        return -1;
    }
};