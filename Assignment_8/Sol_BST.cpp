// BST_Heaps.cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v=0) : data(v), left(nullptr), right(nullptr) {}
};

// ----------------- BST class -----------------
class BST {
    Node* root;

    // INTERNAL recursive helpers
    Node* insertRec(Node* node, int val) {
        if (!node) return new Node(val);
        if (val == node->data) return node; // no duplicates
        if (val < node->data) node->left = insertRec(node->left, val);
        else node->right = insertRec(node->right, val);
        return node;
    }

    Node* minNode(Node* node) {
        if (!node) return nullptr;
        while (node->left) node = node->left;
        return node;
    }

    Node* maxNode(Node* node) {
        if (!node) return nullptr;
        while (node->right) node = node->right;
        return node;
    }

    Node* deleteRec(Node* node, int val) {
        if (!node) return nullptr;
        if (val < node->data) node->left = deleteRec(node->left, val);
        else if (val > node->data) node->right = deleteRec(node->right, val);
        else {
            // found
            if (!node->left && !node->right) { delete node; return nullptr; }
            if (!node->left) { Node* r = node->right; delete node; return r; }
            if (!node->right) { Node* l = node->left; delete node; return l; }
            // two children: replace with inorder successor (min in right)
            Node* succ = minNode(node->right);
            node->data = succ->data;
            node->right = deleteRec(node->right, succ->data);
        }
        return node;
    }

    bool searchRec(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data) return searchRec(node->left, val);
        return searchRec(node->right, val);
    }

    // traversals
    void inorderRec(Node* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }
    void preorderRec(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }
    void postorderRec(Node* node) {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }

    // depth helpers
    int maxDepthRec(Node* node) {
        if (!node) return 0;
        return 1 + max(maxDepthRec(node->left), maxDepthRec(node->right));
    }
    int minDepthRec(Node* node) {
        if (!node) return 0;
        if (!node->left && !node->right) return 1;
        if (!node->left) return 1 + minDepthRec(node->right);
        if (!node->right) return 1 + minDepthRec(node->left);
        return 1 + min(minDepthRec(node->left), minDepthRec(node->right));
    }

    // check BST using range limits
    bool isBSTRec(Node* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->data <= lo || node->data >= hi) return false;
        return isBSTRec(node->left, lo, node->data) && isBSTRec(node->right, node->data, hi);
    }

    // find node pointer by value (first match)
    Node* findNode(Node* node, int val) {
        if (!node) return nullptr;
        if (node->data == val) return node;
        if (val < node->data) return findNode(node->left, val);
        else return findNode(node->right, val);
    }

public:
    BST(): root(nullptr) {}

    // 1 (a) traversals (public wrappers)
    void inorder() {
        if (!root) { cout << "BST empty\n"; return; }
        inorderRec(root); cout << "\n";
    }
    void preorder() {
        if (!root) { cout << "BST empty\n"; return; }
        preorderRec(root); cout << "\n";
    }
    void postorder() {
        if (!root) { cout << "BST empty\n"; return; }
        postorderRec(root); cout << "\n";
    }

    // 2 (a) Search recursive & non-recursive
    bool search_recursive(int val) { return searchRec(root, val); }

    bool search_iterative(int val) {
        Node* cur = root;
        while (cur) {
            if (cur->data == val) return true;
            if (val < cur->data) cur = cur->left;
            else cur = cur->right;
        }
        return false;
    }

    // 2 (b)(c)
    int find_min() {
        Node* mn = minNode(root);
        if (!mn) throw runtime_error("BST empty");
        return mn->data;
    }
    int find_max() {
        Node* mx = maxNode(root);
        if (!mx) throw runtime_error("BST empty");
        return mx->data;
    }

    // 2 (d) inorder successor of a value
    // returns pair(found, value). If not found returns (false, 0)
    pair<bool,int> inorder_successor(int val) {
        Node* cur = findNode(root, val);
        if (!cur) return {false, 0};
        // if right subtree exists, successor is min of right
        if (cur->right) {
            Node* mn = minNode(cur->right);
            return {true, mn->data};
        }
        // else go up: track successor from root
        Node* succ = nullptr;
        Node* ancestor = root;
        while (ancestor && ancestor != cur) {
            if (cur->data < ancestor->data) { succ = ancestor; ancestor = ancestor->left; }
            else ancestor = ancestor->right;
        }
        if (succ) return {true, succ->data};
        return {false, 0};
    }

    // 2 (e) inorder predecessor of a value
    pair<bool,int> inorder_predecessor(int val) {
        Node* cur = findNode(root, val);
        if (!cur) return {false, 0};
        if (cur->left) {
            Node* mx = maxNode(cur->left);
            return {true, mx->data};
        }
        Node* pred = nullptr;
        Node* ancestor = root;
        while (ancestor && ancestor != cur) {
            if (cur->data > ancestor->data) { pred = ancestor; ancestor = ancestor->right; }
            else ancestor = ancestor->left;
        }
        if (pred) return {true, pred->data};
        return {false, 0};
    }

    // 3 (a) Insert an element (no duplicates)
    void insert_node(int val) { root = insertRec(root, val); }

    // 3 (b) Delete an element (existing)
    void delete_node(int val) { root = deleteRec(root, val); }

    // 3 (c)(d) depth
    int max_depth() { return maxDepthRec(root); }
    int min_depth() { if (!root) return 0; return minDepthRec(root); }

    // 4 Check if binary tree is BST
    bool is_bst() { return isBSTRec(root, LLONG_MIN, LLONG_MAX); }

    // helper: expose root for debugging or external functions (const)
    Node* get_root() const { return root; }

    // utility: populate tree from vector by inserting
    void build_from_vector(const vector<int>& v) {
        for (int x: v) insert_node(x);
    }
};

