#include <iostream>
#include <complex>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInMandelbrot(const complex<double>& c, int N) {
    complex<double> z = 0;
    for (int i = 0; i < N; ++i) {
        z = z * z + c;
        if (abs(z) > 2.0) {
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 4 || string(argv[1]) == "--help") {
        cerr << "Usage: " << argv[0] << " <N> <real> <imag>" << endl;
        cerr << "Example: " << argv[0] << " 1000 -0.5 0" << endl;
        return 1;
    }

    int N = atoi(argv[1]);
    double real = atof(argv[2]);
    double imag = atof(argv[3]);

    complex<double> c(real, imag);

    cout << fixed << setprecision(3);
    if (!isInMandelbrot(c, N)) {
        cout << "The number " << c << " is not in the Mandelbrot set!" << endl;
    } else {
        cout << "The number " << c << " is in the Mandelbrot set!" << endl;
    }

    return 0;
}
