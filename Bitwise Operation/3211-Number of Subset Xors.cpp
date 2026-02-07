#include <iostream>
using namespace std;

const int MAX_BITS = 30;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
        int basis[MAX_BITS] = {0};
        int basis_size = 0;
        for (int i = 0; i < n; ++i) {
            int x;cin >> x;
            for (int k = MAX_BITS - 1; k >= 0; --k) {
                if ((x >> k) & 1) {
                    if (!basis[k]) {
                        basis[k] = x;
                        basis_size++;
                        break;
                    }
                    x ^= basis[k];
                }
            }
        }
        cout << (1LL << basis_size) << "\n";
    return 0;
}