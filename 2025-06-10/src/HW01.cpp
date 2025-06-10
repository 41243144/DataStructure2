#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int u, const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, component);
        }
    }
}

int main() {
    int n, m;
    
    // 提示輸入
    cout << "請輸入節點數量和邊數量: ";
    cin >> n >> m;
    
    // 輸入驗證
    if (n <= 0 || m < 0) {
        cout << "錯誤：節點數量必須為正數，邊數量不能為負數！" << endl;
        return 1;
    }
    
    vector<vector<int>> adj(n);
    
    if (m > 0) {
        cout << "請輸入 " << m << " 條邊 (格式: u v):" << endl;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cout << "第 " << (i + 1) << " 條邊: ";
            cin >> u >> v;
            
            // 邊界檢查
            if (u < 0 || u >= n || v < 0 || v >= n) {
                cout << "錯誤：節點編號必須在 0 到 " << (n-1) << " 之間！" << endl;
                return 1;
            }
            
            // 避免自環
            if (u != v) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    vector<bool> visited(n, false);
    vector<int> max_component;
    int component_count = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, visited, component);
            component_count++;
            
            if (component.size() > max_component.size()) {
                max_component = component;
            }
        }
    }

    // 輸出結果
    cout << "\n=== 結果 ===" << endl;
    cout << "總共有 " << component_count << " 個連通分量" << endl;
    cout << "最大連通分量包含 " << max_component.size() << " 個節點" << endl;
    
    // 對結果排序，方便閱讀
    sort(max_component.begin(), max_component.end());
    
    cout << "最大連通分量的節點: ";
    for (size_t i = 0; i < max_component.size(); ++i) {
        cout << max_component[i];
        if (i < max_component.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}