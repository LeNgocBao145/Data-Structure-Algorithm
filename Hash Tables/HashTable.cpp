#include <iostream>

using namespace std;

//Hash Tables
//Step 1: create Hash Functions H(k)

//Load Factor α (alpha) = items in table / size of table
//Once alpha > threshold we need to grow the table size (ideally exponentially, double)


//Hash Table Seperate Chaining


//Hash Table Open Addressing

//1. Linear Probing
//P(x) = ax + b

//To deal with infinite loop and produce a full cycle modulo N
// a and N are relatively prime when Greatest Common Denominator GCD(a, N) = 1 

//2. Quadratic Probing
//P(x) = ax^2 + bx + c

//To tackle chaos with cycles, there are numerous ways but three of the most popular approaches are:

//a. Let P(x) = x^2, keep the table size is prime > 3 and alpha (load factor) α <= 0.5
//b. Let P(x) = (x^2 + x) / 2 and keep the table size is power of 2
//c. Let P(x) = (-1^x) * x^2 and keep the table size a prime N where N == 3 mod 4


//3. Double Hashing
//P(k, x) = x * H2(k), where H2(k) is a secondary hash function 

//H2(k) must hash the same type of keys as H1(k)
//NOTE: Notice the doubling hashing reduces to linear hashing (except that constant is unknown until runtime)

//To fix the issue with cycles pick the table size is prime and compute the value of δ
//  δ = H2(k) mod N
//  if δ = 0 then we are guaranteed to be stuck in a cycle, so when this happens set δ = 1
//Notice that 1 <= δ < N and GCD(δ, N) = 1 since N is prime

//Hash Table Removing Elelments open addressing
//Solution Removing: place a unique marker called a tombstone instead of NULL to indicate that a (k, v) pair
//has been deleted and that the bucket should be skipped during a search

//An optimization we can do it replace the earliest tombstone encountered with the value we did a lookup for.
//The next time we look up the key it will be found much faster!

int main()
{

    return 0;
}