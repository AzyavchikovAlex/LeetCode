class Solution {
 public:
  bool isValidSudoku(std::vector<std::vector<char>>& board) {
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board.size(); ++j) {
        char symbol = board[i][j];
        if (symbol == '.') {
          continue;
        }
        if (CheckCollum(board, i, j, symbol) &&
            CheckRow(board, i, j, symbol) &&
            CheckCell(board, i, j, symbol)) {
          continue;
        }
        return false;
      }
    }
    return true;
  }

 private:
  static bool CheckCollum(const std::vector<std::vector<char>>& board,
                          int i, int j, char c) {
    for (int di = 0; di < board.size(); ++di) {
      if (board[di][j] == c && (di != i)) {
        return false;
      }
    }
    return true;
  }

  static bool CheckRow(const std::vector<std::vector<char>>& board,
                       int i, int j, char c) {
    for (int dj = 0; dj < board[j].size(); ++dj) {
      if (board[i][dj] == c && (dj != j)) {
        return false;
      }
    }
    return true;
  }

  static bool CheckCell(const std::vector<std::vector<char>>& board,
                        int i, int j, char c) {
    int up_border = i - i % 3;
    int left_border = j - j % 3;
    for (int di = up_border; di < up_border + 3; ++di) {
      for (int dj = left_border; dj < left_border + 3; ++dj) {
        if ((di != i || dj != j) && board[di][dj] == c) {
          return false;
        }
      }
    }
    return true;
  }
};
