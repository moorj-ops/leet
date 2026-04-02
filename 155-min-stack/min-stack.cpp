

// Class to implement Minimum Stack
class MinStack {
private:
    // Initialize a stack
    stack <pair<int,int>> st;
    
public:
    
    // Empty Constructor
    MinStack() {
    }
    
    // Method to push a value in stack
    void push(int value) {
        
        // If stack is empty
        if(st.empty()) {
            
            // Push current value as minimum
            st.push( {value, value} );
            return;
        }
        //if not empty
        // Update the current minimum 
        int mini = min(getMin(), value);//here get min give the prev min value and we will compare teh 2 val - curr val and prev min 
        
        // Add the pair to the stack
        st.push({value, mini});
    }
    
    // Method to pop a value from stack
    void pop() {
        // Using in-built pop method
        st.pop(); 
    }
    
    // Method to get the top of stack
    int top() {
        // Return the top value
        return st.top().first;
    }
    
    // Method to get the minimum in stack
    int getMin() {
        // Return the minimum
        return st.top().second;
    }
};



/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */