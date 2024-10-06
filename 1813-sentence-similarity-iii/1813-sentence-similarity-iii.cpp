class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        deque<string> dq1, dq2;
        splitSentence(s1, dq1);
        splitSentence(s2, dq2);
        
        while(!dq1.empty() && !dq2.empty() && dq1.front() == dq2.front()) {
            dq1.pop_front();
            dq2.pop_front();
        }
        while(!dq1.empty() && !dq2.empty() && dq1.back() == dq2.back()) {
            dq1.pop_back();
            dq2.pop_back();
        }
        return  dq1.empty() || dq2.empty();
    }
    
    void splitSentence(string s, deque<string> &dq) {
        string temp = "";
        int i = 0;
        do {
            if(s[i] == ' ') {
                dq.push_back(temp);
                temp = "";
            } else {
                temp += s[i];
            }
            i++;
        } while(i < s.size());
        
        dq.push_back(temp);
    }
};