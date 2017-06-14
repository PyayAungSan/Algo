#include <iostream>
#include <vector>

using namespace std;



vector<int> optimal_summands(int n) {
  vector<int> summands;
  
    /*
     
     Given integers k and l, where l<= k, represent k as a sum of as many pairwise
     distinct integers each of which is at least l as possible.
     
     if k <= 2l then answer is 1. Otherwise, l is summands
     
     */
    
    int k = n ;
    int l = 1 ;
    
    while (k>0 && k > (2*l)){
    
        summands.push_back(l);
        k -= l;
        l++;
    
    }
    summands.push_back(k);
    
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
