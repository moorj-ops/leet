class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int &a: asteroids) {
           
            
            // collission happens when st - pos next neg
            while (!st.empty() && st.top() > 0 && a < 0) {
                int sum = a+st.top();
                if (sum < 0) {
                    //st ast destroyed
                    st.pop(); // stack asteroid destroyed
                }
                else if (sum>0) {//st wala bada
                    a=0;//no pop current destroy
                    //a=0 means current wala add nahi hoga
                }
                else {
                 // dono equal 
                    st.pop();//pop bhi hoga
                    a=0;//current destroy hoga
                }
            }

            
            if(a!=0){
                st.push(a);
            }
            
        }

        // Convert stack tto vector to reverse
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};