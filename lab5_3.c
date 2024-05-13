#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DIGITS 1000

/*
* Iterate through each digit of the numbers.
* Add the corresponding digits of num1 and num2, along with the carry.
* Update result with the least significant digit of the sum (temp % 10) and update carry with the carry-over value (temp / 10).
*/
void add(uint8_t *result, uint8_t *num1, uint8_t *num2)
{
    uint16_t temp, carry = 0;
    for (int i = 0; i < DIGITS; i++)        // Iterate through each digit of the numbers.
    {
        temp = num1[i] + num2[i] + carry;   // Add the corresponding digits of num1 and num2, along with the carry.
        carry = temp / 10;                   
        result[i] = temp % 10;              // Update result with the least significant digit of the sum (temp % 10) and update carry with the carry-over value (temp / 10).
    }
}

void copy(uint8_t *dest, uint8_t *src)
{
    for (int i = 0; i < DIGITS; i++)
    {
        dest[i] = src[i]; // copy from source to dest
    }
}

void fibonacci(int n)
{
    uint8_t fib[DIGITS] = {0}, n1[DIGITS] = {0}, n2[DIGITS] = {0};
    n2[0] = n1[0] = 1;
    int fib_count = 2;

    while (fib_count < n)   // Iterate to calculate the Fibonacci numbers iteratively up to the nth number:
    {
        add(fib, n1, n2);   // Calculate the next Fibonacci number by adding n1 and n2 and store it in fib.
        copy(n2, n1);       // Update n2 with the value of n1.
        copy(n1, fib);      // Update n1 with the value of the calculated Fibonacci number (fib).
        fib_count++;
    }

    printf("The %dth Fibonacci number\n", n);
    int startPrinting = 0;
    for (int i = DIGITS - 1; i >= 0; i--)
    {
        if (fib[i] != 0)
            startPrinting = 1;
        if (startPrinting)
            printf("%u", fib[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    system("cls");
    while (1)
    {
        printf("Fibonacci number (<1 to stop) ");
        scanf("%d", &n);
        if (n <= 0)
            break;
        fibonacci(n);
    }

    return 0;
}
