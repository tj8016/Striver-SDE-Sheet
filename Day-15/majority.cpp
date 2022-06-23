#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 0;
    int candidate = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        if(num==candidate) count += 1; 
        else count -= 1; 
    }

    return candidate;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    cout << majorityElement(nums) << endl;
    return 0;
}