#include <stdio.h>

struct Edge {
    int u, v, w;
};

int parent[100], rankArr[100];

// Find function for DSU
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union function for DSU
void unionSet(int a, int b) {
    a = find(a);
    b = find(b);

    if (rankArr[a] < rankArr[b])
        parent[a] = b;
    else if (rankArr[b] < rankArr[a])
        parent[b] = a;
    else {
        parent[b] = a;
        rankArr[a]++;
    }
}

int main() {
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge edges[100];

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    // Initialize DSU
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }

    // Sort edges by weight (simple bubble sort)
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (edges[i].w > edges[j].w) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    printf("\nMinimum Spanning Tree (Using Kruskal):\n");
    int mstCost = 0, count = 0;

    for (int i = 0; i < m && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v)) {
            printf("%d -- %d  (Weight %d)\n", u, v, w);
            mstCost += w;
            unionSet(u, v);
            count++;
        }
    }

    printf("Total cost of MST = %d\n", mstCost);

    return 0;
}
