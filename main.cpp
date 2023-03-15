#include <iostream>
#include <cmath>
#define N 9
using namespace std;

 bool isSafe(int grid[N][N],int i,int j,int c){
  for(int k=0;k<N;k++){
    if(grid[i][k]==c || grid[k][j]==c) return false;
  }
        int s = (int)sqrt(N); // s=2
        int boxRowStart = i - (i % s);
        int boxColStart = j - (j % s);

        for (int r = boxRowStart;r < boxRowStart + s; r++)
        {
            for (int d = boxColStart;d < boxColStart + s; d++)
            {
                if (grid[r][d] == c) return false;
            }
        }
    return true;
  }

bool solve(int grid[N][N]){
 int i;
 int j;

  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
        if(grid[i][j]==0) goto label;
    }
 }
 label:
 if(i==N && j==N) return true;

 for(int c=1;c<=N;c++){
    if(isSafe(grid,i,j,c)){
        grid[i][j]=c;
        if(solve(grid))
            return true;
        grid[i][j]=0;
    }
 }
 return false;
}

void print_grid(int grid[N][N]){
 for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
        cout<<grid[i][j]<<" ";
    }
    cout<<"\n";
 }
}
int main()
{
    //int N=4;
    int grid[N][N]={
        {0,0,0,0,7,0,0,0,0},
        {0,9,0,5,0,6,0,8,0},
        {0,0,8,4,0,1,2,0,0},
        {0,5,9,0,0,0,8,4,0},
        {7,0,0,0,0,0,0,0,6},
        {0,2,3,0,0,0,5,7,0},
        {0,0,5,3,0,7,4,0,0},
        {0,1,0,6,0,8,0,9,0},
        {0,0,0,0,1,0,0,0,0}  // i=N & j=N
    };
    if (solve(grid)){
        print_grid(grid);
    }
    else
        cout<<"No solution exists";
    return 0;
}


// Sudoko Problems

/*
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
*/

/*
    {0,0,0,0,7,0,0,0,0},
    {0,9,0,5,0,6,0,8,0},
    {0,0,8,4,0,1,2,0,0},
    {0,5,9,0,0,0,8,4,0},
    {7,0,0,0,0,0,0,0,6},
    {0,2,3,0,0,0,5,7,0},
    {0,0,5,3,0,7,4,0,0},
    {0,1,0,6,0,8,0,9,0},
    {0,0,0,0,1,0,0,0,0}
*/

/*
    {6,0,0,0,0,9,0,0,0},
    {0,0,0,0,0,0,0,0,4},
    {0,0,7,6,4,8,0,0,2},
    {0,0,2,0,5,0,8,0,0},
    {0,0,1,8,0,0,0,2,3},
    {7,0,4,0,0,0,0,0,0},
    {0,0,0,3,0,0,0,4,0},
    {0,0,0,0,6,0,5,0,0},
    {0,2,3,0,1,0,0,0,0}
*/
