#include<bits/stdc++.h>

using namespace std;

class ProductOfNumbers {
    vector<int> prefixProduct;
public:
    ProductOfNumbers() {
        prefixProduct.push_back(1);
    }
    
    void add(int num) {
        if(!num){
            prefixProduct.clear();
            prefixProduct.push_back(1);
            return;
        }
        prefixProduct.push_back(num * prefixProduct.back());
    }
    
    int getProduct(int k) {
        if(k > prefixProduct.size() - 1){ return 0;}
        return prefixProduct.back() / prefixProduct[prefixProduct.size() - k - 1];
    }
};

int main(){
    ProductOfNumbers p;
    p.add(3);
    p.add(0);
    p.add(2);
    p.add(5);
    p.add(4);
    cout << p.getProduct(2) << "\n";
    cout << p.getProduct(3) << "\n";
    cout << p.getProduct(4) << "\n";
    p.add(8);
    cout << p.getProduct(2) << "\n";
    return 0;
}