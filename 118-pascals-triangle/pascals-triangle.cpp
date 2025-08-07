class Solution {
public:
    vector<int> generaterow(int numRows){
        long long ansval=1;
        vector<int> ansrow;
        ansrow.push_back(1);
        for(int i=1;i<numRows;i++){
            ansval=ansval*(numRows-i);
            ansval=ansval/i;
            ansrow.push_back(ansval);
        }
        return ansrow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generaterow(i));
        }
        return ans;
    }
};