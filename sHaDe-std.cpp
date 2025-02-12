#include <iostream>
#include "src/Timer.h"
#include "src/Array.h"
#include <string>

int main()
{
    using namespace std;

    const Array<int, 3> con(20);
    Array<int, 3> woo;
    woo[0] = 42;
    woo[1] = 69;
    woo[2] = 420;

    cout << "Iterator testing!\n" << endl;

    cout << "No iters" << endl;
    for (int i = 0; i < woo.len(); i++)
        cout << woo[i] << ",";
    cout << endl;
    for (int i = 0; i < con.len(); i++)
        cout << con[i] << ",";
    cout << endl << endl;

    cout << "Range for loop" << endl;
    for (int i : woo)
        cout << i << ",";
    cout << endl;
    for (int i : con)
        cout << i << ",";
    cout << endl << endl;

    cout << "Explicit iter" << endl;
    for (Array<int, 3>::Iter it = woo.begin(); it != woo.end(); it++)
        cout << *it << ",";
    cout << endl;
    for (Array<int, 3>::ConstIter it = con.begin(); it != con.end(); it++)
        cout << *it << ",";
    cout << endl << endl;
}
