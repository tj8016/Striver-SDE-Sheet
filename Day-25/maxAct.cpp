#include<bits/stdc++.h>
using namespace std;
class act{
    public:
    int start;
    int end;
};
bool compare(act a1,act a2){
    return (a1.end<a2.end);
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    struct act meet[start.size()];
    int  n=start.size();
    for(int i=0;i<n;i++){
        meet[i].start=start[i];
        meet[i].end=finish[i];
    }
    sort(meet,meet+n,compare);
    int prev=meet[0].end;
    int counter=1;
    for(int i=1;i<n;i++){
        if(meet[i].start>=prev){
            counter++;
            prev=meet[i].end;
        }
    }
    return counter;
}

int main() {

    return 0;
}