#include<iostream>
using namespace std;

typedef struct listnode{
    char num[8];
    char name[8];
    int score;
    struct listnode*next;
}Lnode,*Linklist;//Linklistr是指向这个节点的指针 = Lnode* = Linklist typedef listnode *Linklist

// //定义链表
// Linklist L;//为什么呢 因为指向这个链表的指针就可以称作这个链表

// //定义指向节点的指针
// Lnode *p;
// //其实上面两个等价哦

//单链表的初始化 带头结点
void InitList_L(Linklist &L)
{
    L =new Lnode;
    L->next = NULL;
}
/*在C++中，函数参数传递有两种方式：传值（by value）和传引用（by reference）。这两种方式的主要区别在于传递参数时是否复制数据。让我们来详细了解一下为什么可以使用 LinkList &L，但不可以使用 Lnode L。

传引用（Reference）： 当你使用 LinkList &L 时，& 表示你传递的是一个指向链表头节点指针的引用。这意味着你可以在函数内部修改调用处的实际指针，因为你实际上传递了指针本身的引用，而不是指针的拷贝。这对于链表的初始化、插入、删除等操作非常有用，因为这些操作需要修改链表的结构。

传值（Value）： 当你使用 Lnode L 时，你传递的是一个指向 Lnode 类型的指针的拷贝。在函数内部修改 L 不会影响函数外部的实际链表指针，因为你只是在函数内部操作了一个指针的拷贝。这在链表操作时通常不太实用，因为你需要修改链表指针的值。

总之，为了在函数内部能够修改函数外部的链表指针，传引用是必要的。这是为什么你可以使用 LinkList &L，但不能使用 Lnode L 的原因。传引用允许你传递指针本身的引用，从而在函数内部修改实际的指针值。而传值只传递了指针的拷贝，无法修改函数外部的指针。*/
int ListEmpty(Linklist L)
{
    if(L->next)
        return 0;
    else
        return 1;
}

//销毁链表 所以这里创建链表和销毁链表是真的创建和销毁，所以&是必要的，而判断链表为空不用改变 所以不用&、
//这里的百分号不是那个你想的意思哦
void Destroylist_L(Linklist &L)
{
    Lnode *p;//或linklist p
    while(L)
    {
        p = L;
        L = L->next;
        delete p;
    }
}

//清空链表 链表仍然存在(头节点/首元节点存在) 但是后面的节点和数据没了
//思路：依次释放所有节点，并将头节点指针域设置为空 
void ClearList(Linklist &L)
{
    Lnode *p,*q;
    p = L->next;
    while(p)//没到表尾
    {
        q = p->next;
        delete p;
        p = q;
    }
    //清楚完剩下的后
    L->next = NULL;
    //头节点指针域为空
}

//求链表的表长 自己写的哦
int ListLength_L(Linklist L)
{
    Lnode *p;
    int cnt = 0;    
    p = L->next;
    while(p)
    {
        cnt ++;
        p = p->next;
    }
    return cnt;
}

//取值 取第i个元素 -> 找到第i-1个节点中储存的数据
//因为通过e返回，所以要&
void GetElem_L(Linklist L,int i,int &e)
{
    Lnode *p;
    p = L->next;//指向头节点
    int j = 1;//j是负责和i比较的
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p || j>i)
        cout<<"Error"<<endl;
    e = p->score;
}

//查找 按值查找 找值返回位置  
//自己写一遍
void FindNum(Linklist L,int target,int &address)
{   
    Lnode *p;
    address = 1;
    p = L->next;//让p指向头节点
    while(p->score != target && p)
    {
        p = p->next;
        ++ address;
    }
    if(!p)
        cout<<"Error"<<endl;
    
}//他后来也写了 和我这个差不多

//自己写是返回第几个节点了，而要求是返回地址
//这里很聪明 返回是地址就用指针来做函数返回值
Lnode *LocateElem_L(Linklist L, int e)
{
    Lnode *p;
    p = L->next;
    while(p&&p->score!=e)
    {
        p = p->next;
    }
    return p;

