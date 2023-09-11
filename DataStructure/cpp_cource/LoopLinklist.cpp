#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
//首尾相接的链表，最后一节点的指针域指向头节点

typedef struct Node
{
    int val;
    Node *next;
}Lnode,*LinkList;

//尾插法创建循环链表
void CreatloopLinkList(LinkList &L,int n)
{
    Lnode *tail;//尾节点的指针
    L = new Lnode;
    L->next = NULL;
    Lnode *head = L;

    for(int i = 0;i < n; i++)
    {
        LinkList p = new Lnode;
        cout<<"输入第"<<i<<"个"<<endl;
        cin >> p->val;
        p->next = NULL;
        L->next = p;
        L = p;
    }
    //尾节点赋值给尾指针
    tail = L;
    //尾节点的next 为头节点的next
    tail->next = head->next;

}

//遍历循环链表
void traverseLinklist(LinkList L)
{
    LinkList p = L->next;
    while(p)
    {
        cout << p->val <<endl;
        p = p->next;
    }
}

int main()
{
    LinkList test;
    CreatloopLinkList(test,5);
    traverseLinklist(test);
    system("pause"); 
    return 0;
}