class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n/2; i++)
        {
            for(int j=0; j< (n-1-(2*i)); j++)
            {
                int temp = matrix[i][i+j];
                matrix[i][i+j] = matrix[n-1-i-j][i];
                matrix[n-1-i-j][i] = matrix[n-1-i][n-1-i-j];;
                matrix[n-1-i][n-1-i-j] = matrix[i+j][n-1-i];
                matrix[i+j][n-1-i] = temp;
            }
        }
    }
};