// ----------------- Heapsort & Priority Queue -----------------

// heapify (max-heap) for vector<int>
static void heapify_max(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify_max(a, n, largest);
    }
}

void heapsort_increasing(vector<int>& a) {
    int n = (int)a.size();
    if (n < 2) return;
    // build max-heap
    for (int i = n/2 - 1; i >= 0; --i) heapify_max(a, n, i);
    // extract
    for (int i = n-1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify_max(a, i, 0);
    }
}

// heapify (min-heap) for vector<int>
static void heapify_min(vector<int>& a, int n, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && a[l] < a[smallest]) smallest = l;
    if (r < n && a[r] < a[smallest]) smallest = r;
    if (smallest != i) {
        swap(a[i], a[smallest]);
        heapify_min(a, n, smallest);
    }
}

void heapsort_decreasing(vector<int>& a) {
    int n = (int)a.size();
    if (n < 2) return;
    // build min-heap
    for (int i = n/2 - 1; i >= 0; --i) heapify_min(a, n, i);
    for (int i = n-1; i > 0; --i) {
        swap(a[0], a[i]);
        heapify_min(a, i, 0);
    }
}

// Simple binary heap priority queue implementation (max or min)
template<typename T>
class BinaryHeap {
    vector<T> data;
    bool is_min; // true => min-heap, false => max-heap
    void sift_up(int idx) {
        while (idx > 0) {
            int p = (idx - 1) / 2;
            if (is_min ? (data[idx] < data[p]) : (data[idx] > data[p])) {
                swap(data[idx], data[p]);
                idx = p;
            } else break;
        }
    }
    void sift_down(int idx) {
        int n = (int)data.size();
        while (true) {
            int l = 2*idx + 1, r = 2*idx + 2, best = idx;
            if (l < n && (is_min ? data[l] < data[best] : data[l] > data[best])) best = l;
            if (r < n && (is_min ? data[r] < data[best] : data[r] > data[best])) best = r;
            if (best != idx) { swap(data[idx], data[best]); idx = best; }
            else break;
        }
    }
public:
    BinaryHeap(bool minHeap=false): is_min(minHeap) {}
    int size() const { return (int)data.size(); }
    bool empty() const { return data.empty(); }
    void push(const T& x) { data.push_back(x); sift_up((int)data.size()-1); }
    void pop() { if (data.empty()) return; data[0] = data.back(); data.pop_back(); if (!data.empty()) sift_down(0); }
    T top() const { if (data.empty()) throw runtime_error("empty heap"); return data.front(); }
};

