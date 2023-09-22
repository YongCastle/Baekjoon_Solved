import heapq

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        # Step 1) Initialize
        graph = collections.defaultdict(list)
        for u, v, w in times:
            graph[u].append((v,w))

        dist = collections.defaultdict(int)
        
        # Step 2) Dijkstra
        heap = []
        heapq.heappush(heap, (0, k))
        while heap:
            time, node = heapq.heappop(heap)
            if node not in dist:
                dist[node] = time
                for v, w in graph[node]:
                    alt = time + w
                    heapq.heappush(heap, (alt, v)) 
            
            #if node in dist, then already updated
        
        if len(dist) == n:
            return max(dist.values())
        return -1
            


                    




        dijstra()