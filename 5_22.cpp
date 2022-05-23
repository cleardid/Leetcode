#if 0

#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

class Solution {
public:
    //https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2f9gg/
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = { 0 };
        int columns[9][9] = { 0 };
        int subboxes[3][3][9] = { 0 };

        memset(rows, 0, sizeof(rows));
        memset(columns, 0, sizeof(columns));
        memset(subboxes, 0, sizeof(subboxes));

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if (c != '.')
                {
                    int index = c - '0' - 1;    //出现的数
                    rows[i][index]++;
                    columns[j][index]++;
                    subboxes[i / 3][j / 3][index]++;
                    if (rows[i][index] > 1 || columns[j][index] > 1 || subboxes[i / 3][j / 3][index] > 1)
                        return false;
                }
            }
        } 
        return true;
    }

    // https://leetcode.cn/leetbook/read/top-interview-questions-easy/xnhhkv/
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //cout << n << endl;
        auto new_matrix = matrix;       //拷贝整体矩阵
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.size(); j++)
                new_matrix[j][n - i - 1] = matrix[i][j];
        matrix = new_matrix;
    }

    //https://leetcode.cn/leetbook/read/top-interview-questions-easy/xnhbqj/
    void reverseString(vector<char>& s) {
        int n = s.size();
        int left = 0, right = n - 1;        //双指针
        while (left < right)
        {
            swap(s[left++], s[right--]);
        }
    }
};

int main()
{
    vector<vector<int>> matrix = {  {5,1,9,11},
                                    {2,4,8,10},
                                    {13,3,6,7},
                                    {15,14,12,16} };

    Solution s1;
    s1.rotate(matrix);

    vector<char> s = { 'h','e','l','l','o' };
    for (int i = 0; i < s.size(); i++)
        cout << s[i];
    cout << endl;
    Solution s2;
    s2.reverseString(s);
    for (int i = 0; i < s.size(); i++)
        cout << s[i];
}


#endif