class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        s = "0" + s;
        int count[s.length()];
        int ans = 0;
        map<char, int> mappy;//letter and last index
        memset(count, 0, sizeof(count));
        //base case
        count[0] = 0;
        for(int i=1; i<s.length(); i++)
        {
            //check each character before current
            char current = s[i];
            bool contains = false;
            for (int j = i-1; j >= (i - count[i-1]); j--)
            {
                //check if contains current in the previous
                if (s[j] == current)
                {
                    count[i] = (i-1 - j) + 1;
                    contains = true;
                    break;
                }
            }
            if (!contains) count[i] = count[i-1] + 1;
            ans = max(ans, count[i]);
            //if not, add previous + 1
        }
        return ans;
        
    }
};