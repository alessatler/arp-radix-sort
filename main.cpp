#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

bool Branje_Stevil(vector<int> &vec, const char s[]) {
    ifstream input(s);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (!input.eof()) {
        input >> st;
        vec.push_back(st);
        while (isspace(input.peek())) input.get();
    }
    input.close();
    return true;
}

void Izpis_Stevil(int* polje, unsigned int velikost) {
    ofstream output("out.txt");

    for (int i = 0; i<velikost; i++)
        output << polje[i] << ' ';
}
//

void getMinMax(int& min, int& max, vector<int>& nums){
    for(auto num: nums){
        if (num < min)
            min = num;
        else if (num > max)
            max = num;
    }
}

void subtractMin(const int& min, vector<int>& nums) {
    for (int& num: nums) {
        num -= min;
    }
}

void addMin(const int& min, vector<int>& nums) {
    for (int& num: nums) {
        num += min;
    }
}

vector<int> pridobiD(const vector<int> &vec, int k) {
    vector<int> D;
    for (int a: vec) {
        D.push_back((a >> k) & 1);
    }

    return D;
}

int main(int argc, const char* argv[]) {
    vector<int> A;

    if (argc < 2) return 0;
    if (!Branje_Stevil(A, argv[1])) return 0;

    int k = 0;
    vector<int> D = pridobiD(A, k);


    // TODO

    Izpis_Stevil(&D[0], D.size());

    return 0;
}
