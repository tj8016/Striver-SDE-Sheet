#include<iostream>
#include<vector>
using namespace std;

void rotate90(vector<vector<int> >& matrix) {
    int row=matrix.size();
    // Transpose
    for(int i=0; i<row; i++) {
        for(int j=0; j<i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Row wise reverse
    for(int i=0; i<row; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > matrix;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            int val;
            cin >> val;
            temp.push_back(val);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    rotate90(matrix);
    cout << endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}