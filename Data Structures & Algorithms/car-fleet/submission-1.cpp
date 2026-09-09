class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars ;
        int n = position.size() ;
        for(int i=0; i<n; i++){
            cars.push_back({position[i],speed[i]}) ;
        }
        sort(cars.rbegin(),cars.rend()) ;
        vector<double> st ;
        
        for(auto& car : cars){
            double time = 1.0 * (target-car.first)/car.second ;
            st.push_back(time) ;
            if(st.size()>=2 && st.back()<=st[st.size()-2])
                st.pop_back() ;
        }

        return st.size() ;
    }
};
