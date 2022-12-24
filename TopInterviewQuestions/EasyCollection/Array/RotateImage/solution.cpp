class Solution {
 public:
  void rotate(vector <vector<int>>& matrix) {
    for (int i = 0; 2 * i <= matrix.size(); ++i) {
      for (int j = i; j < matrix.size() - i - 1; ++j) {
        MakeCycle(matrix, i, j);
      }
    }
  }

  void MakeCycle(vector <vector<int>>& matrix, int i, int j) {
    int buffer = matrix[i][j];
    int next_i = j;
    int next_j = matrix.size() - i - 1;
    std::swap(buffer, matrix[next_i][next_j]);

    next_i = matrix.size() - i - 1;
    next_j = matrix.size() - j - 1;
    std::swap(buffer, matrix[next_i][next_j]);

    next_i = matrix.size() - j - 1;
    next_j = i;
    std::swap(buffer, matrix[next_i][next_j]);

    matrix[i][j] = buffer;
  }
};
