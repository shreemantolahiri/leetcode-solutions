class Solution {
    class Pair {
    int first, second;
    Pair(int f, int s) {
        this.first = f;
        this.second = s;
    }
}
    public int closestMeetingNode(int[] edges, int node1, int node2) {

        int n = edges.length;
        int[] n1_dist = new int[n], n2_dist = new int[n];
        for (int i = 0; i < n; i++) {
            n1_dist[i] = Integer.MAX_VALUE;
            n2_dist[i] = Integer.MAX_VALUE;
        }
        n1_dist[node1]=0; n2_dist[node2]=0;
        Queue<Pair> q= new LinkedList<>();

        //for node 1
        q.offer(new Pair(node1,0));
        while(!q.isEmpty()){
            Pair p=q.poll();
            int node=p.first;
            int distance=p.second;
            int destNode=edges[node];
            
            if(destNode==-1) continue; //end of graph
            else{
                if(n1_dist[destNode]<distance+1) continue;
                else{
                    n1_dist[destNode]=distance+1;
                    q.offer(new Pair(destNode,distance+1));
                }
            }

        }

        //for second node
        q.offer(new Pair(node2,0));
        while(!q.isEmpty()){
            Pair p=q.poll();
            int node=p.first;
            int distance=p.second;
            int destNode=edges[node];
            
            if(destNode==-1) continue; //end of graph
            else{
                if(n2_dist[destNode]<distance+1) continue;
                else{
                    n2_dist[destNode]=distance+1;
                    q.offer(new Pair(destNode,distance+1));
                }
            }
        }


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