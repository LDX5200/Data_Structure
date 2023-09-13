#include<iostream>
#include<algorithm>
using namespace std;

#define MAXSIZE 10

typedef struct stack
{
    int *base;
    int *top;
    int stacksize;
}Sqstack;

void InitStack(Sqstack &S)
{
    S.base = new int[MAXSIZE];
    if(!S.base)
    {
        cout<<"ERROR"<<endl;
        exit(0);
    }
    S.top = S.base;
    S.stacksize = MAXSIZE;
}

void Push(Sqstack &S, int e)
{
    if(S.top - S.base == S.stacksize)
    {
        cout<<"ERROR"<<endl;
        exit(0);
    }
    //*S.top ++ =e
    *S.top = e;
    S.top ++;
}

//出栈
void Pop(Sqstack &S, int &e)
{
    if(S.top == S.base)
    {
        cout<<"ERROR"<<endl;
        exit(0);
    }
    S.top --;//先减去 因为在上面
    e = *S.top;
}

//现在开始测试！

//先写一个输出函数
void OutputStack(Sqstack S)
{
    int *p;
    p = S.base;
    //为什么是小于 因为top是在最上面的一个的在上面一个
    while(p < S.top)
    {
        cout<<*p<<endl;
        p++;
    }
}
int main()
{
    int e;
    Sqstack test;
    InitStack(test);
    Push(test,1);
    Push(test,2);
    Push(test,3);
    OutputStack(test);
    Pop(test,e);
    OutputStack(test);
    cout<<"this is "<<e;
    return 0;
}