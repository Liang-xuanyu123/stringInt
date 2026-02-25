/*
    有没有人打PC端三角洲，
    本人9岁，60级，
    绝密撤过，但kd低于0.1不显示。
    ID:下辈子坐同桌
*/

//  2026/2/25写的
//      ↓    

#include <iostream>
#include <string.h>
using namespace std;
class sInt
{
public:

    string v;
    sInt(string value) : v(value) {}
    string getValue() const 
    {
        return v;
    }
    int size() const
    {
        return v.size();
    }


    string operator[](int a) //让这个类型跟数组一样，可以访问指定下标的元素
    {
        return string(1,v[a]); 
        /*
        注意：这里返回的是字符串，不是字符，因为这里调用了string类的构造函数，
        第1个参数代表这个string（char数组）的长度，第2个参数代表这个string里的值，
        这个函数就会整个字符串（v）里的一个子串。
        */
    }

    friend string operator+(const sInt& a,const sInt& b) //加法
    {   
        string result;
        bool carry=false;
        int maxLen=max(a.size(),b.size()); //防止这两个字符串长度不同
        string num1=string(maxLen-a.size(),'0')+a.v;
        string num2=string(maxLen-b.size(),'0')+b.v;
        //                ^^^^^^^^^^^^^^^^^
        //这里一定要用maxLen（两个加数中最大的）减这个加数的长度，不然数组会越界
        for (int i=maxLen-1;i>=0;i--)
        {
            int digit1=num1[i]-'0';
            int digit2=num2[i]-'0';
            int sum=digit1+digit2+(carry?1:0);
            if (sum>=10) carry=true;
            result=char('0'+(sum % 10))+result;
        }
        if (carry) result='1'+result; //两个一位数加起来一定不会超过20，所以最多就进1
        return result;
        /*
        这里用遍历的方法，遍历这个字符串，
        这里用一个变量（carry）来记录是否进位，
        如果进位，这一位就+1，然后把每一位的数字记录到result里。
        */
    }
    //  2026/2/26写的
    //      ↓    
    friend string operator-(const sInt& a,const sInt& b)
    {
        

    }
}
