#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp = nums1;
    nums1.clear();

    int i = 0;
    int j = 0;
    while(i<m && j<n) {
        if(temp[i] < nums2[j]) {
            nums1.push_back(temp[i++]);
        }
        else {
            nums1.push_back(nums2[j++]);
        }
    }

    while(i<m) {
        nums1.push_back(temp[i++]);
    }
    while(j<n) {
        nums1.push_back(nums2[j++]);
    }
}

void mergewithoutspace(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i,k;
    for(i=0; i<m; i++) {
        if(nums1[i] > nums2[0]) {
            swap(nums1[i], nums2[0]);
        }
        
        int first = nums2[0];
        
        for(k=1; k<n && nums2[k] < first; k++) {
            nums2[k-1] = nums2[k];
        }
        nums2[k-1] = first;
    }
}

int main() {
    int m,n;
    cin >> m >> n;
    vector<int> nums1(m);
    vector<int> nums2(n);

    for(int i=0; i<m; i++) {
        cin >> nums1[i];
    }

    for(int i=0; i<n; i++) {
        cin >> nums2[i];
    }

    merge(nums1, m, nums2, n);

    for (int i = 0; i < 5; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++) {
        cout << nums2[i] << " ";
    }

    return 0;
}