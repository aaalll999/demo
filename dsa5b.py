import sys

class Graph:
    def _init_(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def print_mst(self, parent):
        print("\nEdges in Minimum Spanning Tree:")
        total = 0
        for i in range(1, self.V):
            print(f"Department {parent[i]} -- {i}  Distance = {self.graph[i][parent[i]]}")
            total += self.graph[i][parent[i]]
        print("Total Distance of MST:", total)

    def min_key(self, key, mstSet):
        min_val = sys.maxsize
        for v in range(self.V):
            if key[v] < min_val and not mstSet[v]:
                min_val = key[v]
                min_index = v
        return min_index

    def prim_mst(self):
        key = [sys.maxsize] * self.V
        parent = [None] * self.V
        key[0] = 0
        mstSet = [False] * self.V
        parent[0] = -1

        for _ in range(self.V):
            u = self.min_key(key, mstSet)
            mstSet[u] = True
            for v in range(self.V):
                if self.graph[u][v] and not mstSet[v] and self.graph[u][v] < key[v]:
                    key[v] = self.graph[u][v]
                    parent[v] = u

        self.print_mst(parent)
g = Graph(5)
g.graph = [
    [0, 10, 6, 5, 0],   
    [10, 0, 0, 15, 0], 
    [6, 0, 0, 4, 0],    
    [5, 15, 4, 0, 8],   
    [0, 0, 0, 8, 0]     
]

g.prim_mst()

