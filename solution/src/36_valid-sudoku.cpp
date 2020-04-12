/* 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。


上图是一个部分填充的有效的数独。

数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1:

输入:
[
  ['5','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: true
示例 2:

输入:
[
  ['8','3','.','.','7','.','.','.','.'],
  ['6','.','.','1','9','5','.','.','.'],
  ['.','9','8','.','.','.','.','6','.'],
  ['8','.','.','.','6','.','.','.','3'],
  ['4','.','.','8','.','3','.','.','1'],
  ['7','.','.','.','2','.','.','.','6'],
  ['.','6','.','.','.','.','2','8','.'],
  ['.','.','.','4','1','9','.','.','5'],
  ['.','.','.','.','8','.','.','7','9']
]
输出: false
解释: 除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。
     但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
说明:

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
给定数独序列只包含数字 1-9 和字符 '.' 。
给定数独永远是 9x9 形式的。
通过次数64,371提交次数109,207

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isValidSudoku(char board[][9], int boardSize, int *boardColSize)
{
    if (boardSize <= 0 || boardColSize <= 0)
    {
        return false;
    }
    for (int i = 0; i < boardSize; i++)
    {
        int row[10] = {0};
        int col[10] = {0};
        for (int j = 0; j < *boardColSize; j++)
        {

            if (board[i][j] != '.')
            {
                if (row[board[i][j] - '0'] > 0)
                {
                    return false;
                }
                row[board[i][j] - '0']++;
                // printf("%c %d ", board[i][j], row[board[i][j] - '0']);
            }

            if (board[j][i] != '.')
            {
                if (col[board[j][i] - '0'] > 0)
                {
                    return false;
                }
                col[board[j][i] - '0']++;
            }

            if ((i + 1) % 3 == 0 && (j + 1) % 3 == 0)
            {
                int matrix[10] = {0};
                for (int i1 = i - 2; i1 <= i; i1++)
                {
                    for (int j1 = j - 2; j1 <= j; j1++)
                    {
                        if (board[i1][j1] != '.')
                        {
                            if (matrix[board[i1][j1] - '0'] > 0)
                            {
                                return false;
                            }
                            matrix[board[i1][j1] - '0']++;
                            printf("%c %d ", board[i1][j1], matrix[board[i1][j1] - '0']);
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool isValidSudoku1(char **board, int boardSize, int *boardColSize)
{
    int i, j, r, c, row[9], col[9], martix[9];
    for (i = 0; i < boardSize; i++)
    {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(martix, 0, sizeof(martix));
        for (j = 0; j < boardColSize[i]; j++)
        {
            // 行
            if (board[i][j] != '.')
            {
                if (row[board[i][j] - '1'] == 1)
                    return false;
                row[board[i][j] - '1']++;
            }
            // 列
            if (board[j][i] != '.')
            {
                if (col[board[j][i] - '1'] == 1)
                    return false;
                col[board[j][i] - '1']++;
            }
            // 九宫格
            r = 3 * (i / 3) + j / 3;
            c = (i % 3) * 3 + j % 3;
            if (board[r][c] != '.')
            {
                if (martix[board[r][c] - '1'] == 1)
                    return false;
                martix[board[r][c] - '1']++;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char a[9][9] = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    int b = 9;

    printf("%d\r\n", isValidSudoku(a, 9, &b));

    char **arr = (char **)malloc(sizeof(char *) * 9);
    for (int i = 0; i < 9; ++i)
        arr[i] = (char *)malloc(sizeof(char) * 9);
    printf("%d\r\n", isValidSudoku1(arr, 9, &b));
    return 0;
}
