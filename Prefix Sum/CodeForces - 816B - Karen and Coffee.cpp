/**
  * Platform: CodeForces
  *	Problem: https://codeforces.com/contest/816/problem/B
  */

#include <bits/stdc++.h>
using namespace std;

#define MAX_TEMP 200001

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    int arr[MAX_TEMP] = {0}, prefix[MAX_TEMP];
    while (n--) {
        int l, r;
        cin >> l >> r;
        arr[l]++;
        arr[r + 1]--;
    }
    prefix[0] = arr[0];
    for(int i = 1; i < MAX_TEMP; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
        // if(prefix[i] > 0) {
        //     cout << i << " = " << prefix[i] << endl;
        // }
    }
    for(int i = 0; i < MAX_TEMP; i++) {
        if(prefix[i] >= k) {
            prefix[i] = 1;
        } else {
            prefix[i] = 0;
        }
    }
    prefix[0] = prefix[0];
    for(int i = 1; i < MAX_TEMP; i++) {
        prefix[i] = prefix[i - 1] + prefix[i];
    }
    while(q--) {
        int a, b, kount = 0;
        cin >> a >> b;
        if(a == 0) {
            kount = prefix[b];
        } else {
            kount = prefix[b] - prefix[a - 1];
        }
        cout << kount << endl;
    }
    return 0;
}