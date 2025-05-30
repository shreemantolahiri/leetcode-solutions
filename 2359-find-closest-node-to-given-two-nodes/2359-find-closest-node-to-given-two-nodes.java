class Solution {
    void BFS(int[] edges, int dist[],int start){
        Queue<Integer> q= new LinkedList<>();

        q.offer(start);
        while(!q.isEmpty()){
            int node=q.poll();
            int distance=dist[node];
            int destNode=edges[node];
            
            if(destNode==-1) continue; //end of graph
            else{
                if(dist[destNode]<=distance+1) continue;
                else{
                    dist[destNode]=distance+1;
                    q.offer(destNode);
                }
            }

        }
    }
    public int closestMeetingNode(int[] edges, int node1, int node2) {

        int n = edges.length;
        int[] n1_dist = new int[n], n2_dist = new int[n];
        Arrays.fill(n1_dist,Integer.MAX_VALUE);
        Arrays.fill(n2_dist,Integer.MAX_VALUE);
        n1_dist[node1]=0; n2_dist[node2]=0;

        BFS(edges,n1_dist,node1);
        BFS(edges,n2_dist,node2);

        //find min distance
        int minDist=Integer.MAX_VALUE;
        int minIndex=-1;
        for(int i=0;i<n;i++){
            // System.out.println(n1_dist[i]+" "+n2_dist[i]);
            if(n1_dist[i]!=Integer.MAX_VALUE && n2_dist[i]!=Integer.MAX_VALUE){

                if(minDist>Math.min(minDist,Math.max(n1_dist[i],n2_dist[i]))){
                    minDist=Math.min(minDist,Math.max(n1_dist[i],n2_dist[i]));
                    minIndex=i;
                }
            }
        }

        return minIndex;
    }
}