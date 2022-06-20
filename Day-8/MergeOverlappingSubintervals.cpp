#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > merge(vector<vector<int> >& intervals) {
    vector<vector<int> > merge;
    sort(intervals.begin(), intervals.end());
    
    vector<int> temp = intervals[0];
    
    for(int i=1; i<intervals.size(); i++) {
        if(intervals[i][0] <= temp[1]) {
            temp[1] = max(temp[1], intervals[i][1]);
        }
        else{
            merge.push_back(temp);
            temp = intervals[i];
        }
    }
    
    merge.push_back(temp);
    return merge;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int> > arr(n);
    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<2; j++) {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        arr.push_back(temp);
        temp.clear();
    }

    vector<vector<int> > ans = merge(arr);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}