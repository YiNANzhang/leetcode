class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
		int m = matrix[0].size();
		int i;
		for(i = 0; i < n; ++i) {
			if(matrix[i][0] > target)
				break;
		}
		if(i==0) return false;
		int begin = 0, end = m;
		while(begin < end){
			int mid = begin + (end - begin)/2;
			if(target == matrix[i-1][mid])
				return true;
			else if(target > matrix[i-1][mid])
				begin = mid + 1;
			else 
				end = mid;
		}
		return false;
    }
};
