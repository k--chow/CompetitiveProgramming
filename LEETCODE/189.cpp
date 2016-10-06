class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();//7
        k = k % n;
        int i = 0;
        int tempA, tempB = nums[i];
        while (1) {
            tempA = tempB;
            i = (i + k) % n;
            tempB = nums[i];
            nums[i] = tempA;
            if (i == 0) break;
        }
    }
};
