#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct Movie {
    int start, end;
};
bool compareMovies(const Movie &a, const Movie &b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    return a.start < b.start;
}
int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }
    sort(movies.begin(), movies.end(), compareMovies);
    multiset<int> member_free_times;
    for (int i = 0; i < k; i++) {
        member_free_times.insert(0);
    }
    int total_movies = 0;
    for (int i = 0; i < n; i++) {
        auto it = member_free_times.upper_bound(movies[i].start);
        if (it == member_free_times.begin()) {
            continue;
        }
        it--;
        total_movies++;
        member_free_times.erase(it);
        member_free_times.insert(movies[i].end);
    }
    cout << total_movies << endl;
    return 0;
}