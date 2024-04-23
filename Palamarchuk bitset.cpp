// Palamarchuk bitset.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Bitset {
private:
    int number_elemets;
    vector<int> bitset;z
public:
    Bitset(int size) : number_elemets(size), bitset((size + 31) / 32, 0) {}

    bool find(int i) {
        return bitset[i / 32] & (1 << (i %32));
    }
    void add_element(int i) {
        bitset[i / 32] |= (1 << (i % 32));
    }
    void remove_element(int i) {
        bitset[i / 32] &= ~(1 << (i % 32));
    }

    Bitset my_union(const Bitset& another){

        Bitset result(this->number_elemets);

        for (int i = 0; i < this->bitset.size(); i++) {
            result.bitset[i] = this->bitset[i] | another.bitset[i];
        }

        return result;    
    }
    Bitset intersection(const Bitset& another){

        Bitset result(this->number_elemets);

        for (int i = 0; i < this->bitset.size(); i++) {
            result.bitset[i] = this->bitset[i] & another.bitset[i];
        }
        return result;
    }
    Bitset difference(const Bitset& another){
        Bitset result(this->number_elemets);

        for (int i = 0; i < this->bitset.size(); i++) {
            result.bitset[i] = this->bitset[i] & ~another.bitset[i];
        }
        return result;
    }

    void show() {
        for (int i = 0; i < this->number_elemets; i++) {
            cout << find(i);
        }
        cout << endl;
    }
};

int main() {
    Bitset bs1(10);
    bs1.add_element(1);
    bs1.add_element(3);
    bs1.add_element(5);
    bs1.add_element(7);
    bs1.add_element(9);
    cout << "bs1" << endl;
    bs1.show();

    Bitset bs2(10);
    bs2.add_element(0);
    bs2.add_element(2);
    bs2.add_element(4);
    bs2.add_element(6);
    //bs2.add_element(33);
    cout << "bs2" << endl;
    bs2.show();

    Bitset bs3 = bs1.my_union(bs2);
    cout << "my_union" << endl;
    bs3.show();

    Bitset bs4 = bs1.intersection(bs2);
    cout << "intersection" << endl;
    bs4.show();

    Bitset bs5 = bs1.difference(bs2);
    cout << "difference" << endl;
    bs5.show();

    return 0;
}