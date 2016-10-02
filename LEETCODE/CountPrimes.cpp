class Solution {
public:
    int countPrimes(int n) {
        if (n == 1 || n == 2 || n == 0) return 0;
        vector<bool> b(n);
        //go up to square root of n
        for(int i=2; i<=sqrt(n); i++)
        {
            //cout << i << endl;
            if (b[i] == 0) {
                int temp = i;
                cout << temp << endl;
                for(int j=i+temp; j<=n; j+=temp) {
                    b[j] = 1;
                }
            }
        }

        return n - count(b.begin(), b.end(), 1)-2;
    }
};
