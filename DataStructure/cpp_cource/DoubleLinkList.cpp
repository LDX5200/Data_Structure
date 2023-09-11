//双向链表
#include<iostream>
using namespace std;

//指向前面节点和后面节点
typedef struct DoubleLinkList
{
    int data;
    struct DoubleLinkList *prior , *next;
}DuLNode,*DuLinkList;

//双向链表的插入
void ListInsert_Dul(DuLinkList &L,int i,int e)
{
    DuLinkList p;
    p = L;
    int j = 0;
    while(p && j < i-1)
    {
        p = p->next;
        j++;
    }
    DuLinkList s = new DuLNode;
    s->data = e;
    //前驱就是p的
    s->prior = p->prior;
    //p的前驱的next是s
    p->prior->next = s;
    //s的next就是p
    s->next = p;
    //s是p的前驱
    s = p->prior;
}

//双向链表的删除
void ListDelete_DuL(DuLinkList &L, int i, int &e)
{
    DuLinkList p;
    p = L;
    int j = 0;
    while(p && j < i-1)
    {
        p = p->next;
        j++;
    }
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}

//开始测试~
void printList(DuLinkList L)
{
    int i = 0;
    DuLinkList p = L->next;
    while(p)
    {
        cout<<"第"<<i<<"个值是"<<p->data<<endl;
        p = p->next;
        i++;
    }
    cout<<"error"<<endl;
    
}

//尾插法
void createDulink(DuLinkList &L,int n)
{
    //必须弄一个head 不然L就是跑到最后一个节点啦
    DuLinkList head; 

    L = new DuLNode;
    L->next = NULL;
    L->prior = NULL;

    head = L;
    for(int i = 0;i < n;i++)
    {
        DuLinkList p = new DuLNode;
        cout<<"p的第"<<i<<"个值是："<<endl;
        cin>>p->data;

        L->next = p;
        p->prior = L;
        p->next = NULL;
        L = p;
    }

    //归位！
    L = head;

}

int main()
{
    DuLinkList test;
    createDulink(test,4);
    printList(test);
    system("pause");
}