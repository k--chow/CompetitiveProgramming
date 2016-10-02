class Solution {
public:
    int sum = 0;
    void helper(vector<NestedInteger>& nestedList, int depth)
    {
        for(int i=0; i<nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                sum += depth * nestedList[i].getInteger();
            } else {
                helper(nestedList[i].getList(), depth + 1);
            }
        }
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        helper(nestedList, 1);
        return sum;
    }
};
