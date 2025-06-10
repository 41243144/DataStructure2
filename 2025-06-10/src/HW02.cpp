#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

// 邊的結構
struct Edge {
    int u, v;
    double weight;
    
    Edge(int u, int v, double weight) : u(u), v(v), weight(weight) {}
    
    // 用於排序
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 城市座標結構
struct City {
    double x, y;
    
    City(double x = 0, double y = 0) : x(x), y(y) {}
    
    // 計算兩點間距離
    double distance(const City& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

// Union-Find (並查集) 類別
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // 路徑壓縮
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return false;
        
        // 按秩合併
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        
        return true;
    }
};

// Kruskal's 最小生成樹算法
double kruskalMST(vector<City>& cities) {
    int n = cities.size();
    vector<Edge> edges;
    
    // 建立所有可能的邊
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = cities[i].distance(cities[j]);
            edges.emplace_back(i, j, dist);
        }
    }
    
    // 按權重排序
    sort(edges.begin(), edges.end());
    
    UnionFind uf(n);
    double totalCost = 0.0;
    int edgesUsed = 0;
    
    // Kruskal算法主體
    for (const Edge& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            totalCost += edge.weight;
            edgesUsed++;
            
            // MST需要 n-1 條邊
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }
    
    return totalCost;
}

int main() {
    int n;
    
    // 提示輸入
    cout << "請輸入城市數量: ";
    cin >> n;
    
    // 輸入驗證
    if (n <= 0 || n > 100) {
        cout << "錯誤：城市數量必須在 1 到 100 之間！" << endl;
        return 1;
    }
    
    vector<City> cities(n);
    
    cout << "請輸入 " << n << " 個城市的座標 (格式: x y):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "第 " << (i + 1) << " 個城市: ";
        cin >> cities[i].x >> cities[i].y;
    }
    
    // 計算最小生成樹
    double minTotalDistance = kruskalMST(cities);
    
    // 輸出結果
    cout << "\n=== 結果 ===" << endl;
    cout << "連接所有城市的最短總距離: " << fixed << setprecision(3) << minTotalDistance << endl;
    
    return 0;
}
