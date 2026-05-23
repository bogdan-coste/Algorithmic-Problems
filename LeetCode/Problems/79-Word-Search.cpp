class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        
      int linesCount = board.size();
      int columnCount = board[0].size();

      for(int i = 0; i < linesCount; i++){
        for(int j = 0; j < columnCount; j++){
          if(dfs(board, word, i, j, 0, linesCount, columnCount)){
            return true;
          }
        }
      }

      return false;
    }

    bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int wordLen, int& linesCount, int& columnCount){

      if(wordLen == word.size()) return true;

      if(i < 0 || i >= linesCount || j < 0 || j >= columnCount){
        return false;
      }

      if(board[i][j] != word[wordLen]) return false;

      char temp = board[i][j];
      board[i][j] = '#';

      bool found =  dfs(board, word, i + 1, j, wordLen + 1, linesCount, columnCount) ||
                    dfs(board, word, i, j + 1, wordLen + 1, linesCount, columnCount) ||
                    dfs(board, word, i - 1, j, wordLen + 1, linesCount, columnCount) ||
                    dfs(board, word, i, j - 1, wordLen + 1, linesCount, columnCount);

      board[i][j] = temp;

      return found;
    }
};
