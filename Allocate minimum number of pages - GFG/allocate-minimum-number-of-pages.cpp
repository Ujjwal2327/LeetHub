//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool possibleAns(int arr[], int n, int num, int maxi){
        int i=0;
        
        while(i<n && num--){
            int curr = 0;
            while(i<n && curr+arr[i] <= maxi){
                curr += arr[i];
                i++;
            }
        }
    
        if(i==n && num>=0)
            return true;
        else
            return false;
    }


    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int num) 
    {
        //code here
        if(num>n)
            return -1;
    
        int s = 0;
        int e = accumulate(arr, arr+n, 0);
    
        int ans = 0;
        while(s<=e){
            // mid refers to maximum number of pages i can allocate (assumed ans)
            int mid = s + (e-s)/2;
    
            if(possibleAns(arr, n, num, mid)){
                ans = mid;
                e = mid - 1;        // to minimize the ans
            }
            else
                s = mid + 1;        // if mid is not a possible ans, pages lesser than mid cant too
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends