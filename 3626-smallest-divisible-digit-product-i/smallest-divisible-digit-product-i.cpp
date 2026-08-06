class Solution {
public:
    int smallestNumber(int n, int t) {
        int a=10;
        while(a--){
            int b=n;
            int pro=1;
            while(b){
                int q= b%10;
                pro = pro*q;
                b=b/10;
            }
            if(pro%t ==0) return n;
            n++;
        }
        return -1;
    }
};