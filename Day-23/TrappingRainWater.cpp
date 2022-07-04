#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& height) {
    int leftmax = 0;
    int rightmax = 0;
    int l = 0;
    int r = height.size()-1;
    int res = 0;
    
    while(l<r) {
        if(height[l] <= height[r]) {
            if(height[l] >= leftmax) {
                leftmax = height[l];
            }
            else {
                res += leftmax-height[l];
            }
            l++;
        }
        else {
            if(height[r] >= rightmax) {
                rightmax = height[r];
            }
            else {
                res += rightmax-height[r];
            }
            r--;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> height(n);

    for(int i=0; i<n; i++) {
        cin >> height[i];
    }

    cout << trap(height) << endl;;
    return 0;
}