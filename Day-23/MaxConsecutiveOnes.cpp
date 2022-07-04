#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int mxCount = INT_MIN;
    int one = 0;
    
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == 0) {
            mxCount = max(mxCount,one);
            one = 0;
        }
        else{
            one++;
        }
    }
    return max(mxCount,one);
}

//Code Studio
int longestSubSeg(vector<int> &arr , int n, int k){
    int start=0;
    int maxi=0;
    int zero=0;
    for(int end=0;end<n;end++){
        if(arr[end]==0){
            zero++;
        }
         if(zero>k){
             while(zero>k){
                 if(arr[start]==0){
                     zero--;
                 }
                 start++;
             }
         }
        maxi=max(maxi,end-start+1);
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << findMaxConsecutiveOnes(arr) << endl;
    return 0;
}