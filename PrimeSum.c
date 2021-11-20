#include<stdio.h>
#include<math.h>



char isPrime(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// int* CantBePrimeSummed()
// {
//     int* cantBePrimeSummed = (int*)malloc(sizeof(int) * 100);
//     int pos = 0;
//     for (int i = 2; i < 197; i++)
//     {
//         char check = 1;
//         for (int j = 0; j < i - j; j++)
//             if (isPrime(i - j) && isPrime(j))
//                 check = 0;
        
//         if (check)
//             cantBePrimeSummed[pos++] = i;
//     }
//     return &cantBePrimeSummed;
// }

// int main(){
//     int* cantBePrimeSummed = CantBePrimeSummed();
//     printf("%d", cantBePrimeSummed);
//     for (cantBePrimeSummed++; cantBePrimeSummed < 100; cantBePrimeSummed++)
//         printf("%d", *cantBePrimeSummed);
//     return 0;
// }



char isValidSum(int sum){
    // a valid sum is a sum that can not be summed with 2 primes
    for (int j = 2; j < sum - j; j++){
        if (isPrime(j) && isPrime(sum-j)) {
            return 0;
        }
    }
    return 1;
}

char check(int prod, int j, int l){
    // j is one of the factors of prod
    // l is 
    double Sqrt = sqrt(prod);
    for (int i = 2; i < sq; i++){
        if (i == j || i == l) continue;
        if (prod % i == 0){
            if (isValidSum(i + prod / i)){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    // there cant be a sum smaller than 5 - all others are composed of 2 primes
    for (int sum = 5; sum < 197; sum++){
        if (!isValidSum(sum)) continue;
        for (int j = 2; j < sum - j; j++){
            int mul = j * (sum - j);
            if (check(mul, j, 0)){
                char ch = 1;
                for (int l = 2; l < sum - l; l++){
                    if (j == l) continue;
                    if (check(l * (l - sum), l, j)){
                        ch = 0;
                        break;
                    }
                }
                if (ch) printf("%d, %d\n", j, sum - j);
            }
        }
    }
    return 0;
}