class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>>cars;
        for(int i = 0 ; i<n ; i++){
            double time = (double) (target - position[i])/speed[i];
            cars.push_back({position[i] , time});
        }
        sort(cars.rbegin() , cars.rend());
        int fleets = 0;
        double max_time = 0.0;
        for(int i = 0 ; i<n ; i++){
            double time = cars[i].second;
            if(time > max_time){
                fleets++;
                max_time = time;
            }
        }
        return fleets;
    }
};
