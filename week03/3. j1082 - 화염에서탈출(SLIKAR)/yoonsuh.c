#include <stdio.h>

#define MAX 100

typedef struct {
    int r, c;
} Node;

char map[MAX][MAX];
int fire_time[MAX][MAX]; // 불이 도달하는 시간
int s_time[MAX][MAX];    // 재우가 이동하는 시간
int R, C;

Node fireQueue[MAX*MAX];
Node sQueue[MAX*MAX];
int f_front=0, f_rear=0;
int s_front=0, s_rear=0;

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int main() {
    scanf("%d %d", &R, &C);
    Node dest;

    for(int i=0;i<R;i++){
        scanf("%s", map[i]);
        for(int j=0;j<C;j++){
            fire_time[i][j] = -1;
            s_time[i][j] = -1;
            if(map[i][j]=='*') {
                fireQueue[f_rear++] = (Node){i,j};
                fire_time[i][j] = 0;
            } else if(map[i][j]=='S') {
                sQueue[s_rear++] = (Node){i,j};
                s_time[i][j] = 0;
            } else if(map[i][j]=='D') {
                dest = (Node){i,j};
            }
        }
    }

    // 1. 불 BFS
    while(f_front < f_rear){
        Node curr = fireQueue[f_front++];
        for(int i=0;i<4;i++){
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if(nr<0 || nr>=R || nc<0 || nc>=C) continue;
            if(map[nr][nc]=='X' || map[nr][nc]=='D') continue;
            if(fire_time[nr][nc] != -1) continue;
            fire_time[nr][nc] = fire_time[curr.r][curr.c] + 1;
            fireQueue[f_rear++] = (Node){nr,nc};
        }
    }

    // 2. 재우 BFS
    while(s_front < s_rear){
        Node curr = sQueue[s_front++];
        for(int i=0;i<4;i++){
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if(nr<0 || nr>=R || nc<0 || nc>=C) continue;
            if(map[nr][nc]=='X') continue;
            if(s_time[nr][nc] != -1) continue;
            if(fire_time[nr][nc]!=-1 && fire_time[nr][nc] <= s_time[curr.r][curr.c]+1) continue;
            s_time[nr][nc] = s_time[curr.r][curr.c]+1;
            sQueue[s_rear++] = (Node){nr,nc};
        }
    }

    if(s_time[dest.r][dest.c]==-1)
        printf("impossible\n");
    else
        printf("%d\n", s_time[dest.r][dest.c]);

    return 0;
}
