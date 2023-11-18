#include <bits/stdc++.h>
using namespace std;
#define krep(i, k, n) for (int i = k; i < (int)(n); i++)

#define prep(i, n) for (int i = 1; i <= (int)(n); i++)

#define irep(i, n) for (int i = (int)n - 1; i >= 0; i--)


char int_to_alphabet(int i) {
    // i = 0 -> a
    // i = 25 -> z
    return i + 'a';
} 

int alphabet_to_int(char s) {
    return s - 'a';
}



int main() {
    int X[1509][1509], Z[1509][1509] = {0};
    int A[100009], B[100009], C[100009], D[100009];
    int H, W, Q;
    cin>>H>>W;

    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <=W; j++)
        {
            cin>>X[i][j];
        }
        
    }
    for (int i = 1; i <= H; i++)
    {
        for (int j = 1; j <=W; j++)
        {
            Z[i][j] = Z[i][j-1] + X[i][j];
        }
        
    }

    for (int j = 1; j <= W; j++)
    {
        for (int i = 1; i <=H; i++)
        {
            Z[i][j] = Z[i-1][j] + Z[i][j];
        }
        
    }
    
    cin>>Q;
    for (int i = 1; i <= Q; i++)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    
    for (int i = 1; i <= Q; i++)
    {
        int ans;
        ans = Z[C[i]][D[i]] + Z[A[i]-1][B[i]-1] - Z[C[i]][B[i]-1] - Z[A[i]-1][D[i]];
        cout<<ans<<endl;
    }

    return 0;

}