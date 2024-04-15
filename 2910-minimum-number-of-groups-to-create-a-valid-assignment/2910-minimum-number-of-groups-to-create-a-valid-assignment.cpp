class Solution {
public:
    // This function returns minimum number of groups that can be made with each 
    // group having size either x or (x + 1)
    int findMinimumGroups(int x, unordered_map<int,int>& map) {  
        int totalGroups = 0;
        for(auto &[num, freq] : map) {
            int a = freq / (x+1); //this gives the number of groups of size equal to x+1
            int b = freq % (x+1);
            // if b == 0,then we make a groups of size x + 1 with this number.
            // So add a to the totalGroups
            if(b == 0)  totalGroups += a;
            // If b != 0 then we make a groups of size x+1 and we are left with b elements.
            // Inorder to make a group of size x we need (x-b) elements.
            // We can extract one element from each of x+1 groups and to new group to make x elements.
            // We have taken 1 element so there size would reduce to 1, we have taken (x-b) elements,
            // so out of a groups (x-b) groups size became b.
            // So no of groups with size x+1 is (a - (x-b))
            // No of groups with size x is x - b + 1.
            // Total gropus = (a-(x-b)) + (x-b+1) = a + 1
            else if((x-b) <= a) totalGroups += (a + 1);
            else return -1;
        }
        
        return totalGroups;
    }
    
    int minGroupsForValidAssignment(vector<int>& balls) {
        unordered_map<int, int> map; //map to store the frequencey of each element.
        for(auto num : balls) ++map[num]; //find frequencey of each unique number.
        int minFreq = INT_MAX; //variable for storing the number with minimum Frequency. 
        for(auto &[num,freq] : map) 
            minFreq = min(minFreq,freq);
        int minGroups = INT_MAX;
        for(int x = 1; x <= minFreq; ++x) {   
            int res = findMinimumGroups(x, map);
            if(res != -1)
                minGroups = min(minGroups,res);
        }
        
        return minGroups == INT_MAX ? -1 : minGroups;
    }
};