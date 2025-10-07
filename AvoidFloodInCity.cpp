//Leetcode 1488. Avoid Flood in The City

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> full_lakes; 
        set<int> dry_days; 

        for (int i = 0; i < n; i++) {
            int lake = rains[i];

            if (lake > 0) { 
                ans[i] = -1;
                if (full_lakes.count(lake)) {
                    int prev_rain_day = full_lakes[lake];
                    //we search for the dry days justt above the prev_rain_day, cause we can't fill a empty thing from before that
                    auto it = dry_days.upper_bound(prev_rain_day);
                    if (it == dry_days.end()) {
                        return {};
                    }
                    int day_to_use = *it;
                    ans[day_to_use] = lake; 
                    dry_days.erase(it);     
                }
                
                full_lakes[lake] = i;

            } else {
                dry_days.insert(i); 
            }
        }
        return ans;
    }
};
