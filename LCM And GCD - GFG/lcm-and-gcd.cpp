//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long prod = A*B;
        long long hcf = 1;
        vector<long long>ans;
        if(A==0){
            ans.push_back(0);
            ans.push_back(B);
            return ans;
        }
        else if(B==0){
            ans.push_back(0);
            ans.push_back(A);
            return ans;
        }
        while(A!=B){
            if(A<B)
                swap(A,B);  // A will always be maximum of two
            if(A%B==0){
                hcf = B;
                break;
            }
            else{
                A = A%B;
            }
        }
        long long lcm = prod;
        lcm = prod/hcf;

        ans.push_back(lcm);
        ans.push_back(hcf);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends