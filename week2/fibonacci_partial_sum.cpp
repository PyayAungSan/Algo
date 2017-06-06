#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}


long fibonacci_sum_fast(long long n){
    
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

long fibonacci_sum_partial_fast(long long from, long long to){

    return fibonacci_sum_fast(to) - fibonacci_sum_fast(from-1);
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
