#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j];
                cd v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    if (cin >> n >> m) {
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        reverse(b.begin(), b.end());
        int size = 1;
        while (size < n + m) size <<= 1;

        vector<cd> fa(size), fb(size);
        for (int i = 0; i < n; i++) fa[i] = a[i];
        for (int i = 0; i < m; i++) fb[i] = b[i]; 
        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < size; i++) {
            fa[i] *= fb[i];
        }
        fft(fa, true);
        for (int i = 0; i < n + m - 1; i++) {
            long long result = (long long)(fa[i].real() + 0.5);
            cout << result << (i == n + m - 2 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}