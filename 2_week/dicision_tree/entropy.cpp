class Solution {
public:
    double calculateEntropy(vector<int>& input) {
        const int inputSize = input.size();        
        double entropy = 0.0;
        unordered_map<int,int> value_to_count;
        
        for (const int& n : input) {
            value_to_count[n]++;     // 각 value에 해당하는 count 값을 key에 저장해둔다.
        }
        
        for (const pair<int,int>& p : value_to_count) {
            const int value = p.first;
            const int hitcount = p.second;
            
            // p.first는 배열에 각 요소 값, p.second는 요소돌의 count
            //             
            //                         double probability = static_cast<double>(hitcount) / inputSize; // 각 요소의 probability 를 구한 뒤
            //                                     entropy -= (probability * log2(probability));  // log값을 취해 각자 빼준다.
            //                                             }
            //                                                     
            //                                                             return entropy;        
            //                                                                 }
            //                                                                 };
