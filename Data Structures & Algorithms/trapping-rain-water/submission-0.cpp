class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int lMax = height[left];
        int rMax = height[right];

        int total = 0;
        int trap = 0;

        while(left < right){
            if(height[left] < height[right]){
                lMax = max(lMax , height[left]);
                if(lMax - height[left] > 0){
                    total = total + (lMax - height[left]);
                }
                left++;
            }
            else{
                rMax = max(rMax , height[right]);
                if(rMax - height[right] > 0){
                    total = total + (rMax - height[right]);
                }
                right--;
            }
        }
        return total;
    }
};
