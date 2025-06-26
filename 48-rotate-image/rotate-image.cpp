class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       //transpose of the given matrix
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //reverse the elemests of each row
        for(int i=0;i<n;i++){
        
            int start=0;
            int end=matrix.size()-1;
            
                while(start<end){
                swap(matrix[i][start],matrix[i][end]);
                
                start++;
                end--;
            }
        
        
        }
        
       
    
    
    
    }
};