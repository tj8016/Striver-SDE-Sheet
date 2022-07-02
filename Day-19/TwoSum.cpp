#include<iostream>
#include<vector>
using namespace std;

// o(n^2) Solution
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                v.push_back(i);
                v.push_back(j);
            }
        }
    }
    return v;
}

// o(nlogn) Solution
vector<int> TwoSum(vector<int>& nums, int target) {
    vector<pair<int, int> > v;
    
    for(int i=0;i<nums.size();i++){
         pair<int,int> p;
         p.first = nums[i];
         p.second = i;

         v.push_back(p);
    }
    sort(v.begin(),v.end());
    
    int i = 0;
    int j = nums.size()-1;
    vector<int> ans;
    
    while(i<j) {
        int sum = v[i].first + v[j].first;
        if(sum == target) {
            ans.push_back(v[i].second);
            ans.push_back(v[j].second);
            break;
        }
        else if(sum > target) {
            j--;
        }
        else {
            i++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = TwoSum(arr, 9);

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}