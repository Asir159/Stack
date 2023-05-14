#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Elmtype;
typedef int Status;

//创建栈链类型
typedef struct StackNode
{
    Elmtype data;
    struct StackNode* next;
}StackNode,*LinkStackPrt;

//头节点 | 栈顶位置 类型
typedef struct LinkStack
{
    LinkStackPrt top;
    int cnt;
}LinkStack;

//创建空栈
Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPrt)malloc(sizeof(StackNode));      //申请一个栈节点让顶栈指向
        if(!S->top)
        return ERROR;
    S->top->next = NULL;                                   //开始无指向
    S->cnt = 0;                                            
    return OK;
}

//添加顶元素
Status Push(LinkStack *S,Elmtype e)
{
    LinkStackPrt s;
    s = (LinkStackPrt)malloc(sizeof(StackNode));
    if(!s)
        return ERROR;
        s->data = e;
        s->next = S->top;
        S->top = s;
        S->cnt++;     
    return OK;
}

void visit(Elmtype e)
{
    printf("%d ",e);
}

Status StackTraverse(LinkStack S)
{
    LinkStackPrt p;
    p = S.top;
    while(p->next)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");

    return OK;
}

//判断是否为空
Status StackEmpty(LinkStack S)
{
    if(S.cnt == 0)
        return TRUE;
    else
        return FALSE;
}

//删除顶元素
Status Pop(LinkStack *S, Elmtype *e)
{
    LinkStackPrt p;
    if(StackEmpty(*S))
        return ERROR;

    *e = S->top->data;              //把要弹出|删除的栈顶数据给e
    p = S->top;                     //先把当前栈顶点给p，用来释放|销毁
    S->top = S->top->next;          //把栈顶的下一个设置成栈顶
    free(p);                        //释放栈顶p
    S->cnt--;

    return OK;
}

Status GetTop(LinkStack S, Elmtype* e)
{
    if(S.top == NULL)
        return ERROR;
    else
    *e = S.top->data;
    return OK;
}

Status StackLength(LinkStack S)
{
    return S.cnt;
}

//清楚栈链
Status ClearStack(LinkStack *S)
{
    LinkStackPrt p,q;
    p = S->top;
    while(p)
    {
        q=p;
        p = p->next;
        free(q);
    }
    S->cnt = 0;
    return OK;
}

int main()
{
    int i;
    LinkStack s;
    Elmtype e;

    InitStack(&s);
    for(i=1; i<=5;i++)
    {
        Push(&s,i);
    }
    printf("栈中的元素依次为: ");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 %d\n",e);
    printf("栈是否空 %d(1:空 0:否)\n",StackEmpty(s));

    GetTop(s,&e);
    printf("栈顶元素为: %d,长度为%d \n",e,StackLength(s));

    ClearStack(&s);
    printf("清空栈后栈是否空 %d(1:空 0:否)\n",StackEmpty(s));
    return 0;
}