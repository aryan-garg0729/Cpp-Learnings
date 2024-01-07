//      *----------------- N-QUEEN PROBLEM --------------*

#include<bits/stdc++.h>
using namespace std;
/*
int queen[11][11];

bool isPossible(int n,int row,int col){
    // vertically
    for(int i = row;i>=0;i--){
        for(int j = 0;j<n;j++){
            if(queen[i][col] == 1){
                return false;
            }
        }
    }
    // diagonally
    for(int i = row-1,j = col-1;i>=0 && j>=0;i--,j--){
        if(queen[i][j] == 1){
            return false;
        }
    }
    
    for(int i = row-1,j = col+1;i>=0 && j<n;i--,j++){
        if(queen[i][j] == 1){
            return false;
        }
    }
    return true;
    
}

void helper(int n,int row){
    if(row == n){
        //print
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<queen[i][j]<<" ";
            }
            
        }
        cout<<endl;
        return;
    }
    for(int i = 0;i<n;i++){
        if(isPossible(n,row,i)){
            queen[row][i] = 1;
        	helper(n,row+1);
        }
        queen[row][i] = 0;
    }
    return;
}
void nQueen(int n,int row){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            queen[i][j] = 0;
        }
    }
    helper(n,0);
    return;
}

int main(){
    int n;
    cin>>n;
    nQueen(n,0);
    return 0;
}*/





//      *----------------- RAT IN A MAZE PROBLEM --------------*
/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/

                        // My Sol
/*#include<bits/stdc++.h>
using namespace std;
int path[18][18];

void helper(int n,int row,int col,int**inp){
    if(row == n-1 && col == n-1){
        path[row][col] = 1;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<path[i][j]<<" ";
            }
        }
        cout<<endl;
        path[row][col] = 0;
        return;
    }
    path[row][col] = 1;
    if(row-1>-1 && path[row-1][col]^inp[row-1][col]){
        helper(n,row-1,col,inp);
    }
    if(row+1<n && path[row+1][col]^inp[row+1][col]){
        helper(n,row+1,col,inp);
    }
    if(col-1>-1 && path[row][col-1]^inp[row][col-1]){
        helper(n,row,col-1,inp);
    }
    if(col+1<n && path[row][col+1]^inp[row][col+1]){
        helper(n,row,col+1,inp);
    }
    path[row][col] = 0;
    return;
    
    
}

void ratInMaze(int n,int**inp){
    
    for(int i = 0;i<18;i++){
        for(int j = 0;j<18;j++){
            path[i][j] = 0;
        }
    }
    helper(n,0,0,inp);
    return;
}

int main() {
	int n;
    cin>>n;
    
    //taking input matrix
    int* *inp = new int*[n];
    for(int i = 0;i<n;i++){
        inp[i] = new int[n];
        for(int j = 0;j<n;j++){
            cin>>inp[i][j];
        }
    }
    
    ratInMaze(n,inp);
    
	return 0;
}*/

                        // ninja sol
/*#include<bits/stdc++.h>
using namespace std;


void printSolution(int** solution,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << solution[i][j] << " ";
		}
	}
	cout<<endl;
}
void mazeHelp(int maze[][20],int n,int** solution,int x,int y){


	if(x == n-1 && y == n-1){
		solution[x][y] =1;
		printSolution(solution,n);
      	solution[x][y] =0;
		return;
	}
	if(x>=n || x<0 || y>=n || y<0 || maze[x][y] ==0 || solution[x][y] ==1){
		return;
	}
	solution[x][y] = 1;
	mazeHelp(maze,n,solution,x-1,y);
	mazeHelp(maze,n,solution,x+1,y);
	mazeHelp(maze,n,solution,x,y-1);
	mazeHelp(maze,n,solution,x,y+1);
	solution[x][y] = 0;
}
void ratInAMaze(int maze[][20], int n){

  int** solution = new int*[n];
  for(int i=0;i<n;i++){
  	solution[i] = new int[n];
  }
  for(int i=0; i<n; i++){
        memset(solution[i], 0, n*sizeof(int));
  }
  mazeHelp(maze,n,solution,0,0);

}
int main(){
	int n;
    cin>>n;
    
    //taking input matrix
    int inp[20][20];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>inp[i][j];
        }
    }
    
    ratInAMaze(inp,n);
}*/

//test cases:-
/*
3
1 1 1 
1 1 0 
0 1 1

3
1 0 1 
1 1 1 
1 0 1 

2
1 1 
1 1 
*/





//      *-----------------SUDOKU PROBLEM --------------*
#include<bits/stdc++.h>
using namespace std;
#define n 9
bool findEmptyLocation(int grid[][n],int & row,int & col){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(grid[i][j]==0){
                row = i;
                col = j;
                return true;
            }
        }
    }
}

bool isSafe(int grid[][n],int row,int col,int num){
    //is safe row
    for(int i = 0;i<n;i++){
        if(grid[row][i]==num){
            return false;
        }
    }
    
    //is safe col
    for(int i = 0;i<n;i++){
        if(grid[i][col]==num){
            return false;
        }
    }
    
    //is safe grid 3X3
    for(int i = 0;i<3;i++){
        for(int j =0;j<3;j++){
            if(grid[i+row-(row%3)][j+col-(col%3)]==num){
                return false;
            }
        }
    }
    
    return true;
    
}

bool solveSudoku(int grid[][n]){
    int row,col;
    if(!findEmptyLocation(grid,row,col)){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    for(int i = 1;i<=n;i++){
        if(isSafe(grid,row,col,i)){
            grid[row][col] = i;
            if(solveSudoku(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    int grid[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<endl;
    solveSudoku(grid)?cout<<"true":cout<<"false";
    return 0;
}
//TEST CASES:-
/*
3 0 5 4 2 0 8 1 0 
4 8 7 9 0 1 5 0 6 
0 2 9 0 5 6 3 7 4 
8 5 0 7 9 3 0 4 1 
6 1 3 2 0 8 9 5 7 
6 1 3 2 0 8 9 5 7 
0 7 4 0 6 5 2 8 0 
2 4 1 3 0 9 0 6 5 
5 0 8 6 7 0 1 9 2

9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

0 0 0 0 4 8 0 9 7
7 0 0 5 0 1 0 0 3
0 6 0 0 0 0 0 4 0
0 9 0 0 0 0 8 1 0
8 0 4 1 9 2 3 7 0
6 1 7 0 3 4 5 2 0
0 0 0 0 5 0 0 0 1
0 3 6 4 0 9 0 0 0
4 0 5 0 0 0 0 3 0
*/

//      *-----------------CROSSWORD PROBLEM --------------*




//      *-----------------SUBSET SUM PROBLEM --------------*
/*long long subsetSum(long long *arr,long long n,long long k, long long count){
    if(n==0){
        if(k==0) count++;
        return count;
    }
    
    count =subsetSum(arr+1,n-1,k-arr[0],count);
    count =subsetSum(arr+1,n-1,k,count);
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
            long long *arr = new long long[n];
            for(int i = 0;i<n;i++){
                cin>>arr[i];
            }
            cout<<subsetSum(arr,n,k,0)<<endl;
    }
    return 0;
}*/


