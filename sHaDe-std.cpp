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
        for (int i = 0; i < words.len(); i++) {
            cout << words[i] << ", ";
        }
        cout << endl;
        words.pop();
        for (int i = 0; i < words.len(); i++) {
            cout << words[i] << ", ";
        }
        cout << endl;
    }
    cout << "done done" << endl;
}
