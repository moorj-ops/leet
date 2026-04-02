#include<queue>
class MyStack{
public:
    queue<int> q1, q2;

    void push(int x) {
        // Step 1: Push into q2
        q2.push(x);

        // Step 2: Move all elements from q1 to q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        if(!q1.empty()) {
            int val=q1.front();
            q1.pop();
            return val;
        }
        return -1;
        
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }

};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */