class Solution {
public:
    int length;
    vector<string> store;
    vector<string> ans;
    void recurse(int index, string current) {
        if (index == length) {
            ans.push_back(current);
            cout << current << endl;
            return;
        }

        for(int i=0; i<store[index].length(); i++)
        {
            recurse(index + 1, current + store[index][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        length = digits.size();
        if (length == 0) return ans;
        map<char, string> mappy;
        mappy['2'] = "abc";
        mappy['3'] = "def";
        mappy['4'] = "ghi";
        mappy['5'] = "jkl";
        mappy['6'] = "mno";
        mappy['7'] = "pqrs";
        mappy['8'] = "tuv";
        mappy['9'] = "wxyz";

        for(int i=0; i<digits.size(); i++)
        {
            char c = digits[i];
            store.push_back(mappy[c]);
        }
        //cout << mappy[2] << endl;
        string current = "";
        recurse(0, current);
        return ans;

    }
};
