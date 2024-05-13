#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize(int *array, int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

void display(int *array, int size)
{
    printf("Array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%-3d", array[i]);
    }
    printf("\n");
}

void release(int *array)
{
    free(array);
    printf("Memory freed. . .\n");
}

void selection_sort(int *array, int size)
{
    clock_t start_time = clock();
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }
        int temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Selection sort executed in %.6f seconds.\n", time_taken);
}

void rearrange_array(int *array, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        rearrange_array(array, size, largest);
    }
}

void heap_sort(int *array, int size)
{
    clock_t start_time = clock();
    for (int i = size / 2 - 1; i >= 0; i--)
        rearrange_array(array, size, i);

    for (int i = size - 1; i > 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        rearrange_array(array, i, 0);
    }

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Heap sort executed in %.6f seconds.\n", time_taken);
}

int main()
{
    int *array = NULL;
    int size, choice;

    system("cls");

    while (1)
    {
        printf("\nMenu:\n");
        printf("1 | Initialize array\n");
        printf("2 | Display array\n");
        printf("3 | Release memory\n");
        printf("4 | Sort using selection sort\n");
        printf("5 | Sort using heap sort\n");
        printf("0 | Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (array != NULL)
            {
                release(array);
            }
            printf("Size of array: ");
            scanf("%d", &size);
            array = (int *)malloc(size * sizeof(int));
            initialize(array, size);
            printf("\nArray initialized. . .\n");
            break;
        case 2:
            if (array == NULL)
            {
                printf("Initialize array. . .\n");
            }
            else
            {
                display(array, size);
            }
            break;
        case 3:
            if (array != NULL)
            {
                release(array);
                array = NULL;
            }
            else
            {
                printf("Initialize array. . .\n");
            }
            break;
        case 4:
            if (array == NULL)
            {
                printf("Initialize array. . .\n");
            }
            else
            {
                selection_sort(array, size);
            }
            break;
        case 5:
            if (array == NULL)
            {
                printf("Initialize array. . .\n");
            }
            else
            {
                heap_sort(array, size);
            }
            break;
        case 0:
            if (array != NULL)
            {
                release(array);
            }
            printf("============\n||  EXIT  ||\n============\n");
            return 0;
        default:
            printf("invalid choice\n");
        }
    }

    return 0;
}
