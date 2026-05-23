#include <iostream>
#include <vector>

class Solution {

  public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        
      int count = 0;
      int numLines = grid.size();
      int numColumns = grid[0].size();

      for(int i = 0; i < numLines; i++){
        for(int j = 0; j < numColumns; j++){

          if(grid[i][j] == '1'){
            dfs(grid, i, j, numLines, numColumns);
            count++;
          }
        }
      }

      return count;
    }

    void dfs(std::vector<std::vector<char>>& grid, int i, int j, int &numLines, int &numColumns){

      if(i < 0 || i >= numLines || j < 0 || j >= numColumns || grid[i][j] != '1'){
        return;
      }

      grid[i][j] = '0';

      dfs(grid, i + 1, j, numLines, numColumns);
      dfs(grid, i, j + 1, numLines, numColumns);
      dfs(grid, i - 1, j, numLines, numColumns);
      dfs(grid, i, j - 1, numLines, numColumns);
    }
};

int main() {

  return 0;
}
