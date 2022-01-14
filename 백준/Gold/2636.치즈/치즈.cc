#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> bfs;
int table[101][101];
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, -1, 1};
bool vs[101][101];
int X, Y, cnt, res, last;

int main(void) 
{
        scanf("%d %d", &X, &Y);
        for (int i = 0; i < X; i++)
                for (int j = 0; j < Y; j++)
                        scanf("%d", &table[i][j]);
        
        while (true) {
                for (int i = 0; i < X; i++)
                        for (int j = 0; j < Y; j++)
                                if (table[i][j] == 1) last++;

                if (last == 0) break;
                else {
                        cnt++;
                        res = last;
                }

                memset(vs, false, sizeof(vs));
                last = 0;

                bfs.push({0, 0});
                vs[0][0] = true;
                while (!bfs.empty()) {
                        auto a = bfs.front();
                        int x = a.first, y = a.second;

                        bfs.pop();

                        for (int i = 0; i < 4; i++) {
                                int nx = x + moveX[i];
                                int ny = y + moveY[i];

                                if (nx >=0 && ny >= 0 && nx < X && ny < Y && !vs[nx][ny]) {
                                        if (table[nx][ny] == 0)
                                                bfs.push({nx, ny});
                                        else if (table[nx][ny] == 1)
                                                table[nx][ny] = 0;

                                        vs[nx][ny] = true;
                                }
                        }
                }
        }
        printf("%d\n%d", cnt, res);
        return 0;
}