#include <bits/stdc++.h>
 
using namespace std;

 int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minimum = 1;
        int maximum =1;
        int ans = INT_MIN;
        for(int i =0;i<n;i++){
            if(nums[i]<0){
                swap(maximum,minimum);
            }
            maximum=max(maximum*nums[i],nums[i]);
            minimum=min(minimum*nums[i],nums[i]);
            ans=max(ans,maximum);
        }
        return ans;
    }
    int main(){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        cout<<maxProduct(nums);
        return 0;
    }