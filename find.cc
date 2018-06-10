#include <iostream>
using namespace std;

#define SIZE 10
//number of tables to find
#define NFIND 3
int cnt = NFIND;

void tprint(int a[][SIZE]){
  cout << "Result " << (NFIND - cnt + 1) << endl;
  for(int row = 0; row < SIZE; row++){
    for(int col = 0; col < SIZE; col ++)
    cout << a[row][col] << " ";
    cout << endl;
    //print for latex
    //cout << row;
    //for(int col = 0; col < SIZE; col ++)
      //cout << " & " << a[row][col];
    //cout << "\\\\\n\\hline\n";
  }
  cout << endl;
}
bool f(int a[][SIZE], int row, int col, int val){
  if (!cnt) return false;
  a[row][col] = val;
  int nrow, ncol;
  if (col < SIZE - 1){
    ncol = col + 1;
    nrow = row;
  } else if (row < SIZE - 1){
      ncol = 0;
      nrow = row + 1;
    } else {
      bool found = false;
      for(int i = 0; i < SIZE; i++)
        if (a[i][i] != i){
          found = true;
          break;
        }
      if (!found) return false;
      tprint(a);
      cnt--;
      return !cnt;
    }
  bool checked[SIZE];
  fill(checked, checked + SIZE * sizeof(bool), false);
  for(int i = 0; i < ncol; i++)
    checked[a[nrow][i]] = true;
  for(int i = 0; i < nrow; i++)
    checked[a[i][ncol]] = true;
  for(int v = 0; v < SIZE; v++)
    if (!checked[v] && f(a, nrow, ncol, v))
      return true;
  return false;
}

int main(){
  int a[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++)
    f(a, 0, 0, i);
  if (cnt == NFIND)
    cout << "not found" << endl;
  return 0;
}
