class Stack {
    queue<int> q;
    //queue<int> &q;
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if (q.empty()) return;
        int size = q.size();
        for (int i = 0; i < size-1; ++i) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }

    // Get the top element.
    int top() {
        //if (q.empty()) return ;
        return q.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }
};
