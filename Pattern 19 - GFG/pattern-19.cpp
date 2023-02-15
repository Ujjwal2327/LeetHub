//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        // code here
        // upper half
        for(int i=0; i<n; i++){
            // left spaces
            for(int j=0; j<n-i; j++){
                cout<<'*';
            }
            // spaces
            for(int j=0; j<i; j++){
                cout<<"  ";
            }
            // right stars
            for(int j=0; j<n-i; j++){
                cout<<'*';                
            }   
            cout<<'\n';
        }
        
        // lower half
        for(int i=0; i<n; i++){
            // left spaces
            for(int j=0; j<i+1; j++){
                cout<<'*';
            }
            // spaces
            for(int j=0; j<n-i-1; j++){
                cout<<"  ";
            }
            // right stars
            for(int j=0; j<i+1; j++){
                cout<<'*';                
            }   
            cout<<'\n';
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends