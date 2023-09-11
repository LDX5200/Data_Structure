//definition
#include<iostream>
#include<algorithm>
using namespace std;
typedef struct ListNode
{
    int val;
    struct ListNode *next;
    
}Lnode,*Linklist;

//插入操作
//先把新节点的next给了p->next 然后，p->next = 新节点
//自己写一下 把节点插入第i个
void ListInsert(Linklist &L,int i,int e)
{
    Lnode *p;
    p = L;
    int num = 0;
    while(p && num<i-1)
    {
        p = p->next;
        ++num;
    }
    //找到了
    if(!p || num > i-1)
    {
        cout << "ERROR"<<endl;
    }
    //大于表厂+1 或小于1 插入非法
    Linklist s = new Lnode;
    s->next = p->next;
    p->next = s;
    cout<<"Insert success"<<endl;
}

//删除节点
//自己写一个
void DeleteNode_L(Linklist &L,int i)
{
    Linklist p;
    Linklist q;
    int num;
    while(p && i < num-1)
    {
        p = p->next;
        ++num;
    }
    if(!p || num > i-1)
    {
        cout << "ERROR"<<endl;
    }
    q = p->next;
    p->next = p->next->next;
    delete q;
    cout<<"Delete Success!"<<endl;    
}   
//教材上的 增加了保存删除节点的数据
//e就是用来保存的
void ListDelete_L(Linklist &L,int i, int &e)
{
    Linklist p,q;
    int j =0 ;
    while(p && j < i-1)
    {
        p = p->next;
        ++j;
    }
    if(!p ||j > i-1)
    {
        cout << "ERROR"<<endl;
    }    
    q = p->next;
    p->next = q->next;
    e = q->val;//就加了这一步
    delete q;
}

//建立链表
//头插法 / 前插法
//从最后一个节点开始 依次往前插 也就是插头
void CreateList_H(Linklist &L,int n)
{
    L = new Lnode;
    L->next = NULL;
    //创建一个头节点
    for(int i = 0;i < n; i++)
    {
        Linklist p = new Lnode;
        cin >> p->val;
        p->next = L->next;
        L->next = p;
    }
}

//尾插法
//建立尾指针
void Createlist_F(Linklist &L,int n)
{
    L = new Lnode;
    L->next = NULL;
    Linklist r = L;

    for(int i = 0;i < n;i++)
    {
        Linklist p = new Lnode;
        cin >> p->val;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}