#include<bits/stdc++.h>

using namespace std;

class NumberContainers {
    private:
        // Map to store number -> min heap of indices
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numberToIndices;
        // Map to store index -> number
        unordered_map<int, int> indexToNumber;
    public:
        NumberContainers() {}
        
        void change(int index, int number) {
            indexToNumber[index] = number;
            numberToIndices[number].push(index);
        }
        
        int find(int number) {
            if(numberToIndices.find(number) == numberToIndices.end()){
                return -1;
            }

            auto& minHeap = numberToIndices[number]; // Priority queue of indices

            while(!minHeap.empty()){
                int index = minHeap.top();
                if(indexToNumber[index] == number){
                    return index;
                }
                minHeap.pop();
            }
            return -1;
        }
    };

int main(){
    NumberContainers nc;
    nc.change(0, 1);
    nc.change(1, 2);
    nc.change(2, 3);
    cout << nc.find(1) << "\n";
    cout << nc.find(2) << "\n";
    cout << nc.find(3) << "\n";
    return 0;
}