/*
 Design Browser History
 
 Two stacks. Second stack to keep track when we go back and want to go forward again. Empty second stack when we visit new because older history should be deleted.
 https://www.youtube.com/watch?v=-a3np7BO2zY&t=348s
 */

class BrowserHistory {
public:
    stack<string> st1;
    stack<string> st2;
    BrowserHistory(string homepage) {
        while(!st1.empty()) st1.pop();
        while(!st2.empty()) st2.pop();
        st1.push(homepage);
    }
    
    void visit(string url) {
        st1.push(url);
        while(!st2.empty())
        {
            st2.pop();
        }
    }
    
    string back(int steps) {
        while(st1.size()>1 and steps--)
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        return st1.empty() ? st2.top() : st1.top();
    }
    
    string forward(int steps) {
        while(!st2.empty() and steps--)
        {
            st1.push(st2.top());
            st2.pop();            
        }
        return st1.top();
    }
};
