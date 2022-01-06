/*#include<bits/stdc++.h>
using namespace std;                //you can

bool isPossible(int stalls[],int n, int k, int mid) {
    
    int cowCount = 1;
    int lastPos = stalls[0];
    
    for(int i=0; i<n; i++ ){
        
        if(stalls[i]-lastPos >= mid){
            cowCount++;
            if(cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(int stalls[],int n, int k)
{
  // sort(stalls.begin(), stalls.end());    1 5 6 9
      sort(stalls,stalls+n);
   	int s = 0;
    int maxi = -1;
    for(int i=0; i<n; i++) {
        maxi = max(maxi, stalls[i]);        //9
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e-s)/2;
    
    while(s<=e) {
        if(isPossible(stalls ,n, k, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int main()
{
	int n;
	cin>>n;
	
	int stalls[1000];
	for(int i=0;i<n;i++)
	{
		cin>>stalls[i];
	}
	
	int k;
	cin>>k;
	int mid;
	isPossible(stalls,n,k,mid);
	
	cout<<aggressiveCows(stalls,n,k);
	
	return 0;
}
*/

#include<bits/stdc++.h>

using namespace std;

bool isPossible(int arr[],int n,int k,int mid)
{
	int cowCount=1;
	int ps=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]-ps>=mid)
		{
			cowCount++;
			
			if(cowCount==k)
			{
				return true;
			}
			ps=arr[i];
		}
	}
	return false;
}

int agressiveCow(int arr[],int n,int k)
{
	sort(arr,arr+n);
	int s=0;
	int maxi=-1;
	
	for(int i=0;i<n;i++)
	{
		maxi = max(arr[i],maxi);
	}
	int e= maxi;
	int mid= s+(e-s)/2;
	int ans =-1;
	while(s<=e)
	{
		if(isPossible(arr,n,k,mid))
		{
			ans=mid;
			s=mid+1;
			
		}
		else
		{
			e=mid-1;
		}
		mid= s+(e-s)/2;
	}
	
	return ans;
	}

int main()
{
	int n;
	cin>>n;
	
	int arr[100];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int k;
	cin>>k;
	int mid;
	isPossible(arr,n,k,mid);
	
	cout<<agressiveCow(arr,n,k);
	
	return 0;
}
