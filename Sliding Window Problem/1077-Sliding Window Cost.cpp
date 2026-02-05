#include <bits/stdc++.h>
using namespace std;

multiset<long long> low, high;
long long sum_low = 0;
long long sum_high = 0;
int n, k;

void balance() {
    size_t target_low_size = (k + 1) / 2;
    while (low.size() > target_low_size) {
        auto it = prev(low.end());
        long long val = *it;
        sum_low -= val;
        low.erase(it);
        
        high.insert(val);
        sum_high += val;
    }
    while (low.size() < target_low_size && !high.empty()) {
        auto it = high.begin();
        long long val = *it;
        sum_high -= val;
        high.erase(it);
        
        low.insert(val);
        sum_low += val;
    }
    while (!low.empty() && !high.empty() && *low.rbegin() > *high.begin()) {
        long long low_max = *low.rbegin();
        long long high_min = *high.begin();
        
        low.erase(prev(low.end())); sum_low -= low_max;
        high.erase(high.begin());   sum_high -= high_min;
        
        low.insert(high_min); sum_low += high_min;
        high.insert(low_max); sum_high += low_max;
    }
}
void add(long long val) {
    if (low.empty()) {
        low.insert(val);
        sum_low += val;
    } else {
        long long median = *low.rbegin();
        if (val > median) {
            high.insert(val);
            sum_high += val;
        } else {
            low.insert(val);
            sum_low += val;
        }
    }
    balance();
}
void remove(long long val) {
    auto it_high = high.find(val);
    if (it_high != high.end()) {
        sum_high -= val;
        high.erase(it_high);
    } else {
        auto it_low = low.find(val);
        sum_low -= val;
        low.erase(it_low);
    }
    balance();
}
long long get_cost() {
    long long median = *low.rbegin();
    return (sum_high - sum_low) + median * ((long long)low.size() - (long long)high.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> k)) return 0;

    vector<long long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < k; i++) {
        add(x[i]);
    }
    
    cout << get_cost();

    for (int i = k; i < n; i++) {
        remove(x[i - k]); 
        add(x[i]);       
        cout << " " << get_cost();
    }
    cout << endl;

    return 0;
}