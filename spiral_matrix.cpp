#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cout << "please input n: " << endl;
	cin >> n;
	vector<vector<int> > mat(n, vector<int>(n,0));
	vector<vector<int> > direction(4,vector<int>(2,0));
	direction[0][0] = 0;
	direction[0][1] = 1;
	direction[1][0] = 1;
	direction[1][1] = 0;
	direction[2][0] = 0;
	direction[2][1] = -1;
	direction[3][0] = -1;
	direction[3][1] = 0;
	int dir = 0;
	int row = 0;
	int col = 0;
	for(int i = 1; i < n*n + 1; i++){
		mat[row][col] = i;
		int newrow = row + direction[dir][0];
		int newcol = col + direction[dir][1];
		if(newrow > n - 1 || newcol > n - 1 || newrow < 0 || newcol < 0 || mat[newrow][newcol] > 0){
			dir = (dir + 1) % 4;
		}
		row = row + direction[dir][0];
		col = col + direction[dir][1];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout <<" "<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}