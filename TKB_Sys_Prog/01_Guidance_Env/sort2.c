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
    int i, j;

    for (i = 0; i < count; i++)
    {
        printf("%d: ", i);
        print_data(data, count);

        for (j = i; j < count; j++)
        {
            if (data[j] > data[j + 1])
            {
                swap_array(data, j, j + 1);
            }
        }
    }
}

int main(void)
{
    sort(sample, SAMPLE_COUNT);
    print_data(sample, SAMPLE_COUNT);
    return 0;
}
