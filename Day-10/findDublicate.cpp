#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int check[n];
    for(int i=0; i<n; i++){
        check[i] = 0;
    }
    
    for(int i=0; i<n; i++){
        if(check[nums[i]] != 0 ){
            return nums[i];
        }
        else{
            check[nums[i]] = 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << "The dublicate number is : ";
    cout << findDuplicate(nums) << endl;

    return 0;
}