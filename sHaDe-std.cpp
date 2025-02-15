#include <iostream>
#include "src/Timer.h"
#include "src/Array.h"
#include "src/Vector.h"
#include <string>

int main()
{
    using std::cout, std::endl;

    //Vector<int> nums;
    {
        Vector<std::string> words;

        words.push("5");
        words.push("20");
        words.print();

        words.pop();
        words.print();

    }
    cout << "done done" << endl;
}
