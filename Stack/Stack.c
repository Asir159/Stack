#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FASLE 0

typedef int ElmType;
typedef int Status;
//创建Stack表类型
typedef struct SqStack
{
    ElmType data[MAXSIZE];
    int top;
}SqStack;

//初始化元素
Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status Push(SqStack *S,ElmType e)
{
    //溢出返回错误
    if(S->top == MAXSIZE -1)
     return ERROR;

    S->top++;
    S->data[S->top] = e;
    return OK;
}

void visit(ElmType e)
{
    printf("%d ", e);
}

//遍历栈表
Status StackTraverse(SqStack S)
{
    int i;
    i = 0;

    while(i <= S.top)
    {
        visit(S.data[i]);
        i++;
    }
    printf("\n");

    return OK;
}

//弹出栈顶元素 || 删除栈顶元素
Status Pop(SqStack *S, ElmType *e)
{
    if(S->top == -1)
        return ERROR;

    *e = S->data[S->top];
    S->top--;

    return OK;
}

//查看栈表是否为空
Status StackEmpty(SqStack S)
{
    if(S.top != -1)
        return FASLE;
    else
        return TRUE;
}

//获取栈顶元素
Status Gettop(SqStack S, ElmType *e)
{
    *e = S.data[S.top];
    return OK;
}

//获取栈表长度
int StackLength(SqStack S)
{
    return S.top + 1;
}

//清空栈表
Status ClearStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

int main()
{
    int i;
    SqStack s;
    ElmType e;
    InitStack(&s);
    for(i=1; i<=10; i++)
    {
        Push(&s,i);
    }
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 e= %d\n",e);
    printf("栈是否为空 %d(1:空 0:否)\n",StackEmpty(s));
    Gettop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后, 栈是否为空 %d (1:空 0:否)\n",StackEmpty(s));
}