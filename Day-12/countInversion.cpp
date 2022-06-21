#include<bits/stdc++.h>
// #include<iostream>
using namespace std;

int merge(int arr[], int temp[], int s, int mid, int e) {
	int i, j, k;
	int inv_count = 0;

	i = s;
	j = mid;
	k = s;

	while((i <= mid-1) && (j <= e)) {
		if(arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}

	while(i <= mid-1) {
		temp[k++] = arr[i++];
	}

	while(j <= e) {
		temp[k++] = arr[j++];
	}

	for(int i=s; i<=e; i++) {
		arr[i] = temp[i];
	}
	return inv_count;
}

int mergeSort(int arr[], int temp[], int s, int e) {
	int mid, inv_count = 0;
	if(e > s) {
		mid = (s+e)/2;

		inv_count += mergeSort(arr, temp, s, mid);
		inv_count += mergeSort(arr, temp, mid+1, e);

		inv_count += merge(arr, temp, s, mid+1, e);
	}
	return inv_count;
}

int main() {
// ONLINE_JUDGE
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);

// 	freopen("output.txt", "w", stdout);
// #endif

	int arr[] = {5,3,2,4,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int temp[n];

	int ans = mergeSort (arr, temp, 0, n-1);
	cout << "Number of Inversion : " << ans << endl;

	return 0;
}