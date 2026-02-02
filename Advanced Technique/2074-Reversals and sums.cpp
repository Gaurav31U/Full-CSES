#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node {
    int val;int priority;  
    int cnt;   
    ll sum;  
    bool rev;  
    Node *l, *r;
    Node(int v) : val(v), priority(rand()), cnt(1), sum(v), rev(false), l(NULL), r(NULL) {}
};
int get_cnt(Node* t) {
    return t ? t->cnt : 0;
}
ll get_sum(Node* t) {
    return t ? t->sum : 0;
}
void update(Node* t) {
    if (t) {
        t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
        t->sum = t->val + get_sum(t->l) + get_sum(t->r);
    }
}
void push(Node* t) {
    if (t && t->rev) {
        t->rev = false;
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
    }
}
void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = NULL;
        return;
    }
    push(t);
    int current_idx = get_cnt(t->l) + 1;
    
    if (current_idx <= k) {
        split(t->r, k - current_idx, t->r, r);
        l = t;
    } else {
        split(t->l, k, l, t->l);
        r = t;
    }
    update(t);
}
void merge(Node*& t, Node* l, Node* r) {
    push(l);
    push(r);

    if (!l || !r) {
        t = l ? l : r;
    } else if (l->priority > r->priority) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    update(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));

    int n, m;
    if (!(cin >> n >> m)) return 0;

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        merge(root, root, new Node(x));
    }
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        Node *left_part = NULL;
        Node *range_part = NULL; 
        Node *right_part = NULL;
        
        split(root, b, range_part, right_part);
        split(range_part, a - 1, left_part, range_part);

        if (t == 1) {
            if(range_part) range_part->rev ^= true; 
        } 
        else {
            cout << get_sum(range_part) << "\n";
        }
        merge(root, left_part, range_part);
        merge(root, root, right_part);
    }

    return 0;
}