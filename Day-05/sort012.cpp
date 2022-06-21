#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int>& arr) {
    int i=0;
    int j=0;
    int k=arr.size()-1;

    while(j<=k) {
        switch (arr[j])
        {
        case 0:
            swap(arr[i++], arr[j++]);
            break;
        
        case 1:
            j++;
            break;

        case 2:
            swap(arr[j++], arr[k--]);
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sort012(arr);
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }cout << endl;
    return 0;
}