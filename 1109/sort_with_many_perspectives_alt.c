#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[9];
    double height;
    int weight;
} student;


int comp_by_name(student *A, student *B)
{
    return strcmp(A->name, B->name);
}

int comp_by_height(student *A, student *B)
{
    if (A->height < B->height)
	return -1;
    else if (A->height > B->height)
	return 1;
    else
	return 0;
}

int comp_by_weight(student *A, student *B)
{
    if (A->weight < B->weight)
	return -1;
    else if (A->weight > B->weight)
	return 1;
    else
	return 0;
}

int ord_name_height_weight(const void *A, const void *B)
{
    int val;

    val = comp_by_name((student *)A, (student *)B);
    if (val != 0) return val;
    val = comp_by_height((student *)A, (student *)B);
    if (val != 0) return val;
    return comp_by_weight((student *)A, (student *)B);
}

int ord_heigth_weight_name(const void *A, const void *B)
{
    int val;

    val = comp_by_height((student *)A, (student *)B);
    if (val != 0) return val;
    val = comp_by_weight((student *)A, (student *)B);
    if (val != 0) return val;
    return comp_by_name((student *)A, (student *)B);
}

int ord_weight_name_heigth(const void *A, const void *B)
{
    int val;

    val = comp_by_weight((student *)A, (student *)B);
    if (val != 0) return val;
    val = comp_by_name((student *)A, (student *)B);
    if (val != 0) return val;
    return comp_by_height((student *)A, (student *)B);
}

void print_array(student *array, int size)
{
    int i;

    for (i=0; i<size; i++)
	printf("%s %.1f %d\n", array[i].name, array[i].height, array[i].weight);
}

int main()
{
    int N;

    scanf("%d", &N);

    student *contestants = (student *) malloc(sizeof(student)*N);

    int i;

    for (i=0; i<N; i++)
	scanf("%s %lf %d", contestants[i].name, &contestants[i].height, &contestants[i].weight);

    qsort(contestants, N, sizeof(student), ord_name_height_weight);
    print_array(contestants, N);

    qsort(contestants, N, sizeof(student), ord_heigth_weight_name);
    print_array(contestants, N);

    qsort(contestants, N, sizeof(student), ord_weight_name_heigth);
    print_array(contestants, N);

    return 0;
}
