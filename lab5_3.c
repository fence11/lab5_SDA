#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define DIGITS 1000

/*
* iterate through number's digits
* add digits of num1 and num2 along with the carry
* add last digit of sum to result, temp/10 is new carry
*/
void add(uint8_t *result, uint8_t *num1, uint8_t *num2)
{
    uint16_t temp, carry = 0;
    for (int i = 0; i < DIGITS; i++)        // iterate through number's digits
    {
        temp = num1[i] + num2[i] + carry;   // add digits of num1 and num2 along with the carry
        carry = temp / 10;                   
        result[i] = temp % 10;              // add last digit of sum to result, temp/10 is new carry
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

    while (fib_count < n)   // calculate fibonacci to nth number
    {
        add(fib, n1, n2);   // calc next fibonacci n1 + n2 --> fib
        copy(n2, n1);       // n2 gets n1, n2 = n1
        copy(n1, fib);      // n1 gets fib, n1 = fib
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
        printf("Fibonacci number (<1 to stop) "); // up to 1000, after this it bugs and doesn't show properly for some reason
        scanf("%d", &n);
        if (n <= 0)
            break;
        fibonacci(n);
    }

    return 0;
}
