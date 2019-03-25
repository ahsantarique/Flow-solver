#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
int b[8][8];
int mapr[8];
int mapc[8];
int bridgerow, bridgecol;

bool vis[8][8];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void printboard(){
	for(int i=0; i < 8; i++){
		for(int j=0; j < 8; j++){
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
}

int x;
bool done =false;

bool dfs(int u, int r, int c){
	cout << u << r <<c;
	getchar();
	if(u > x) {
		done =true;
		return true;
	}
	if(vis[r][c]==true) return false;
	vis[r][c]=true;

	if(r<0 || r >=8|| c<0 || c>=8) return false;
	// memset(vis,0, sizeof(vis));
	bool flag = false;
	for(int i=0; i < 4; i++){
		int nr = r+dx[i];
		int nc = c+dy[i];
		if(b[nr][nc]==0){
			b[nr][nc]=u;
			flag |= dfs(u,nr,nc);
		}
		if(b[nr][nc]==u){
			dfs(u+1,mapr[u+1],mapc[u+1]);
			return true;
		}
		if(done) return true;
	}
	return done;
}

int main()
{
	int n, m;
	// cin >> n >> m;
	cin >> x;
	n = 8, m = 8;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> b[i][j];
			mapr[b[i][j]]=i;
			mapc[b[i][j]]=j;
			if(b[i][j]==-1){
				bridgerow=i;
				bridgecol=j;
			}
		}
	}

	dfs(1,mapr[1],mapc[1]);

	return 0;
}