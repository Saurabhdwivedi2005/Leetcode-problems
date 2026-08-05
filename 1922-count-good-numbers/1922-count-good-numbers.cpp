class Solution {
public:
    const int M=1e9 + 7;
    int solve(long x,long n){
        if(n==0){
            return 1;
        }
        long long half=solve(x,n/2);
        long long res=(half*half)%M;
        if(n%2==1){
            res=(res*x)%M;
        }
        return res;
    
        
    }
    int countGoodNumbers(long long n) {
        return (long long )solve(5,(n+1)/2)*solve(4,n/2)%M;
    }
};