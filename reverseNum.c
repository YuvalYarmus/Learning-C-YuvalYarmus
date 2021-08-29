#include <limits.h>
#include <stdio.h>


/*
The different types of variables define their bounds. A char can range only from -128 to 127,
whereas a long can range from -2,147,483,648 to 2,147,483,647
(long and other numeric data types may have another range on different computers,
for example:
from –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 on 64-bit computer).

Note that C does not have a boolean type. Usually, it is defined using the following notation:

#define BOOL char
#define FALSE 0
#define TRUE 1

A long int is a signed integral type that is at least 32 bits,
while a long long or long long int is a signed integral type is at least 64 bits.
*/


int reverse(int x) {
    long long val = 0;
	do 
	{
		val = val * 10 + x % 10;
		x /= 10;
	} while (x);
	
	return (val > INT_MAX || val < INT_MIN) ? 0 : val;
}

int main() {
	int n = -15;
	int rev = reverse(n);
	printf("\n");
	printf("og num = %d\n", n);
	printf("reversed = %d\n", rev);
}
