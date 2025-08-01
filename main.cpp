#include <iostream>
#include <cstdlib> 

using namespace std;

int main() {
    int* N = (int*)malloc(sizeof(int));
    char* C = (char*)malloc(sizeof(char));
    float* F = (float*)malloc(sizeof(float));

    if (!N || !C || !F) {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter an Integer:" << endl;
    cin >> *N;

    cout << "Enter a char:" << endl;
    cin >> *C;

    cout << "Enter a float:" << endl;
    cin >> *F;

    cout << "Displaying values" << endl;
    cout << "Integer: " << *N << endl;
    cout << "Character: " << *C << endl;
    cout << "Float: " << *F << endl;

    free(N);
    free(C);
    free(F);

    return 0;
}
