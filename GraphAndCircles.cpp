bool valid(int maxx,int maxy,int r,vector<int> x,vector<int> y,int a,int b){
    if(a<0||b<0||a>maxx||b>maxy) return false;
    for(int i=0;i<x.size();i++){
        if(pow(y[i]-b,2)+pow(x[i]-a,2)<=r*r){
            return false;
        }
    }
    return true;
}

int canYou(int x,int y,int xt,int yt, int r,vector<int> xx,vector<int> yy, vector<vector<int>> visit){
    visit[x][y]=1;
    int sum=0;
    int dx[] = {1,1,0,-1,-1,-1,0,1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    if(x == xt && y == yt){
        return 1;
    }else if(valid(xt,yt,r,xx,yy,x,y)){
        for(int i=0;i<8;i++){
            if(visit[x+dx[i]][y+dy[i]]!=1)
            sum+=canYou(x+dx[i],y+dy[i],xt,yt,r,xx,yy,visit);
        }
      }
    return sum;
}


string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    int x,y,n,r;
    x=A;
    y=B;
    n=C;
    r=D;
    vector<int> xx(E),yy(F);
    vector<vector<bool>> visited(x+1,vector<bool>(y+1,false));
    //function cal
    queue <pair<int,int>> q;
    int dx[] = {1,1,0,-1,-1,-1,0,1};
    int dy[] = {0,1,1,1,0,-1,-1,-1};
    if(valid(x,y,r,xx,yy,0,0))q.push(make_pair(0,0));
    while(!q.empty()){
        int x1=q.front().first,y1= q.front().second;
        if(x1==x && y1==y){
            return "YES";
        }
        for(int i=0;i<8;i++){
            if(valid(x,y,r,xx,yy,x1+dx[i],y1+dy[i])&&visited[x1+dx[i]][y1+dy[i]]==false){
                q.push(make_pair(x1+dx[i],y1+dy[i]));
            
                visited[x1+dx[i]][y1+dy[i]]=true;
            }
        }
        q.pop();
    }
    return "NO";
 
    
}