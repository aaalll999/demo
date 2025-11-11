import sys

V = 5 
def min_key(key, mst_set):
    min_val = sys.maxsize
    min_index = -1
    for v in range(V):
        if key[v] < min_val and not mst_set[v]:
            min_val = key[v]
            min_index = v
    return min_index

def prim_mst(graph):
    key = [sys.maxsize] * V
    parent = [None] * V
    key[0] = 0
    mst_set = [False] * V
    parent[0] = -1

    for _ in range(V - 1):
        u = min_key(key, mst_set)
        mst_set[u] = True

        for v in range(V):
            if graph[u][v] and not mst_set[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u

    total_cost = 0
    print("Edges in the Minimum Spanning Tree (Prim's Algorithm):")
    for i in range(1, V):
        print(f"{parent[i]} -- {i} == {graph[i][parent[i]]}")
        total_cost += graph[i][parent[i]]
    print("Minimum Spanning Tree Cost:", total_cost)

graph = [
    [0, 2, 8, 0, 0],
    [2, 0, 5, 3, 0],
    [8, 5, 0, 0, 6],
    [0, 3, 0, 0, 0],
    [0, 0, 6, 0, 0]
]

prim_mst(graph)
