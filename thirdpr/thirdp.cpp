#include <iostream>
using namespace std;
 
typedef struct Node{
    int data;
    struct Node *next;
}Node ,*LNode;
 
void Display(LNode head)// 打印链表
{
    if (head == NULL)
    {
        cout << "the list is empty" << endl;
        return;
    }
    else
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
            // if(p->data==head->data)//加个判断，如果环中元素打印完了就退出，否则会无限循环
            //     break;
        }
    }
    cout << endl;
}
 
bool IsExistLoop(LNode head)
{
    LNode slow = head, fast = head;
 
    while ( fast && fast->next )
    {
        slow = slow->next;
        fast = fast->next->next;
        if ( slow == fast )
            break;
    }
 
    return !(fast == NULL || fast->next == NULL);
}
LNode Init(int num) // 创建环形链表
{
    if (num <= 0)
        return NULL;
    Node* cur = NULL;
    Node* head = NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = 1;
    head = cur = node;
    for (int i = 1; i < num; i++)
    {
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = i + 1;
        cur->next = node;
        node->next = NULL;
        cur = node;
    }
    //cur->next = head;//让最后一个元素的指针域指向头结点，形成环
    //cur->next = NULL;
    return head;
}
// 让单链表的奇数节点在偶数节点的前面
void changeOddAndEvenNode(LNode head)
{
    //p用来每次向下走，q用来记录偶数节点的头，r 用来记录偶数list的尾巴
    LNode p,q,q1;
    p=head;
    q=head->next;
    q1 = q;
    while(p && q1 && q1->next )
    {
        p->next = q1->next;
        p=p->next;
        q1->next=p->next;
        q1=q1->next;
    }
    //将两条链表连在一起
    p->next = q;
}
int main( )
{
    LNode list = NULL;
    list = Init(11);
    Display(list);
 
    if(IsExistLoop(list))
    {
        cout<<"this list has loop"<<endl;
    }
    else
    {
        cout<<"this list do not has loop"<<endl;
    }
    changeOddAndEvenNode(list);
    Display(list);
    return 0;
}