// C program for RSA asymmetric cryptographic
// algorithm. For demonstration values are
// relatively small compared to practical
// application
#include<stdio.h>
#include<math.h>

// Returns greatest common devider of a and b
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}

// p , q should be as large as possible in order to make factorization harder
// usually done using a CSPRNG and than checking if the number is prime

// N is called the module and represents the Zn series - all the natural numbers
// N is used as the base to the modular arithmatics
// --- which means sums and products are the remainder from division by N

// another reason p q should be large, is so that N would be large
// since we use modular arithmatics on base N our range of numbers is N - 1
// therefore we need a large N so that we can encrypt a large range of numbers

// phi(n) is (p-1)(q-1) and represents all the 
// numbers that have common factors with n

// e is the public key which is used in order encrypt
// e must be smaller than phi(n)
// e must also be coprime with N and phi(n)

// d is the private key used for decryption

// encryption: 
// we take the integer value we want to encrypt,
// raise it to the power of e - our enctyption key
// and than take the mod of n
// it is the encrypted value

// decryption:
// we take the integer value we want to decrypt,
// raise it to the power of d - our decryption key
// and than the mod of n
// it is the original value

// notice: the diffie-helman key exchange allows both parties to encrypt and decrypt and thus send messsages.
// if only one party needs to send messages there is no need for the key exchange.
// only one party will send its public (the reciever), the other party (the sender)
// will encrypt using the the public key he got and will send the encrypted message.
// it will than we be decrypted by the receiving party.
// This is a typical use of assymetric encryption without the diffie-helman key exchange.
// it can be used as a standard to pass a symmetric key (like AES).
// this code will not get into the diffie-helman key exchange.


//// Code to demonstrate RSA algorithm
int main()
{
    // Two random prime numbers
    double p = 17;
    double q = 23;
  
    // First part of public key:
    double n = p*q;
  
    // Finding other part of public key.
    // e stands for encrypt
    double e = 2;
    double phi = (p-1)*(q-1);
    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }
    
    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
    int k = 2;  // A constant value
    double d = (1 + (k*phi))/e;
  
    // Message to be encrypted
    double msg = 2;
  
    printf("Message data = %lf", msg);
  
    // Encryption c = (msg ^ e) % n
    double c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %lf", c);
  
    // Decryption m = (c ^ d) % n
    double m = pow(c, d);
    m = fmod(m, n);
    printf("\nOriginal Message Sent = %lf\n", m);
  
    return 0;
}

// to run use:
// 1. gcc -o rsa RSA.c
// 2. ./rsa

// to add the math library add -lm