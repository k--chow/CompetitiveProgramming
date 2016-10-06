class Solution {
public:
    bool canPermutePalindrome(string s) {
        //#keys should be one
        unordered_map<char, bool> exist;
        for(int i=0; i<s.size(); i++)
        {
            char c = s[i];
            if (exist.count(c)) {
                exist.erase(c);
            } else {
                exist[c] = true;
            }
        }
        if (exist.size() <= 1) return true;
        return false;
    }
};
