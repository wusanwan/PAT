**392. Is Subsequence** <a href="https://leetcode-cn.com/problems/is-subsequence/">原题</a>


最简单的思路应该是用有点像归并操作的双指针来做。

    //双指针O(n)
    //执行用时：48ms,在所有 C++ 提交中击败了81.34%的用户
    //内存消耗:17.2 MB, 在所有 C++ 提交中击败了13.64%的用户
    class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i2=0;
            for(int i1=0;i1<s.length();i1++){//s的循环
                for(;i2<t.length()&&t[i2]!=s[i1];i2++);//t的循环
                if(i2>=t.length())return false;//如果t已经遍历完毕
                else i2++;//如果找到某字符，则从下一个坐标继续找
            }
            return true;
        }
    };

也可以写成这种更典型的双指针形式。

    //执行用时：52 ms,在所有 C++ 提交中击败了61.04%的用户
    class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i1=0,i2=0;
            while(i1<s.length()&&i2<t.length()){
                if(s[i1]==t[i2])i1++;
                i2++;//不管相不相等i2都得动
            }
            if(i1<s.length())return false;
            else return true;
        }
    };



**报错**


😡都是弱智错误。
单句for记得加；
int i1=0，i2=0;记得分开赋值……


**改进**


1.简洁的代码

      if(i1<s.length())return false;
      else return true;
      //可改成 return i1==s.length()

2.追求更快的速度可以用i2=t.find(s[i1],i2);

    a.find(b);    //若b是a的子串，返回在a中第一次出现的位置。若非，则返回string::npos
    a.find(b,pos);    //从pos开始找b

❓为什么用find会更快
