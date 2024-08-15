class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5 = 0, bill10 = 0, bill20 = 0;
        for(int i=0; i<bills.size(); i++) {
            int toReturn = 0;
            if(bills[i] == 5) {
                bill5++;
            } else if(bills[i] == 10) {
                bill10++;
                toReturn = 5;
                if(bill5 > 0) {
                    bill5--;
                } else {
                    return false;
                }
            } else {
                bill20++;
                toReturn = 15;
                if(bill10 > 0 && bill5 > 0) {
                    bill10--;
                    bill5--;
                } else if(bill5 >= 3) {
                    bill5 -= 3;
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};