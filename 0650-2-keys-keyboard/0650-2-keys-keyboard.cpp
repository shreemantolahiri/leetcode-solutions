class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1)
            return false;
        if (n == 2 || n == 3)
            return true;
        if (n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }

    int minSteps(int n) {
        if (n == 1)
            return 0;
        else if(isPrime(n)) return n;

        for(int i=n/2;i>=1;i--){
            if(n%i==0 && isPrime(i)){
                return i+minSteps(n/i);
            }
        }

        return n;
        
    }
};