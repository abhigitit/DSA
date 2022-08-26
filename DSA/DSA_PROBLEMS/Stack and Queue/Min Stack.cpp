/*

Leetcode: 155

TC:O(1)
SC:O(n)

Intution : Maintain another stack and keep adding the current minimum value each time we add an element to the main stack.

*/

class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
       if(!min_st.empty())
       {
           int into_min = min(val,min_st.top());
           min_st.push(into_min);
       }
        else
   
           min_st.push(val);  
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
