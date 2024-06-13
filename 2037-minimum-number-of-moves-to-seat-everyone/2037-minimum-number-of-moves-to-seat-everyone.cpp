class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for (int i = 0; i < seats.size(); i++) {
            // Add the absolute value of the difference
            // between the position of the seat and the student
            moves += abs(seats[i] - students[i]);
        }
        return moves;
    }
};