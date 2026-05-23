#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        
        int lineCount = board.size();
        int colCount = board[0].size();

        for(int i = 0; i < colCount; i++){
          if(board[0][i] == 'O'){
            dfs(board, 0, i);
          }
        }

        for(int i = 0; i < lineCount; i++){
          if(board[i][0] == 'O'){
            dfs(board, i, 0);
          }
        }

        for(int i = 0; i < lineCount; i++){
          if(board[i][colCount - 1] == 'O'){
            dfs(board, i, colCount - 1);
          }
        }

        for(int i = 0; i < colCount; i++){
          if(board[lineCount - 1][i] == 'O'){
            dfs(board, lineCount - 1, i);
          }
        }

        for(int i = 0; i < lineCount; i++){
          for(int j = 0; j < colCount; j++){
            if (board[i][j] == 'O'){
              board[i][j] = 'X';
            }
          }
        }

        for(int i = 0; i < lineCount; i++){
          for(int j = 0; j < colCount; j++){
            if (board[i][j] == '#'){
              board[i][j] = 'O';
            }
          }
        }
    }

    void dfs(std::vector<std::vector<char>>& board, int i, int j){

      int m = board.size(), n = board[0].size();
      if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O'){
        return;
      }

      if(board[i][j] == 'O'){
        board[i][j] = '#';
      } else {
        return;
      }

      dfs(board, i + 1, j);
      dfs(board, i, j + 1);
      dfs(board, i - 1, j);
      dfs(board, i, j - 1);
    }
};

int main() {

  return 0;
}
