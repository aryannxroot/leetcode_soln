class Solution {
private:
    int findMins(string &time){
        int hr = stoi(time.substr(0,2));
        int mins = stoi(time.substr(3,2));
        return hr*60 + mins;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int>all_min;
        int min_m = INT_MAX;
        for(string s : timePoints){
            all_min.push_back(findMins(s));
        }

        sort(all_min.begin(),all_min.end());

        for(int i = 1;i<n;i++)
        {
            min_m = min(min_m, all_min[i] - all_min[i-1]);
        }
        
        int cir_diff = 1440 - all_min.back() + all_min.front();

        min_m = min(min_m, cir_diff);
        return min_m;
    }
};