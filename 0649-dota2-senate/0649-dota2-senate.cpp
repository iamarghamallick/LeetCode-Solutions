class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;
        
        for(int i=0; i<n; i++) {
            if(senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        
        if(r.empty())   return "Dire";
        if(d.empty())   return "Radiant";
        
        while(!r.empty() && !d.empty()) {
            if(r.front() < d.front()) {
                d.pop(); // Ban R's right
                
                r.push(r.front() + n);
                r.pop();
            } else {
                r.pop(); // Ban D's right
                
                d.push(d.front() + n);
                d.pop();
            }
        }
        
        return r.empty() ? "Dire" : "Radiant";
    }
};