#include <iostream>
#include <complex>

using namespace std;

const double Pi = 3.14159265359;
int c = 0;

void Furie(complex<double> arr[], double N) {
    complex<double> z(0, 1);

    complex<double> *A = new complex<double>[4];

    cout << "Fourier transform: " << endl;
    for (int i = 0; i < N; i++) {
        A[i] = 0;
        for (int j = 0; j < N; j++) {
            A[i] += exp(-2 * Pi * j * i / N * z) * arr[j];
            c += 5;
        }
        A[i] /= N;
        printf("%.10f %.10f \n", A[i].real(), A[i].imag());
    }

    cout << endl << endl;
    
    
	cout << "Inverse Fourier transform: " << endl;
    for (int i = 0; i < N; i++) {
        arr[i] = 0;
        for (int j = 0; j < N; j++) {
            arr[i] += exp(2 * Pi * j * i / N * z) * A[j];
            c += 5;
        }
        printf("%.10f %.10f \n", arr[i].real(), arr[i].imag());
    }
    cout << endl << endl;

    cout << "Complexity: " << c << endl;
}


int main() {
    double arrSize = 0;
    arrSize = 4;
    cout << "Input array elements: " << endl;

    complex<double> *arr = new complex<double>[4];

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }
    cout << endl;

    Furie(arr, arrSize);
}