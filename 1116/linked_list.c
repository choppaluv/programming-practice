#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}list;

void insert(struct list *head, int x)
{
    while (head->next!=NULL)
	head = head->next;

    head->next = (struct list *)malloc(sizeof(struct list));
    head->next->data = x;
    head->next->next = NULL;  
}

void delete(struct list *head, int x)
{
    struct list *pre = head;
    head = head->next;

    if (head==NULL)
	return;

    while (head->data!=x && head->next!=NULL)
    {
	pre = head;
	head = head->next;
    }

    if (head->data==x)
    {
	pre->next = pre->next->next;
	free(head);
    }
    return;
    /*
    struct list *copy = head;
    struct list *copy2 = head;
    int cnt = 0;
    while (copy->data!=x && copy->next!=NULL)
    {
	copy = copy->next;
	cnt++;
    }
    if (copy->data == x && cnt == 0)
    {
	struct list *new_head = head->next;
	free(copy);
	return new_head;
    }
    else if (copy->next == NULL && copy->data != x)
	return head;

    int i;
    for (i=0; i<cnt-1;i++)
	head = head->next;

    struct list *tmp;
    tmp = head->next;
    head->next = head->next->next;
    free(tmp);

    return copy2; */
}

void print(struct list *head)
{
    while (head->next!=NULL)
    {
	head = head->next;
	printf("%d ", head->data);
    }
    printf("\n");
}

void free_all(struct list *head)
{
    if (head->next==NULL)
	free(head);
    else
    {
	free_all(head->next);
	free(head);
    }
}


int main()
{
    int N;
    scanf("%d", &N);
    
    int i;
    int op, x;

    struct list *head = (struct list *)malloc(sizeof(struct list));
    head->data = -1; //dummy node
    head->next = NULL;

    for (i=0; i<N; i++)
    {
	scanf("%d",&op);
	if (op==2)
	    print(head);
	else
	{
	    scanf("%d", &x);
	    if (op==0)
		insert(head, x);
	    else if (op==1)
		delete(head, x);
	}
    }
    free_all(head);

    return 0;
}
