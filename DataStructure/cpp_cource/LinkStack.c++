#include<iostream>
using namespace std;

//定义链栈
typedef struct StackNode
{
    int data;
    StackNode *next;
}StackNode,*LinkStack;

//注意 链栈的NEXT存的不是后继元素，是(栈顶到栈底)前驱元素

//判断是否为空 
bool StackEmpty(LinkStack S)
{
    if(S == NULL) return true;
    else return false;
}

//链栈的入栈
//链栈头指针指向栈顶元素
void Push(LinkStack &S,int e)
{
    LinkStack p = new StackNode;
    p->data = e;//把数据给e
    p->next = S;//栈顶元素++ 所以指针是栈顶指向栈底的
    S = p;//修改栈顶指针
}

void Pop(LinkStack &S,int &e)
{
    if(S == NULL)
    {
        cout<<"ERROR"<<endl;
        exit(0);
    }
    LinkStack p = S;
    e = S->data;
    S = S->next;
    delete p;//别忘了释放空间
    cout<<S->data;
}

//取栈顶元素
void GetTop(LinkStack S)
{
    if(S != nullptr)
    {
        cout<<"栈顶元素是";
        cout << S->data<<endl;
    }
}

//OK 开始测试！
//惯例写一个输出函数
void Output(LinkStack S)
{
    LinkStack p = S;
    while(p)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}

int main()
{
    int e;
    LinkStack test = nullptr;//牛逼 不赋初始值就是这样的！
    Push(test,1);
    Push(test,2);
    Push(test,3);
    GetTop(test);//3
    Output(test);//3 2 1
    Pop(test,e);
    cout<<"pop is "<<e<<endl;//3
    Output(test);//2 1
    return 0;
}




