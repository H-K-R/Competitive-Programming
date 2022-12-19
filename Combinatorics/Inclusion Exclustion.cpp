/**
    Name : Inclusion-Exclusion
    Description : compute the union of sets
    Time Complexity : O(2^n)
    Space : O(n)
    Source : collected form hacker earth
*/

int n; // the number of sets in the set A
int result = 0; //final result, the cardinality of sum of all subsets of A
for(int b = 0; b < (1 << n); ++b){
     vector<int> indices;
     for(int k = 0; k < n; ++k){
          if(b & (1 << k)){
                // we could work with this values
                indices.push_back(k);
          }
     }
     int cardinality = intersectionCardinality(indices); // intersections
     if(indices.size() % 2 == 1) result += cardinality;
     else result -= cardinality;
}
cout << result << endl; //printing the final result
