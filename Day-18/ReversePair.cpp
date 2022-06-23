#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr ,int l ,int r , int mid){
    int inv = 0;
    int n1 = mid-l+1; // for size of first array 
    int n2 = r-mid; // for size of second array 

    int a[n1];
    int b[n2];

    // generating the left subarray
    long long int originalIndex = l;
    for(int i=0;i<n1;i++)
    {
        a[i] = arr[originalIndex++];
    }

    // generating the right subarray
    originalIndex = mid + 1;
    for(int i=0;i<n2;i++)
    {
        b[i] = arr[originalIndex++];
    }

    // counting inv
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]/(2.0)>b[j]){

            inv+=n1-i;
            j++;
        }
        else
            i++;
        }

    // To traverse array and then genereate a sorted one 
    i=0;
    j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {   
            arr[k++] = b[j++];
        }
    }

    while(i<n1)
    {
        arr[k++] = a[i++];
    }

    while(j<n2)
    {
        arr[k++] = b[j++];
    }
    return inv;
}

int merge_sort(vector<int>& arr ,int l , int r)
{
    int inversion = 0;
    if(l < r)
    {
        int mid = (l+r)/2;
        inversion+=merge_sort(arr , l , mid); // left subarray se inversion honge wo 
        inversion+=merge_sort(arr , mid+1 , r); // right subarray se inversion honge wo
        inversion+=merge(arr , l , r , mid); // merge krte time inversion count hogo
    }
    return inversion;
}

int reversePairs(vector<int>& arr, int n) {
    return merge_sort(arr, 0, n-1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << reversePairs(arr, n) << endl;
    return 0;
}