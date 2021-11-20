// Program to print all prime factors
# include <stdio.h>
# include <math.h>
 
// A function to print all prime factors of a given number n
void primeFactors(int n)
{
    int len = sqrt(n), loc = 1;
    //create an array to hold the prime factors
    int primeFactors[len];

    for (int i = 0; i < len; i++)
        primeFactors[i] = -1;
    primeFactors[0] = 1;

    // Print the number of 2s that divide n
    // so that n is no longer divisible by 2
    while (n%2 == 0)
    {
        printf("n is now %d after divided by %d\n",n,  2);
        n = n/2;
        if (primeFactors[loc - 1] != 2)
            primeFactors[loc++] = 2;
    }
 
    // n must be odd at this point - since it can no longer be divided by 2.  
    // So we can skip one element (Note i = i +2)

    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and n and divide n by i
        while (n%i == 0)
        {
            printf("n is %d and i is %d\n",n,  i);
            n = n/i;
            if (primeFactors[loc - 1] != i)
                primeFactors[loc++] = i;
        }
        // when i no longer divides n, skip to next number (Note i = i +2)
    }
 
    // This condition is to handle the case when n - the number left after all the divisions
    // is a prime number greater than 2
    if (n > 2) {
        printf ("the sqrt was: %d and the final factor: %d \n", len, n);
        if (primeFactors[loc - 1] != n)
            primeFactors[loc++] = n;
    }

    // Print all prime factors
    for (int i = 0; i < loc; i++)
        printf("%d ", primeFactors[i]);
    printf("\n");
}
 
int main()
{
    int n = 315;
    for (int i = 1; i <= 35; i++) {
        primeFactors(i);
        printf("\n");
    }
    primeFactors(n);
    printf("\n");
    primeFactors(n + 100);
    printf("\n");
    primeFactors(n + 1000);
    printf("\n");
    return 0;
}