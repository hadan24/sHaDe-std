#include <iostream>
#include "src/Timer.h"
#include "src/Array.h"
#include <string>
#include <array>

int main()
{
    using namespace std;

    Array<int, 3> woo;
    woo[0] = 42;
    woo[1] = 69;
    woo[2] = 420;
    cout << "Iterator testing!\n" << endl;

    cout << "No iters" << endl;
    for (int i = 0; i < woo.len(); i++)
        cout << woo[i] << ",";
    cout << endl << endl;

    cout << "Range for loop" << endl;
    for (int i : woo)
        cout << i << ",";
    cout << endl << endl;

    cout << "Explicit iter" << endl;
    for (Array<int, 3>::Iter it = woo.begin(); it != woo.end(); it++)
        cout << *it << ",";
    cout << endl << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
