#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;

    int* arr = new int[N];

    cout << "Enter " << N << " integers:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sumEven = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] % 2 == 0) {
            sumEven += arr[i];
        }
    }
    cout << "Sum of even numbers is: " << sumEven << endl;

    delete[] arr;

    return 0;
}
