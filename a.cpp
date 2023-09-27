#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x<<" = "<<x<<endl

void solve() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vector<vector<int>>v(n +1, vector<int>(31));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 30; j++) {
            if(a[ i - 1] & (1 << j)) {
                v[i][j] = 1;
            }
            v[i][j] += v[i - 1][j];
        }

    }
    int q;
    cin >> q;
    while(q--) {
        int l, k; cin >> l >> k;
        int lx = l - 1;
        if(a[l - 1] < k) {
            cout << -1 << ' ';
            continue;
        }
        int rx = n + 1;
        while(rx > lx + 1) {
            int mid = (lx + rx) / 2;
            int x = 0;
            for(int i = 0; i <= 30; i++) {
                if(v[mid][i] - v[l - 1][i] == mid - l + 1) {
                    x |= (1 << i);
                }
            }
            if(x >= k) {
                lx = mid;
            } else {
                rx = mid;
            }
        }
        cout << lx <<' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int tt = 1; cin >> tt;
    while(tt--) solve();
    return 0;
}