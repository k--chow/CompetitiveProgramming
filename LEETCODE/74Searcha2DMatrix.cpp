class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) {
            return false;
        }
        int r = matrix.size();
        int c = matrix[0].size();
        int lo = 0, hi = r*c, mid;
        int row = 0;
        int col = 0;
        mid = (lo+hi)/2;

        while (lo <= hi)
        {

            mid = (lo+hi)/2;
            row = 0;
            col = 0;
            if (mid != 0) {
                row = (mid-1)/c;
                col = (mid-1)%c;
            }
            cout << row << " " << col << " " << matrix[row][col] << " " << mid << endl;
            if (matrix[row][col] > target) {
                hi = mid-1;
            } else if (matrix[row][col] < target) {
                lo = mid+1;
            } else if (matrix[row][col] == target) {
                return true;
            } else if (lo == hi && matrix[row][col] != target) {
                return false;
            }
        }

        return false;
    }
};
