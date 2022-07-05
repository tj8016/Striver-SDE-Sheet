#include <bits/stdc++.h> 
using namespace std;

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int sz = start.size();
    vector<int> answer;
    map<pair<int,int>, int> val;
    for(int i = 0; i < sz; i++) {
        val.insert({{end[i], start[i]}, i+1});
    }
    int x = -1;
    for(auto &p : val) {
        if(x < p.first.second) {
            answer.push_back(p.second);
            x = p.first.first;
        }
        else if (x == p.first.first && p.second < answer.back()) {
            answer.back() = p.second;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);

    for(int i=0; i<n; i++) {
        cin >> start[i];
    }
    for(int i=0; i<n; i++) {
        cin >> end[i];
    }
    vector<int> ans = maximumMeetings(start, end);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}