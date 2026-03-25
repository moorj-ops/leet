class Solution {
public:
    string removeOuterParentheses(string s) {
      int depth=0;
      string str="";
      for( char ch : s){
        if ( ch=='('){
            if (depth>0){
                str+=ch;
            
            }
            depth ++;
        }
        else if(ch==')'){
            depth--;
            if(depth>0){
                str+=ch;
            }
        }
      } 
      return str; 
    }
};