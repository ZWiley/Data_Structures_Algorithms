// 题目描述
// 给定一个 n 行 m 列的地牢，其中 '.' 表示可以通行的位置，'X' 表示不可通行的障碍，牛牛从 (x0 , y0 ) 位置出发，遍历这个地牢，和一般的游戏所不同的是，他每一步只能按照一些指定的步长遍历地牢，要求每一步都不可以超过地牢的边界，也不能到达障碍上。地牢的出口可能在任意某个可以通行的位置上。牛牛想知道最坏情况下，他需要多少步才可以离开这个地牢。
// 输入描述:

// 每个输入包含 1 个测试用例。每个测试用例的第一行包含两个整数 n 和 m（1 <= n, m <= 50），表示地牢的长和宽。接下来的 n 行，每行 m 个字符，描述地牢，地牢将至少包含两个 '.'。接下来的一行，包含两个整数 x0, y0，表示牛牛的出发位置（0 <= x0 < n, 0 <= y0 < m，左上角的坐标为 （0, 0），出发位置一定是 '.'）。之后的一行包含一个整数 k（0 < k <= 50）表示牛牛合法的步长数，接下来的 k 行，每行两个整数 dx, dy 表示每次可选择移动的行和列步长（-50 <= dx, dy <= 50）

// 输出描述:

// 输出一行一个数字表示最坏情况下需要多少次移动可以离开地牢，如果永远无法离开，输出 -1。以下测试用例中，牛牛可以上下左右移动，在所有可通行的位置.上，地牢出口如果被设置在右下角，牛牛想离开需要移动的次数最多，为3次。
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
 
int n,m;
int direction[55][2];
int dcnt;
char ground[55][55];
int dis[55][55];
 
struct Point{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point go(int idx){
        return Point(x+direction[idx][0],y+direction[idx][1]);
    }
    bool isOK(){
        return x>=0&&y>=0&&x<n&&y<m&&ground[x][y]=='.';
    }
};
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",ground[i]);
    }
    Point start;
    scanf("%d%d",&start.x,&start.y);
    scanf("%d",&dcnt);
    for(int i=0;i<dcnt;i++){
        scanf("%d%d",&direction[i][0],&direction[i][1]);
    }
    fill(dis[0],dis[54]+55,INT_MAX);
    dis[start.x][start.y]=0;
     
    queue<Point> q;
    q.push(start);
    while(!q.empty()){
        Point x=q.front();q.pop();
        for(int i=0;i<dcnt;++i){
            Point y=x.go(i);
            if(y.isOK()){
                if(dis[y.x][y.y]>dis[x.x][x.y]+1){
                    dis[y.x][y.y]=dis[x.x][x.y]+1;
                    q.push(y);
                }
            }
        }
    }
    int answer=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ground[i][j]=='.') answer=max(answer,dis[i][j]);
        }
    }
    printf("%d\n",answer==INT_MAX?-1:answer);
    return 0;
}