#include <bits/stdc++.h>
using namespace std;
struct Node {
    char val;      
    int priority;   
    int size;      
    Node *l, *r;

    Node(char c) : val(c), priority(rand()), size(1), l(NULL), r(NULL) {}
};
int get_size(Node* t) {
    return t ? t->size : 0;
}
void update_size(Node* t) {
    if (t) t->size = 1 + get_size(t->l) + get_size(t->r);
}
void split(Node* t, int k, Node*& l, Node*& r) {
    if (!t) {
        l = r = NULL;
        return;
    }
    int current_index = get_size(t->l) + 1;
    if (current_index <= k) {
        split(t->r, k - current_index, t->r, r);
        l = t;
    } else {
        split(t->l, k, l, t->l);
        r = t;
    }
    update_size(t);
}
void merge(Node*& t, Node* l, Node* r) {
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
    print_treap(t->l);
    cout << t->val;
    print_treap(t->r);
}
int main() {
    ios::sync_with_stdio(false);
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
        
        Node *left_part = NULL;
        Node *range_part = NULL; 
        Node *right_part = NULL;
        Node *temp = NULL;
        split(root, b, temp, right_part);
        split(temp, a - 1, left_part, range_part);

        merge(root, left_part, right_part);
        merge(root, root, range_part);
    }

    print_treap(root);
    cout << endl;
    return 0;
}