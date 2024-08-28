#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int userIndex(const vector<pair<int,int>>& v, int id) {
    for(int i = 0; i < (int)v.size(); i++) {
        if(v[i].first == id)
            return i;
    }
    return -1;
}

bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    
    for(int i = 0; i < n; i++) {
        int id, bal;
        cin >> id >> bal;
        v[i] = {id, bal};
    }
    
    int t;
    cin >> t;
    vector<string> status;
    
    while(t--) {
        int from, to, amt;
        cin >> from >> to >> amt;
        
        int fromIndex = userIndex(v, from);
        int toIndex = userIndex(v, to);
        
        if(fromIndex != -1 && toIndex != -1 && v[fromIndex].second >= amt) {
            v[fromIndex].second -= amt;
            v[toIndex].second += amt;
            status.push_back("Success");
        } else {
            status.push_back("Failure");
        }
    }
    
    for(const auto& x : status)
        cout << x << endl;
    cout << endl;
    
    sort(v.begin(), v.end(), compare);
    
    for(const auto& x : v)
        cout << x.first << " " << x.second << endl;
    
    return 0;
}