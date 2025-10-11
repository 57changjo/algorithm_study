#include <stdio.h>
#include <string.h>

#define MAXN 3100  // 충분히 큰 배열 크기 왜냐 최대가 3072이기 때문에 3100로 함

char board[MAXN][MAXN*2]; // 별 그리기 가로 세로라고 생각하고 세로가 2배로 생각함.

//꼭대기 위치 (r, c)가 삼각형 가운데 꼭대기 별 위치
//r=삼각형 꼭대기 행, c=삼각형 꼭대기 열
//  *    <-board[r][c]  기준으로 생각
// * *   <-board[r+1][c-1],board[r+1][c+1]
//*****  <-board[r+2][c-2],board[r+2][c+2] 이런식!
//위에 그림처럼 하려면 밑에가 기본단위 그림이야 최소 단위!!
//N이 3이라면 이렇게 그러짐 기본단위
void star(int r, int c) {
    board[r][c] = '*';
    board[r+1][c-1] = '*';
    board[r+1][c+1] = '*';
    for (int i = -2; i <= 2; i++) {
        board[r+2][c + i] = '*';     //이건 기본 삼각형의 맨아래줄은 가운데를 기준으로 2칸씩 별을 찍어서 5를 만듦.
    }
}

//r, c =꼭대기 별의 위치 좌표, size = 높이
void draw(int r, int c, int size) {
    if (size == 3) {
        star(r, c);
        return;
    }
    int half = size / 2;
    // 꼭대기
    draw(r, c, half);
    // 왼쪽 아래 삼각형
    draw(r + half, c - half, half);
    // 오른쪽 아래 삼각형
    draw(r + half, c + half, half);
}

int main() {
    int N;
    scanf("%d", &N);
    int width = 2 * N - 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = ' ';
        }
        board[i][width] = '\0';  
    }

  
    draw(0, width/2, N);


    for (int i = 0; i < N; i++) {
        printf("%s\n", board[i]);
    }
    return 0;
}
