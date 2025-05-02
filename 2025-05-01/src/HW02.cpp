#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
    char key;
    Node* left, * right;
    Node(char k) : key(k), left(nullptr), right(nullptr) {}
};

// 計算實際高度（層數）
int height(Node* n) {
    return n ? 1 + max(height(n->left), height(n->right)) : 0;
}

// 範例裡的右旋
Node* rightRotate(Node* p) {
    Node* q = p->left;
    Node* r = q->right;
    q->right = p;
    p->left = r;
    return q;
}

void printPretty(Node* root) {
    if (!root) return;
    int h = height(root);
    int width = (1 << (h + 1)) - 1;
    vector<string>  nodeLines(h), connLines(h - 1);
    vector<Node*>   curr = { root };
    vector<int>     pos = { (width - 1) / 2 };

    for (int level = 1; level <= h; ++level) {
        string line(width, ' ');
        for (size_t i = 0; i < curr.size(); ++i) {
            if (curr[i]) line[pos[i]] = curr[i]->key;
        }
        nodeLines[level - 1] = move(line);

        if (level == h) break;

        string lineC(width, ' ');
        int delta = 1 << (h - level);
        for (size_t i = 0; i < curr.size(); ++i) {
            if (!curr[i]) continue;
            int p = pos[i];
            if (curr[i]->left)  lineC[p - delta] = '/';
            if (curr[i]->right) lineC[p + delta] = '\\';
        }
        connLines[level - 1] = move(lineC);

        // 3) 準備下一層
        vector<Node*> nextN;
        vector<int>   nextP;
        for (size_t i = 0; i < curr.size(); ++i) {
            int p = pos[i];
            nextN.push_back(curr[i] ? curr[i]->left : nullptr);
            nextP.push_back(p - delta);
            nextN.push_back(curr[i] ? curr[i]->right : nullptr);
            nextP.push_back(p + delta);
        }
        curr = move(nextN);
        pos = move(nextP);
    }

    // 輸出：節點行與連線行交錯
    for (int i = 0; i < h - 1; ++i) {
        cout << nodeLines[i] << "\n"
            << connLines[i] << "\n";
    }
    cout << nodeLines[h - 1] << "\n";
}

int main() {
    // --- 建立範例樹 A(B(D,E), C(F,G)) ---
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->left = new Node('F');
    root->right->right = new Node('G');

    cout << "\n旋轉前：\n\n";
    printPretty(root);

    // --- 執行以 A 為根的右旋 ---
    Node* newRoot = rightRotate(root);

    cout << "\n旋轉後：\n\n";
    printPretty(newRoot);

    return 0;
}
