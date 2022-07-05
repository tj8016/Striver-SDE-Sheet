#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > ans;
    if (nums.empty()) {    //Base case 1
        return ans;
    }
    if(nums.size() < 3){    //Base case 2
        return ans;
    }
    sort(nums.begin(),nums.end());
    
    for(int i=0; i<nums.size()-2; i++) {
        if(i==0 || (i>0 && nums[i] != nums[i-1])) {
            int s = i+1;
            int e = nums.size()-1;
            int sum = 0-nums[i];
            
            while(s < e) {
                if(nums[s]+nums[e] == sum) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[s]);
                    temp.push_back(nums[e]);
                    ans.push_back(temp);
                    
                    while(s<e && nums[s] == nums[s+1]) s++;
                    while(s<e && nums[e] == nums[e-s]) e--;

                    s++;
                    e--;
                }
                else if(nums[s]+nums[e] > sum) {
                    e--;
                }
                else {
                    s++;
                }
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    vector<vector<int> > ans = threeSum(nums);

    for(int i=0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
// [-1,0,1,2,-1,-4]