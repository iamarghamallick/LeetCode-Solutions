class Solution {
public:
    int compress(vector<char>& chars) {
        int prev = chars[0];
        int count = 1;
        int i = 1;
        while(i < chars.size()) {
            if(chars[i] == prev) {
                count++;
                chars.erase(chars.begin() + i);
            } else {
                if(count >= 2) {
                    int idx = i;
                    while(count > 0) {
                        chars.insert(chars.begin() + idx, (count % 10) + '0');
                        i++;
                        count /= 10;
                    }
                }
                prev = chars[i];
                count = 1;
                i++;
            }
        }
        
        if(count >= 2) {
            while(count > 0) {
                chars.insert(chars.begin() + i, (count % 10) + '0');
                count /= 10;
            }
        }
        
        return chars.size();
    }
};