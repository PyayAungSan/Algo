#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


void print_map (const unordered_map<double,int>& map){

    for (pair<double,int> element: map){
        cout << element.first<<" "<<element.second<<endl;
    }

}

//bool greaterthan_fun (double first, double second){ return first > second; }
//Output maximum value of fraction of items
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;
    
    int currentWeight = 0;
    
    
    double max = values[0]/weights[0];
    
    unordered_map<double,int> absolute_values;
    
    for(int i =0 ;i < values.size();  ++i){
        
        absolute_values.insert({values[i]/weights[i], i});
    }
    //sort(absolute_values.begin(), absolute_values.end(), greaterthan_fun);
    
    print_map(absolute_values);
    
    for (auto& element: absolute_values){
    
        cout<<element.first <<endl;
        
       // if (capacity == 0) return value;
        
        if ((currentWeight + weights[element.second]) <= capacity){
            currentWeight+= weights[element.second];
            value +=  values[element.second];
        }
        else {
        
            int remain = capacity - currentWeight;
            value +=  values[element.second];
            break;
        }
    
    }
  return value;
}


int main() {
   
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0;
}
