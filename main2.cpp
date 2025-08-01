#include <iostream>
#include <cstdlib> 

using namespace std;

int main() {
    int N;

    cout << "Enter the number of elements: ";
    cin >> N;

    int* A = (int*)calloc(N, sizeof(int));

    if (A == nullptr) {
        cerr << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter " << N << " integers:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int maxElement = A[0];
    for (int i = 1; i < N; i++) {
        if (A[i] > maxElement) {
            maxElement = A[i];
        }
    }

    cout << "The largest element is: " << maxElement << endl;

    free(A);

    return 0;
}
