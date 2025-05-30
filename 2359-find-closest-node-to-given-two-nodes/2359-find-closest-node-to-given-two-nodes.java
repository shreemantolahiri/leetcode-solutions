class Solution {
    /*
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     * n = number of nodes in edges array
     */
    
    // BFS to compute shortest distances from start node to all reachable nodes
    void BFS(int[] edges, int[] dist, int start) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);

        while (!q.isEmpty()) {
            int node = q.poll();
            int distance = dist[node];
            int destNode = edges[node];

            if (destNode == -1) continue; // no outgoing edge
            if (dist[destNode] <= distance + 1) continue; // already visited with shorter distance

            dist[destNode] = distance + 1;
            q.offer(destNode);
        }
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;
        int[] n1_dist = new int[n], n2_dist = new int[n];
        Arrays.fill(n1_dist, Integer.MAX_VALUE);
        Arrays.fill(n2_dist, Integer.MAX_VALUE);

        n1_dist[node1] = 0;
        n2_dist[node2] = 0;

        BFS(edges, n1_dist, node1);
        BFS(edges, n2_dist, node2);

        int minDist = Integer.MAX_VALUE;
        int minIndex = -1;

        for (int i = 0; i < n; i++) {
            if (n1_dist[i] != Integer.MAX_VALUE && n2_dist[i] != Integer.MAX_VALUE) {
                int maxDist = Math.max(n1_dist[i], n2_dist[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    minIndex = i;
                }
            }
        }

        return minIndex;
    }
}
