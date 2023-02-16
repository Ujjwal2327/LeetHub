//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        // val, freq
        map<int,int, greater<int>>freq;
        for(auto val:nums){
            freq[val]++;
        }
        
        // freq, val
        multimap<int,int, greater<int>> values;
        for(auto it=freq.begin(); it!=freq.end(); it++){
            values.insert({it->second, it->first});
        }
        
        vector<int>ans;
        int i=0;
        for(auto it = values.begin(); it!=values.end(); it++){
            if(i<k){
                ans.push_back(it->second);
                i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends