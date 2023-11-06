class SeatManager {
    priority_queue<int, vector<int>, greater<int>> aval;

public:
    SeatManager(int n) {
        // Initially all seats are unreserved.
        for (int i=1; i<=n; ++i)
            aval.push(i);
    }

    int reserve() {
        // Get the smallest-numbered unreserved seat from the min heap.
        int seatNumber = aval.top();
        aval.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        // Push the unreserved seat in the min heap.
        aval.push(seatNumber);
    }
};