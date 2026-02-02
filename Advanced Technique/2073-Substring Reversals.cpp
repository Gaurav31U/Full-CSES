#include <bits/stdc++.h>
using namespace std;
struct Node {
    char val;   
    int priority;  
    int size;  
    bool reverse;   
    Node *l, *r;
    Node(char c) : val(c), priority(rand()), size(1), reverse(false), l(NULL), r(NULL) {}
};
int get_size(Node* t) {
    return t ? t->size : 0;
}
void update_size(Node* t) {
    if (t) t->size = 1 + get_size(t->l) + get_size(t->r);
}
void push(Node* t) {
    if (t && t->reverse) {
        t->reverse = false; 
        swap(t->l, t->r); 
        if (t->l) t->l->reverse ^= true;
        if (t->r) t->r->reverse ^= true;
    }
}
void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = NULL;
        return;
    }
    push(t);
    int current_idx = get_size(t->l) + 1;
    if (current_idx <= k) {
        split(t->r, k - current_idx, t->r, r);
        l = t;
    } else {
        split(t->l, k, l, t->l);
        r = t;
    }
    update_size(t);
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
    update_size(t);
}
void print_treap(Node* t) {
    if (!t) return;
    push(t);
    print_treap(t->l);
    cout << t->val;
    print_treap(t->r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    int n, m;cin >> n >> m;
    string s;cin >> s;
    Node* root = NULL;
    for (char c : s) {
        merge(root, root, new Node(c));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        Node *t1 = NULL, *t2 = NULL, *t3 = NULL;
        split(root, b, t2, t3);
        split(t2, a - 1, t1, t2);
        if (t2) t2->reverse ^= true;

        merge(root, t1, t2);
        merge(root, root, t3);
    }
    print_treap(root);
    cout << endl;

    return 0;
}