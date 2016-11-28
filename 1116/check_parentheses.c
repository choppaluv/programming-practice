#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    char data;
    struct list *next;
}list;

typedef struct stack
{
    int cnt;
    list *top;
}stack;

void push(char x, stack *stk)
{
    list *ptr = (list *)malloc(sizeof(list));
    ptr->data = x;
    ptr->next = stk->top;
    stk->top = ptr;
    stk->cnt++;
    return;
}

char pop(stack *stk)
{
    char c = stk->top->data;
    list *ptr = stk->top;
    stk->top = stk->top->next;
    stk->cnt--;
    free(ptr);
    return c; 
}

int empty(stack *stk)
{
    if (stk->cnt==0)
	return 1;
    else 
	return 0;
}

void main()
{
    char str[1000001];
    scanf("%s", str);
    
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->cnt = 0; // stack initialization
    stk->top = NULL;

    int i = 0;
    int cnt1 = 0, cnt2 = 0;
    while (str[i]!='\0')
    {
	if (str[i] == '(' || str[i] == '[' || str[i] == '{') // opening parenthesis
	{
	    push(str[i], stk);
	    cnt1++;
	}
	else if (str[i] == ')' || str[i] == ']' || str[i] == '}') // closing  parenthesis
	{
	    cnt2++;
	    if (empty(stk)==1)
	    {
		printf("INVALID\n");
		return;
	    }
	
	    char c = pop(stk);
	    if (c=='(')
	    {
		if (str[i] != ')')
		{
		    printf("INVALID\n");
		    return;
		}
	    }
	    else if (c=='[')
	    {
		if (str[i] != ']')
		{
		    printf("INVALID\n");
		    return;
		}
	    }
	    else if (c=='{')
	    {
		if (str[i] != '}')
		{
		    printf("INVALID\n");
		    return;
		}
	    }
	}
	else
	{
	    printf("INVALID\n");
	    return;
	}
	i++;
    }
    if (cnt1!=cnt2)
    {
	printf("INVALID\n");
	return;
    }
    printf("VALID\n");
    return;
}
