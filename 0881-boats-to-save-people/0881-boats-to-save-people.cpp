class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end());
        int count = 0;
        int i = 0, j = n-1;
        
        while(i <= j) {
            if(people[i] + people[j] <= limit) {
                // we can take both people together in one boat
                count++;
                i++;
                j--;
            } else {
                // only one (j-th) people can be taken
                count++;
                j--;
            }
        }
        
        return count;
    }
};