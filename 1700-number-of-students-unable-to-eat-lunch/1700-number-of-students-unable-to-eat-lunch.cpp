class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        
        while(true) {
            int before = students.size();
            
            for(int student = 0; student < students.size(); student++) {
                if(students[student] == sandwiches[0]) {
                    sandwiches.erase(sandwiches.begin());
                    students.erase(students.begin() + student);
                    student--;
                }
            }
            
            int after = students.size();
            
            if(before == after)
                break;
        }
        
        return students.size();
    }
};