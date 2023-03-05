//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossibleAns(vector<int>arr, int cows, int mini){
        int n = arr.size();
        int curr = 0;
        int next = 1;
        int count = 1;      // 1st cow will be at index 0
    
        while(next<n){
            while(next<n && arr[next]-arr[curr] < mini){
                next++;
            }
            if(next<n){
                count++;
                curr = next;
                next++;
            }
            if(count==cows)
                return true;
        }
    
        return false;
    }

    int solve(int n, int cows, vector<int> &arr) {
        // Write your code here
        sort(arr.begin(), arr.end());
        int s = 0;
        int e = arr[n-1] - arr[0];
        int ans = -1;
    
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isPossibleAns(arr, cows, mid)){
                ans = mid;
                s = mid + 1;
            }
            else
                e = mid - 1;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends