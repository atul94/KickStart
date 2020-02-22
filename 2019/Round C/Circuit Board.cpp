#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int testcaees;
    cin >> testcaees;
    
    for(int testcase = 1; testcase <= testcaees; testcase++) {
        int ans = 1;
        int r,c,k,x;
        cin >> r >> c >> k;
        ans = r;
        vector<vector<int> > A(r, vector<int>(c));
        vector<vector<int> > maxDp(r, vector<int>(c, 1));
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                cin >> A[i][j];
        for(int i = 0; i < r; i++) {
            for(int j = 1; j < c; j++) {
                int f = 0;
                int thickest = A[i][j];
                int thinest = A[i][j];
                for(int l = j-1; l >= 0; l--) {
                    thickest = max(thickest, A[i][l]);
                    thinest = min(thinest, A[i][l]);
                    if(thickest-thinest > k) {
                        maxDp[i][j] = j-l;
                        f = 1;
                        break;
                    }
                }
                if(f == 0)
                    maxDp[i][j] = j+1;
            }
        }
        for(int i = 0; i < c; i++) {
            ans = max(ans, maxDp[0][i]);
        }
        for(int i = 1; i < r; i++) {
            for(int j = 0; j < c; j++) {
                //dp[i][j] = maxDp[i][j];
                x = maxDp[i][j];
                for(int l = i-1; l >= 0; l--) {
                    x = min(x, maxDp[l][j]);
                    ans = max(ans, x*(i-l+1));
                    if(x == 1)
                        break;
                }
            }
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
