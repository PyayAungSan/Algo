#include <iostream>
using namespace std;
/*

 1. 
 period 60
 
 2.
 f(0)+f(1)+....+f(n) = f(n+2) - 1
 */
int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n){

/*
 last digit of fib sequence repeats after every 60th.
 We use that advantage not to loop all the way n times
 */

    int reminder = (n+2)% 60;
    
    if (reminder <= 1) return reminder;
    
    /*
     
     we can add until the loop reaches to the reminder
     or we can use this fib addition number theory
     
     f(0)+f(1)+....+f(n) = f(n+2) - 1
 
     */
    int previous = 1;
    int current =1;
    int temp =0 ;
    for(int i =2; i<= reminder ; i++) {
    
        current = (previous + temp) %10;
        temp = previous;
        previous = current;
    }
    
    current = current - 1;
    
  //  if(current < 0) return current+10;
    
    return current;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n)<<endl;
    std::cout << fibonacci_sum_fast(n)<<endl;

}
