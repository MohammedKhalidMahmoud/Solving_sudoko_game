#include <iostream>
#include <cmath>
#define N 4
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
        //grid[i][j]=0;
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
    {1,0,3,0},
    {0,0,2,1},
    {0,1,0,2},
    {2,4,0,0}   // i=N & j=N
    };
    if (solve(grid)){
        print_grid(grid);
    }
    else
        cout<<"No solution exists";
    return 0;
}

/*

bool isSafe(int grid[N][N],int row,int col){
  for(int i=0;i<col;i++)
    if(grid[row][i]==1) return false;

  for(int i=row,j=col; i>=0 && j>=0; i--,j--)
    if(grid[i][j]==1) return false;

  for(int i=row,j=col; i<N && j>=0; i++,j--)
    if(grid[i][j]==1) return false;

  return true;
}

bool solve(int grid[N][N],int col){
    if(col==N) return true;
    for(int i=0;i<N;i++){
        if(isSafe(grid,i,col)){
           grid[i][col]=1;
           if(solve(grid,col+1)) return true;
           // grid[i][col]=0;
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
int main(){
    int grid[N][N]={
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };
if(solve(grid,0)){
    print_grid(grid);
}
else
    cout<<"There is no solution";
return 0;
}

*/
