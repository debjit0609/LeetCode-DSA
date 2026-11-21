class Solution {
public:
    int maxArea(vector<int>& height) {
    int mw = 0;
    int left =0, right = height.size()-1;
    while(left<right){
        int width = right - left;
        int ht = min(height[left], height[right]);
        int area = width * ht;
        if(height[left] < height[right]){
            left ++;
        }else{
            right --;
        }
        mw = max(area, mw);
    }
    return mw;
    }
};