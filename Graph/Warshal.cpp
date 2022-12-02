/**
    Name : Warshal Algorithm

    he key idea to notice here is that, we go through all
    the nodes and for each node we try to make every path
    better by going through that. Hence, Floyd Warshall can add vertex online.
    n^2 loop can add this.

    Time Complexity : O(n^3)

*/


int mtx[102][102],n;//intialize with inf;
int next[102][102];//for finding path only
void wrsl()
{
    int i,j,k;
    for(i=1;i<=n;i++){//for finding path only
        for(j=1;j<=n;j++){
            next[i][j]=j;
        }
    }

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(mtx[i][j]>mtx[i][k]+mtx[k][j]){
                    mtx[i][j]>mtx[i][k]+mtx[k][j];
                    next[i][j]=next[i][k];//for finding path only
                }
            }
        }
    }
}
//finding path using warshal, i to j
vector <int> path;
void findpath(int i,int j)
{
    path.clear();
    path.push_back(i);
    while(i!=j){
        i=next[i][j];
        path.push_back(i);
    }
}
