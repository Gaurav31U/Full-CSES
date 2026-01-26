#include <bits/stdc++.h>
using namespace std;
const int OFFSET = 1000000; 
const int MAX_COORD = 2000005;
int bit[MAX_COORD] = {0};
void update(int idx, int val) {
    for (; idx < MAX_COORD; idx += idx & -idx)
        bit[idx] += val;
}
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}
struct Event {
    int x;
    int type; 
    int y1, y2;
    bool operator<(const Event& other) const {
        if (x != other.x) return x < other.x;
        return type < other.type;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Event> events;
    events.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int min_x = min(x1, x2), max_x = max(x1, x2);
        int min_y = min(y1, y2), max_y = max(y1, y2);

        if (min_x == max_x) { 
            events.push_back({min_x, 1, min_y, max_y});
        } else { 
            events.push_back({min_x, 2, min_y, 0});
            events.push_back({max_x, 0, min_y, 0});
        }
    }

    sort(events.begin(), events.end());

    long long intersections = 0;

    for (const auto& ev : events) {
        int y_idx = ev.y1 + OFFSET + 1;

        if (ev.type == 2) { 
            update(y_idx, 1);
        } else if (ev.type == 0) {
            update(y_idx, -1);
        } else {
            int top = (ev.y2 + OFFSET + 1) - 1; 
            int bot = (ev.y1 + OFFSET + 1);  
            
            if (top >= bot) {
                intersections += (query(top) - query(bot - 1));
            }
        }
    }

    cout << intersections << endl;

    return 0;
}