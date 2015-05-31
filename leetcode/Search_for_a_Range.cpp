class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        ret.push_back(searchMinRange(A, 0, n-1, target));
        ret.push_back(searchMaxRange(A, 0, n-1, target));
        return ret;
    }
    
    int  searchMinRange(const int A[], int begin, int end, int target){
        int minIndex = begin;
        int maxIndex = end;
        int midIndex;
        while(minIndex<maxIndex-1){
            midIndex = minIndex + (maxIndex-minIndex)/2;
            if(A[midIndex]>=target){
                maxIndex = midIndex;
            }else{
                minIndex = midIndex;
            }
        }
        if(A[minIndex] == target){
            return minIndex;
        }else if(A[maxIndex] == target){
            return maxIndex;
        }
        return -1;
    }
    
    int searchMaxRange(const int A[], int begin, int end, int target){
        int minIndex = begin;
        int maxIndex = end;
        int midIndex;
        while(minIndex<maxIndex-1){
            midIndex = minIndex + (maxIndex-minIndex)/2;
            if(A[midIndex]<=target){
                minIndex = midIndex;
            }else{
                maxIndex = midIndex;
            }
        }
        if(A[maxIndex] == target){
            return maxIndex;
        }else if(A[minIndex] == target){
            return minIndex;
        }
        return -1;
    }
};
