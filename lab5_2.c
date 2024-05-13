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

void linear_search(int *array, int size)
{
    int key, found = 0;
    clock_t start, end;
    double elapsed_time;

    printf("Element to search ");
    scanf("%d", &key);

    start = clock();

    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
        {
            printf("Element %d found at position %d\n", array[i], i);
            found = 1;
            break;
        }
    }

    end = clock();
    elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (!found)
    {
        printf("Element not in array\n");
    }

    printf("Time taken %f seconds\n", elapsed_time);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int binary_search_algorithm(int array[], int x, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // printf("Mid = %d, Low = %d, High = %d\n", mid, low, high);

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

void binary_search_output(int *array, int size)
{
    int key;
    clock_t start, end;
    double elapsed_time;

    printf("Element to search: ");
    scanf("%d", &key);

    qsort(array, size, sizeof(int), compare);

    start = clock();

    int index = binary_search_algorithm(array, key, 0, size - 1);

    end = clock();
    elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (index != -1)
    {
        printf("Element %d found at position %d\n", key, index);
    }
    else
    {
        printf("Element not in array.\n");
    }

    printf("Time taken %f seconds\n", elapsed_time);
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
        printf("4 | Linear search\n");
        printf("5 | Binary search\n");
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
                linear_search(array, size);
            }
            break;
        case 5:
            if (array == NULL)
            {
                printf("Initialize array. . .\n");
            }
            else
            {
                binary_search_output(array, size);
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