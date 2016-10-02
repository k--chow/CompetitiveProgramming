class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> check;
        while (1) {
            //int to string
            string temp = to_string(n);
            n = 0;
            //int to char
            for(int i=0; i<temp.size(); i++) {
                n+= pow(temp[i] - '0', 2);
            }
            //if equals 1, yay
            if (n == 1) {
                return true;
            }
            //check if in map, if is, false
            if (check.count(n) == 1) {
                return false;
            }
            //add to map
            check[n] = true;
        }
        return false;
    }
};
