class MinStack {
    int minStackIndex;
    vector<int> minValVector; 
    vector<int> Stack;
    int StackTop;
public:
    MinStack() {
        StackTop = -1;
        minStackIndex = -1;
    }
    void push(int x) {
        StackTop++;
        Stack.push_back(x);
        if(x<getMin()){
            minValVector.push_back(minStackIndex);
            minStackIndex = StackTop;
        }else{
            minValVector.push_back(-1);
        }
    }

    void pop() {
        if(Stack.empty());
        else{
            if(StackTop == minStackIndex){
                minStackIndex = minValVector[StackTop];
            }
            StackTop--;
            Stack.pop_back();
            minValVector.pop_back();
        }
    }

    int top() {
        if(!Stack.empty())
            return Stack.back();
        return INT_MIN;
    }

    int getMin() {
        if(minStackIndex>=0)
            return Stack[minStackIndex];
        return INT_MAX;
    }
};
