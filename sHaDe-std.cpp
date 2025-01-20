#include <iostream>
#include "src/Timer.h"
#include "src/Array.h"
#include <string>

int main()
{
    using namespace std;

    Array<string, 5> a;
    a[0] = "hi";
    a[4] = "poopoo";
    a[2] = "420";
    a[1] = "69";
    int i = 20;

    cout << "\n";
    {
        Timer timer;
        Array<string, 5> b(a);
    }
    cout << "\n";
    {
        Array<string, 5> c("hi");
        c.print();

        Array<string, 5> d("301");
        d.print();

        c.swap(d);
        c.print();
        d.print();
    }

    cout << "\n";
    a.print();
    cout << endl;
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
