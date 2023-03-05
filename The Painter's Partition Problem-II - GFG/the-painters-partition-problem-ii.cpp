//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool possibleAns(int arr[], int n, int num, long long maxi){
        int i=0;
        while(i<n && num--){
            int curr = 0;
            while(i<n && curr+arr[i] <= maxi){
                curr +=arr[i];
                i++;
            }
        }
    
        if(i==n)
            return true;
        else
            return false;
    }

 
    long long minTime(int arr[], int n, int num)
    {
        // code here
        // return minimum time
        long long s = 0;
        long long e = 0;
        e = accumulate(arr, arr+n, e);
        long long ans = -1;
        
        while(s<=e){
            long long mid = s + (e-s)/2;
    
            if(possibleAns(arr, n, num, mid)){
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends