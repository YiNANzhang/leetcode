class Solution {
public:
    int majorityElement(vector<int> &num) {
        vector<pair<int,int> > ir;
		int n = num.size();
//		int max_num=0;
//		int freq = 0;
		int j=0;
		if(n==1)
		    return num[0];
		for(int i=0;i<n;i++){
			if(ir.size()>n/2+1)
				return 0;
			for(j=0;j<ir.size();j++){
				if(ir[j].second>n/2 || (num[i]==ir[j].first && ir[j].second == n/2))
					return ir[j].first;
				if(num[i]==ir[j].first){
					ir[j].second++;
					break;
				}
			}
			if(j>=ir.size())
				ir.push_back(make_pair(num[i],1));
		}
//		for(i = 0;i<ir.size();i++){
//			max_num = (freq<ir[i].second)&&(ir[i].second>n/2)?ir[i].first:max_num;
//		}
		return 0;
    }
};
