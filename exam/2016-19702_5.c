#include <stdio.h>

int include(int x, int y, int a)
{
	if (x<=a && a<=y)
		return 1;
	else return 0;
}

void comb1(int *x, int *y, int check_x, int check_y, int size)
{
	int i;
	for (i=0; i<size-check_y-2; i++)
		x[i+check_x+1] = x[i+check_y+2];
	for (i=0; i<size-check_y-2; i++)
		y[i+check_x+1] = y[i+check_y+2];
}

void comb2(int *x, int *y, int check_x, int check_y, int size)
{
	int i;
	for (i=0; i<size-check_y-2; i++)
		x[i+check_x+1] = x[i+check_y+2];
	for (i=0; i<size-check_y-2; i++)
		y[i+check_x+1] = y[i+check_y+1];
}

void comb3(int *x, int *y, int check_x, int check_y, int size)
{
	int i;
	for (i=0; i<size-check_y-2; i++)
		x[i+check_x+1] = x[i+check_y+1];
	for (i=0; i<size-check_y-2; i++)
		y[i+check_x+1] = y[i+check_y+2];
}

void comb4(int *x, int *y, int check_x, int check_y, int size)
{
	int i;
	for (i=0; i<size-check_y-2; i++)
		x[i+check_x+1] = x[i+check_y+1];
	for (i=0; i<size-check_y-2; i++)
		y[i+check_x+1] = y[i+check_y+1];
}

/*int include2(int x, int y, int a, int b)
{
	if (x<=a && y>=a)
	{
		if (x<=b && y>=b)
			return 0;
		else
			return 1;
	else if (y<a)
		return 2;
	else if (x<=b && y>=b)
		return -1;
	else if (b<x)
		return -2;
	}
} */

void print(int *x, int *y, int size)
{
	int i;
	for (i=0; i<size; i++)
		printf("%d %d\n", x[i], y[i]);
}

void main()
{
	int n;
	scanf("%d", &n);
	int x[10000];
	int y[10000];

	scanf("%d %d", &x[0], &y[0]);
	int i, j;
	int size = 1;
	int check_x , check_y;
	int tmp_x, tmp_y;
	for (j=1; j<n; j++)
	{
		scanf("%d %d", &tmp_x, &tmp_y);
		if (size==1)
		{
			if (x[0]<=tmp_x && y[0]>=tmp_x && y[0]<tmp_y)
				y[0] = tmp_y; 
			else if (x[0]<=tmp_y && y[0]>=tmp_y && x[0]>tmp_x)
				x[0] = tmp_x; 
			else if (y[0]<tmp_x)
			{
				x[1] = tmp_x;
				y[1] = tmp_y;
				size++;
			}
			else if (x[0]>tmp_y)
			{
				x[1] = x[0];
				y[1] = y[0];
				x[0] = tmp_x;
				y[0] = tmp_y;
				size++;
			}
			else if (x[0]>tmp_x && y[0]<tmp_y)
			{
				x[0] = tmp_x;
				y[0] = tmp_y;
			}
			else if (x[0]<=tmp_x && y[0]>=tmp_x && x[0]<=tmp_y && y[0]>=tmp_y)
				;
		}
		else
		{
			if (tmp_x > y[size-1])
			{
				x[size] = tmp_x;
				y[size] = tmp_y;
				size++;
			}
			else if (tmp_y<x[0])
			{
				for (i=0; i<size; i++)
				{
					x[i+1] = x[i];
					y[i+1] = y[i];
				}
				x[0] = tmp_x;
				y[0] = tmp_y;
				size++;
			}

			else
			{
				for (i=0; i<size-1; i++)
					if (include(x[i], x[i+1], tmp_x)==1)
						check_x = i;
				for (i=0; i<size-1; i++)
					if (include(y[i], y[i+1], tmp_y)==1)
						check_y = i;

				if (check_x==check_y)
					break;
				int bet_x = include(x[check_x], y[check_y], tmp_x);
				int bet_y = include(x[check_y+1], y[check_y+1], tmp_x);

				int diff =check_y - check_x;
				if (diff==0)
				{
					for (i=size; i>check_x; i--)
					{
						x[i] = x[i-1];
						y[i] = y[i-1];
					}
					x[check_x+1] = tmp_x;
					y[check_x+1] = tmp_y;
					size++;
				}
				else if (bet_x==1 && bet_y==1)
				{
					y[check_x] = y[check_y+1];
					comb1(x, y, check_x, check_y, size);
					size = size - (diff);
				}
				else if (bet_x==1 && bet_y==0)
				{
					y[check_x] = tmp_y;
					comb2(x, y, check_x, check_y, size);
					size = size - (diff);
				}
				else if (bet_x==0 && bet_y==1)
				{
					x[check_x] = tmp_x;
					y[check_x] = y[check_y+1];
					comb3(x, y, check_x, check_y, size);
					size = size - (diff-1);
				}
				else if (bet_x==0 && bet_y==0)
				{
					x[check_x] = tmp_x;
					y[check_x] = tmp_y;
					comb4(x, y, check_x, check_y, size);
				}
			}
		}
	}
		print(x, y, size);
}
