#include <stdio.h>

#define SAMPLE_COUNT 6
int sample[SAMPLE_COUNT] = {8, 12, 3, 15, 7, 4};

void print_data(int a[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        printf("%2d ", a[i]);
    }
    printf("\n");
}

void swap_array(int a[], int i, int j)
{
    int tmp;

    tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void sort(int data[], int count)
{
}

int main(void)
{
    sort(sample, SAMPLE_COUNT);
    print_data(sample, SAMPLE_COUNT);
    return 0;
}
