#include<iostream>
#include<vector>
using namespace std;

void nextPermutation(vector<int>& arr) {
    int n = arr.size(), k, l;
    for (k = n - 2; k >= 0; k--) {
        if (arr[k] < arr[k + 1]) {
            break;
        }
    }
    if (k < 0) {
        reverse(arr.begin(), arr.end());
    } else {
        for (l = n - 1; l > k; l--) {
            if (arr[l] > arr[k]) {
                break;
            }
        } 
        swap(arr[k], arr[l]);
        reverse(arr.begin() + k + 1, arr.end());
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n, 1);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    nextPermutation(arr);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}