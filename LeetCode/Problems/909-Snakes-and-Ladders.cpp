#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        
      int n = board.size();
      int N = n * n;

      std::vector<int> dest(N, -1);

      for(int s = 0; s < N; s++){

        int r = s / n;
        int row = n - 1 - r;
        int col;

        if(r % 2 == 0){
          col = s % n;
        } else {
          col = n - 1 - (s % n);
        }

        if(board[row][col] != -1){
          dest[s] = board[row][col] - 1;
        }
      }

      std::queue<int> q;
      std::vector<int> dist(N, -1);
      q.push(0);
      dist[0] = 0;

      while(!q.empty()){

        int curr = q.front();
        q.pop();

        if(curr == N - 1) return dist[curr];

        for(int dice = 1; dice <= 6; dice++){
          int next = curr + dice;
          if (next >= N) continue;

          if (dest[next] != -1) next = dest[next];
          if (dist[next] == -1) {
              dist[next] = dist[curr] + 1;
              q.push(next);
          }
        }
      }

      return -1;

    }
};
int main() {

  return 0;
}
