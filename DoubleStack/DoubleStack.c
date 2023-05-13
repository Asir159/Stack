#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElmType;
typedef int Status;

//创建DoubleStack类型
typedef struct DoubleStack
{
    ElmType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

Status InitStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status Push(SqDoubleStack *S, ElmType e,int stackNum)
{
    if(S->top1+1 == S->top2)
        return ERROR;
    if(stackNum == 1)
    {
        S->top1++;
        S->data[S->top1] = e;
    }
    else if(stackNum == 2)
    {
        S->top2--;
        S->data[S->top2] = e;
    }

    return OK;
}

void visit(ElmType e)
{
    printf("%d ",e);
}

Status StackTraverse(SqDoubleStack s)
{
    int i = 0;

    while(i <= s.top1)
    {
        visit(s.data[i]);
        i++;
    }

    i = s.top2;
    while(i < MAXSIZE)
    {
        visit(s.data[i]);
        i++;
    }
    printf("\n");

    return OK;
}

int StackLength(SqDoubleStack S)
{
    return (S.top1+1) + (MAXSIZE - S.top2);
}

Status Pop(SqDoubleStack *S,ElmType *e, int stackNum)
{
    if(S->top1 == -1 || S->top2 == MAXSIZE)
        return ERROR;
    if(stackNum == 1)
    {
        *e = S->data[S->top1];
        S->top1--;
    }
    else if(stackNum == 2)
    {
        *e = S->data[S->top2];
        S->top2++;
    }

    return OK;
}

Status ClearStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status StackEmpty(SqDoubleStack S)
{
    if(S.top1 == -1 && S.top2 == MAXSIZE)
            return TRUE;
    else
            return FALSE;
}

int main()
{
    int j;
    SqDoubleStack s;
    ElmType e;
    InitStack(&s);
    for(j=1; j<=5; j++)
    {
        Push(&s,j,1);
    }
    for(j=MAXSIZE; j>=MAXSIZE-2; j--)
    {
        Push(&s,j,2);
    }

    printf("栈元素依次为: ");
    StackTraverse(s);
    printf("当前栈中元素有：%d \n",StackLength(s));

    Pop(&s,&e,2);
    printf("弹出的栈顶的元素 e=%d\n",e);

    for(j=6;j<=MAXSIZE-2;j++)
    {
        Push(&s,j,1);
    }
    printf("栈元素依次为: ");
    StackTraverse(s);

    printf("栈是否满了: %d(1:否,0:满)\n",Push(&s,100,1));

    ClearStack(&s);
    printf("清空栈后,栈是否为空:%d (1:是 0:否)\n",StackEmpty(s));
}