class Solution {
public:
    int smallestNumber(int n) {
        int sum=0;
        int mul=1;
        
        while(n>0){
            sum+=mul;
            mul*=2;
            
            n=n/2;
        }
        
        return sum;
    }
};