#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <stack>
#include <vector>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100005;
struct Node {
    int key;
    Node *next;
};

Node* b[N];
int cnt = 0;

Node *insert(Node *h, int key, int id) {
    if (id == 0) {
        Node *r = new Node;
        r->next = h;
        r->key = key;
        b[++cnt] = r;
        return r;
    }
    Node* p = b[id];
    Node *q = new Node;
    q->key = key;
    q->next = p->next;
    b[++cnt] = q;
    p->next = q;
    return h;
}

Node *erase(Node *h, int id) {
    if (id == 0) {
        Node *r = h->next;
        delete h;
        return r;
    }
    Node *p = b[id];
    Node *q = p->next;
    p->next = q->next;
    delete q;
    return h;
}

int main() {
  int n;
  cin >> n;
  Node *head = nullptr;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'H') {
        int x;
        cin >> x;
        head = insert(head, x, 0);
    } else if (c == 'D') {
        int k;
        cin >> k;
        head = erase(head, k);
    } else if (c == 'I') {
        int k, x;
        cin >> k >> x;
        head = insert(head, x, k);
    }
  }
  Node *p = head;
  while (p) {
    cout << p->key << " ";
    p = p->next;
  }
  cout << endl;

  return 0;
}