class Solution {
public:
    int trap(vector<int>& height) {
        int mxl[height.size()];
        int mxr[height.size()];
        
        mxl[0] = height[0];
        mxr[height.size()-1] = height[height.size()-1];
        
        for(int i=1; i<height.size(); i++)
            mxl[i] = max(mxl[i-1], height[i]);
        for(int i=height.size()-2; i>=0; i--)
            mxr[i] = max(mxr[i+1], height[i]);
        
        int water[height.size()];
        int mx=0;
        
        for(int i=0; i<height.size(); i++) {
            water[i] = min(mxl[i], mxr[i]) - height[i];
            
        }
        for(int i=0; i<height.size(); i++) {
            water[i] = min(mxl[i], mxr[i]) - height[i];
            mx += water[i];
        }
        
        return mx;
    }
};