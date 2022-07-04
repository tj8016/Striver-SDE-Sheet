#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    if(n==0) {
        return 0;
    }

    int i=0;
    for(int j=0; j<n; j++) {
        if(arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    n = removeDuplicates(arr, n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}