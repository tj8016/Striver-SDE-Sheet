#include <bits/stdc++.h>
using namespace std;
void setZeros(vector<vector<int> > &matrix)
{
    // Write your code here.
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> temp1(row, -1);
    vector<int> temp2(col, -1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                temp1[i] = 0;
                temp2[j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (temp1[i] == 0 || temp2[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    // ONLINE_JUDGE
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);
    #endif

    vector<vector<int> > arr;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    setZeros(arr);
    cout << "The Final Matrix is " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
