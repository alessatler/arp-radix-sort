#include <algorithm>
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

// TODO ---------------------------------------------------

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

    for (int k = 0; k < 8; k++) {
        vector<int> D = pridobiD(A, k);

        int count[2] = {0, 0};
        for (int bit : D) {
            count[bit]++;
        }

        count[1] += count[0];

        vector<int> outputA(A.size());

        for (int i = A.size() - 1; i >= 0; i--) {
            outputA[count[D[i]] - 1] = A[i];
            count[D[i]]--;
        }

        A = outputA;
    }

    Izpis_Stevil(&A[0], A.size());

    return 0;
}
