from queue import PriorityQueue
import sys


class Graph(): 
    # vertices -> number of vertices
    # edges -> matrix mapping the weight between all vertice to vertice combinations
    def __init__(self, vertices, edges):
        self.V = vertices
        self.edges = edges
        self.distances = [sys.maxint for column in range(vertices)]
    
    # start -> initial vertice
    # end -> destination vertice
    def dijkstra(self,start, end):
        self.distances[start] = 0

        q = PriorityQueue()
        q.put((0, start))

        while q:
            vertice = q.get()
            current = vertice[1]
            currWeight = vertice[0]
            if currWeight > self.distances[current]:
                continue
    
            for i in range(self.V):
                weight = self.edges[current][i]

      
                if self.distances[current] + weight < self.distances[i]:
                    self.distances[i] = self.distances[current] + weight
                    q.put((self.distances[i], i))
        
        return self.distances[end] if self.distances[end] < sys.maxtint else -1