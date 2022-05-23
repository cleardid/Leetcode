#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

class Solution {
public:
    //https://leetcode.cn/leetbook/read/top-interview-questions-easy/xnx13t/
    int reverse(int x) {
        string s = to_string(x);                  //变成字符串
        std::reverse(s.begin(), s.end());       //翻转字符串
        int ans = 0;
        try {
            ans = stoi(s);                      //变回数字
            if (x < 0) ans = -ans;              //x是负数，加上负号
        }
        catch (exception ex) {}                 //溢出，啥也不做，返回零
        return ans;
    }

    //https://leetcode.cn/leetbook/read/top-interview-questions-easy/xn5z8r/
    int firstUniqChar(string s) {
        int* ar = new int[26] {};                      //字母出现次数
        int n = s.length();
        char* chr = new char[n + 1];
        strcpy(chr, s.c_str());
        for (int i = 0; i < n; i++)
        {
            ar[chr[i] - 'a']++;
        }
        for (int i = 0; i < n; i++)
        {
            if (ar[chr[i] - 'a'] == 1)
                return i;
        }
        //while (s.begin() != s.end())
        //{
        //    ar[(int)*(s.begin()) - 97]++;
        //    ar[(int)*(s.end()) - 97]++;
        //    s.begin() = s.erase(s.begin());
        //    s.end() = s.erase(s.end());
        //}
        //for (int i = 0; i < 26; i++)
        //    cout << ar[i] << " ";
        //cout << endl;
        //int i = 0;
        //while (str.begin() != str.end())
        //{
        //    if (ar[(int)*(str.begin()) - 97] == 1)
        //        return i;
        //    str.begin() = str.erase(str.begin());
        //    i++;
        //}
        return -1;
    }

    //https://leetcode.cn/leetbook/read/top-interview-questions-easy/xn96us/
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        int* ar = new int[26]{};                      //字母出现次数
        int* br = new int[26]{};
        int n = s.length();
        char* chr_s = new char[n + 1];
        char* chr_t = new char[n + 1];
        strcpy(chr_s, s.c_str());
        strcpy(chr_t, t.c_str());

        for (int i = 0; i < n; i++)
        {
            ar[chr_s[i] - 'a']++;
            br[chr_t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (ar[i] != br[i])
                return false;
        }
        return true;
    }
};

int main()
{
    /*
    Solution s1;
    int x = 2147483647;
    cout << x << endl;
    x = s1.reverse(x);
    cout << x << endl;
    */

    //Solution s2;
    //string s = "loveleetcode";
    //cout << s2.firstUniqChar(s) << endl;
    // char a = *(s.begin();
    //cout << s.size() << endl;
    //while (s.begin() != s.end())
    //{
    //    cout << (int)*(s.begin()) - 97 << endl;
    //    s.begin() = s.erase(s.begin());
    //}

    Solution s3;
    string s = "rat", t = "car";
    cout << s3.isAnagram(s, t) << endl;
    return 0;
}