// ----------------- Small interactive menu -----------------
void bst_menu(BST &tree) {
    while (true) {
        cout << "\n--- BST MENU ---\n"
             << "1. Insert\n2. Delete\n3. Search(rec)\n4. Search(iter)\n5. Min element\n6. Max element\n7. Inorder successor\n8. Inorder predecessor\n9. Inorder traversal\n10. Preorder traversal\n11. Postorder traversal\n12. Max depth\n13. Min depth\n14. Is BST?\n15. Back to main\nChoice: ";
        int ch; cin >> ch;
        if (ch == 15) break;
        int x;
        switch (ch) {
            case 1: cout << "Value to insert: "; cin >> x; tree.insert_node(x); break;
            case 2: cout << "Value to delete: "; cin >> x; tree.delete_node(x); break;
            case 3: cout << "Value to search (rec): "; cin >> x; cout << (tree.search_recursive(x) ? "Found\n" : "Not found\n"); break;
            case 4: cout << "Value to search (iter): "; cin >> x; cout << (tree.search_iterative(x) ? "Found\n" : "Not found\n"); break;
            case 5: try { cout << "Min: " << tree.find_min() << "\n"; } catch(...) { cout << "Empty\n"; } break;
            case 6: try { cout << "Max: " << tree.find_max() << "\n"; } catch(...) { cout << "Empty\n"; } break;
            case 7: cout << "Value: "; cin >> x; { auto p=tree.inorder_successor(x); if (p.first) cout<<"Successor: "<<p.second<<"\n"; else cout<<"No successor or not found\n"; } break;
            case 8: cout << "Value: "; cin >> x; { auto p=tree.inorder_predecessor(x); if (p.first) cout<<"Predecessor: "<<p.second<<"\n"; else cout<<"No predecessor or not found\n"; } break;
            case 9: tree.inorder(); break;
            case 10: tree.preorder(); break;
            case 11: tree.postorder(); break;
            case 12: cout << "Max depth: " << tree.max_depth() << "\n"; break;
            case 13: cout << "Min depth: " << tree.min_depth() << "\n"; break;
            case 14: cout << (tree.is_bst() ? "Is BST\n" : "Not BST\n"); break;
            default: cout << "Invalid\n";
        }
    }
}

void heap_menu() {
    while (true) {
        cout << "\n--- HEAP MENU ---\n1. Heapsort increasing\n2. Heapsort decreasing\n3. Priority queue (max-heap) demo\n4. Priority queue (min-heap) demo\n5. Back\nChoice: ";
        int ch; cin >> ch;
        if (ch == 5) break;
        if (ch == 1 || ch == 2) {
            cout << "Enter numbers (space separated), end with non-number (e.g. letter):\n";
            vector<int> a;
            int v;
            // read line of ints
            string line;
            getline(cin, line); // flush
            getline(cin, line);
            stringstream ss(line);
            while (ss >> v) a.push_back(v);
            if (ch == 1) {
                heapsort_increasing(a);
                cout << "Sorted increasing: ";
                for (int x: a) cout << x << " ";
                cout << "\n";
            } else {
                heapsort_decreasing(a);
                cout << "Sorted decreasing: ";
                for (int x: a) cout << x << " ";
                cout << "\n";
            }
        } else if (ch == 3) {
            BinaryHeap<int> pq(false); // max-heap
            cout << "Enter numbers to push to max-heap. Enter non-number to stop:\n";
            int v;
            while (cin >> v) {
                pq.push(v);
                cout << "pushed " << v << ". top = " << pq.top() << ". continue? (enter number or letter to stop)\n";
                // break only on non-number, but we'll allow user to press Ctrl+D or type letter: handled by next extraction
                char c = cin.peek();
                if (c == '\n') continue;
            }
            // clear failbit if user typed letter
            cin.clear();
            string discard;
            getline(cin, discard);

            cout << "Pop all elements: ";
            while (!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << "\n";
        } else if (ch == 4) {
            BinaryHeap<int> pq(true); // min-heap
            cout << "Enter numbers to push to min-heap. Enter non-number to stop:\n";
            int v;
            while (cin >> v) {
                pq.push(v);
                cout << "pushed " << v << ". top = " << pq.top() << ". continue? (enter number or letter to stop)\n";
            }
            cin.clear();
            string discard;
            getline(cin, discard);
            cout << "Pop all elements: ";
            while (!pq.empty()) {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << "\n";
        }
    }
}

int main() {
    BST tree;
    while (true) {
        cout << "\n=== MAIN MENU ===\n1. BST operations\n2. Heap / priority queue\n3. Exit\nChoice: ";
        int ch; cin >> ch;
        if (ch == 3) break;
        if (ch == 1) bst_menu(tree);
        else if (ch == 2) heap_menu();
    }
    cout << "Goodbye\n";
    return 0;
}
