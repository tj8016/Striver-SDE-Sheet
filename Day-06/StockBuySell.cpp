#include<iostream>
#include<vector>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int profit = 0;
    int minprice = INT_MAX;
    
    for(int i=0; i<prices.size(); i++) {
        minprice = min(minprice, prices[i]);
        profit = max(profit, (prices[i] - minprice));
    }
    return profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> prices(n);

    for(int i=0; i<n; i++) {
        cin >> prices[i];
    }
    int ans = maximumProfit(prices);
    cout << ans << endl;
    return 0;
}