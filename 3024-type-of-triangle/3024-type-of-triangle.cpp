class Solution {
public:
    string triangleType(vector<int>& a) {
        if(a[0] + a[1] > a[2] && a[1] + a[2] > a[0] && a[2] + a[0] > a[1]) {
            // it is a triangle
            if(a[0] == a[1] && a[1] == a[2])
                return "equilateral";
            
            if(a[0] == a[1] || a[1] == a[2] || a[2] == a[0])
                return "isosceles";
            
            return "scalene";
        }
        
        // not a triangle, so
        return "none";
    }
};