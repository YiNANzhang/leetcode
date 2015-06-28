class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long area;
		area = (long long)(C-A)*(long long)(D-B) + (long long)(G-E)*(long long)(H-F);
		if(A >= G || E >=C || F >= D || B >= G)
			return area;
		else {
			area -= (long long)(min(D, H) - max(F, B)) * (long long)(min(C, G) - max(A, E));
		}
		return area;
        
    }
};
