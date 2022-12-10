/// *** BFS in 2D Grid [edge + node]

int lev[MX][MX],m,n;
bool vs[MX][MX];
char st[MX][MX];
int dx[]={1,-1,0, 0, 1,1,};
int dy[]={0, 0,1,-1,-1, };

int bfs(int fx,int fy) /// starting position
{
    int i,v,x,y,md=0;
    queue <pii> q;
    pii pr;
    vs[fx][fy]=1;
    lev[fx][fy]=0;
    q.push(pii(fx,fy));
    while(!q.empty()){
        pr=q.front();
        fx=pr.first;
        fy=pr.second;
        q.pop();
        for(i=0;i<4;i++){
            x=fx+dx[i];
            y=fy+dy[i];
            if(x<0||x>=n||y<0||y>=m)continue; /// for zero based index
            if(!vs[x][y]&&st[x][y]!='#'){ /// # is blocked
                q.push(pii(x,y));
                vs[x][y]=1;
                lev[x][y]=lev[fx][fy]+1;
                if(st[x][y]=='d'){ /// d is destinition
                    md=max(md,lev[x][y]);
                }

            }
        }

    }
    return md;/// max distance of d

}

