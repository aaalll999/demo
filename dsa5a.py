class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []
    
    def add_edge(self, u, v, w):
        self.graph.append([u, v, w])
    
    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])
        return parent[i]
    
    def union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        
        if xroot != yroot:
            if rank[xroot] < rank[yroot]:
                parent[xroot] = yroot
            elif rank[xroot] > rank[yroot]:
                parent[yroot] = xroot
            else:
                parent[yroot] = xroot
                rank[xroot] += 1
    
    def kruskal_mst(self):
        result = []
        i = 0
        e = 0
        
        self.graph = sorted(self.graph, key=lambda item: item[2])
        
        parent = []
        rank = []
        
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            
            x = self.find(parent, u)
            y = self.find(parent, v)
            
            if x != y:
                e = e + 1
                result.append([u, v, w])
                self.union(parent, rank, x, y)
        

        print("\nEdges in the Minimum Spanning Tree (Kruskal's Algorithm):")
        min_cost = 0
        for u, v, weight in result:
            print(f"{u} -- {v} == {weight}")
            min_cost += weight
        print("Minimum Spanning Tree Cost:", min_cost)

if __name__ == "__main__":
    g = Graph(5)
    g.add_edge(0, 1, 10)
    g.add_edge(0, 2, 8)
    g.add_edge(1, 2, 5)
    g.add_edge(1, 3, 3)
    g.add_edge(2, 3, 7)
    g.add_edge(2, 4, 6)
    g.add_edge(3, 4, 4)
    
    g.kruskal_mst()