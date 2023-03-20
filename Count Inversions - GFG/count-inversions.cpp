//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[], long long s, long long e){
        long long mid = s + (e-s)/2;
        long long ans = 0;
        long long len1 = mid - s + 1;
        long long len2 = e - mid;
    
        vector<long long>left(len1);
        vector<long long>right(len2);
    
        long long i=0, j=0, k=s;
        for(; i<len1; i++)
            left[i] = arr[k++];
        
        for(; j<len2; j++)
            right[j] = arr[k++];
    
        i=0, j=0, k=s;
    
        while(i<len1 && j<len2){
            if(left[i]<=right[j])
                arr[k++] = left[i++];
            else{
                arr[k++] = right[j++];
                ans += len1 - i;
            }
        }
    
        while(i<len1)
            arr[k++] = left[i++];
        
        while(j<len2)
            arr[k++] = right[j++];
        
        return ans;
    }
    
    long long inversionCount(long long arr[], long long s, long long e){
        if(s>=e)
            return 0;
        
        long long mid = s + (e-s)/2;
        long long ans1 = inversionCount(arr, s, mid);
        long long ans2 = inversionCount(arr, mid+1, e);
    
        long long ans3 = merge(arr, s, e);
    
        return ans1 + ans2 + ans3;
    
    }
    
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long s = 0, e = N-1;
        long long ans = inversionCount(arr, s, e);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends