/*Pisano Period
 
  So objective is how to search a similiar pattern.

 There is a similiar pattern of the reminder which always start with 01.
 
 This is known as Pisano period becuase Fib sequence always start with 0, 1 , 1 , 2 , 3 , 5 ...... and reminder always starts with 0 ,1
 
 
 Approach
 
1. We can start finding the length of pattern then we can use it to divide "n" so that we will get reminder.
 
2. Or we can use Dynamic Programming approach where we will use array that we already created on Pisano period. Doing so will reduce looping through the n again.
  Also , instead of saving the large numbers, we can only store the reminders
*/

#include <iostream>
#include <vector>

using namespace std;

void print_vec(const vector<long long>& vec){

    cout<<"print vec "<< endl;
    for (long long i:vec) cout << i ;
    cout <<endl;

}

vector<long long> Pisano_period(long long m){
    
    
    vector<long long> pattern = {0,1};
    
    int i=2;
    
    while(true){
    
        pattern.push_back((pattern[i-2]+pattern[i-1])%m);
        
        
        if(pattern[i-1]==0 && pattern[i]==1) break;
        ++i;
        }
    
    cout << "i is  "<<i <<" value of i "<<pattern[i]<<endl;
    //By the time we end the loop, we already added up 0, 1. So , we gotta remove it
  
    
    pattern.erase (pattern.begin()+(i -2) ,pattern.begin()+i);
   
     return pattern;

}

long long get_fibonacci_huge_fast(long long n, long long m){

    vector<long long> pattern = Pisano_period(m);
    
    long long reminder_index  = n % (pattern.size());
    
    
    return pattern[reminder_index];
   }

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n, m;
    cin >> n >> m;
    //cout << get_fibonacci_huge_naive(n, m) << '\n';
    cout << get_fibonacci_huge_fast(n, m) << '\n';

}
