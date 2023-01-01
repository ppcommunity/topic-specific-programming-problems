/**
  * Platform: Sphere Online Judge
  * Problem: https://www.spoj.com/problems/CSUMQ/
  * Solved by mustaquenadim
  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N;
    int arr[N], sum[N];
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        if(i == 0) {
            sum[i] = arr[i];
        } else {
            sum[i] = sum[i - 1] + arr[i];
        }
    }
    cin >> Q;
    while(Q--) {
        int i, j, res;
        cin >> i >> j;
        if(i == 0) {
            res = sum[j];
        } else {
            res = sum[j] - sum[i - 1];
        }
        cout << res << endl;
    }
    return 0;
}