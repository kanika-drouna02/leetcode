class Solution {
public:
    int minSensors(int n, int m, int k) {
        if(n<= 2*k && m<=2*k) return 1;
        int side = 2*k+1;
        long long r= (n+side-1)/side;
        long long c= (m+side-1)/side;
        return (int)r*c;
    }
};