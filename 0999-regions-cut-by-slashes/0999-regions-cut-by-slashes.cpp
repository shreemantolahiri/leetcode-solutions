class Solution {
    public:
    class DSU{
        public:
        int n;
        vector<int> par;
        vector<int> siz;
        DSU(int m){
            n=m;
            par.resize(n);
            siz.resize(n,1);

            for(int i=0;i<n;i++){
                par[i]=i;
            }
        }

        int findUPar(int u){
            if(par[u]==u) return u;

            return par[u]=findUPar(par[u]);
        }

        void unionBySize(int u,int v){
            int ulpU=findUPar(u);
            int ulpV=findUPar(v);

            if(ulpU==ulpV) return;

            if(siz[ulpV]>siz[ulpU]){
                siz[ulpV]+=siz[ulpU];
                par[ulpU]=ulpV;
            }
            else{
                siz[ulpU]+=siz[ulpV];
                par[ulpV]=ulpU;
            }

            return;
        }
    };
    int getCode(char ch){
        if(ch==' ') return 0;
        else if(ch=='/') return 1;
        else return 2;
    }
    int regionsBySlashes(vector<string>& grid) {
        //there will be n*2 mini boxes
        int n=grid.size();

        

        
        int m=n*n*4;
        // return m;
        DSU d(m);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int num=(i*n)+j;

                int first=4*num;
                int second=4*num+1;
                int third=4*num+2;
                int fourth=4*num+3;
                int code=getCode(grid[i][j]);

                if(code==0){
                    //merge the regions
                    d.unionBySize(first,second);
                    d.unionBySize(third,fourth);
                    d.unionBySize(first,third);
                    d.unionBySize(second,fourth);
                }
                else if(code==1){
                    // means its is "/"
                    d.unionBySize(first,second);
                    d.unionBySize(third,fourth);
                }
                else{
                    // it is "\"
                    d.unionBySize(fourth,second);
                    d.unionBySize(third,first);
                }
                //we check in left and up
                //left
                if(j>0){
                    d.unionBySize(first,first-1);
                }

                //up
                if(i>0){
                    // int upCode=getCode(grid[i-1][j]);
                    int upIndex=(((i-1)*n)+j)*4+2;
                    // int upDown=((i-1)*n)+j+2;
                    
                    //merge with up
                    d.unionBySize(upIndex,second);
                    
                }
            }
        }

        int count=0;
        // cout<<m<<endl;
        for(int i=0;i<m;i++){
            // cout<<"i= "<<i<<" par="<<d.par[i]<<" size="<<d.siz[i]<<endl;
            
            if(d.par[i]==i) count++;
        }

        return count;
    }
};