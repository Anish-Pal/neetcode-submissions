class Solution {
public:
    long long totalhrs(vector<int>& v , int hourly){
    long long totalhrs = 0; 
    for(int bananas : v){
        totalhrs += (bananas + (long long)hourly - 1) / hourly;
    }
     return totalhrs;
  }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        int high = *max_element(piles.begin() , piles.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totlhrs = totalhrs(piles , mid);
            if(totlhrs <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};