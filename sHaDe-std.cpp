#include <iostream>
#include "src/Timer.h"
#include "src/Array.h"
#include "src/Vector.h"
#include <string>

struct Point3D {
    float x = 0, y = 0, z = 0;

    Point3D() { std::cerr << "Created empty point" << std::endl; };
    Point3D(float scalar) : x(scalar), y(scalar), z(scalar) {
        std::cerr << "Created point from scalar" << std::endl;
    };
    Point3D(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {
        std::cerr << "Created point" << std::endl;
    };
    Point3D(const Point3D& other) : x(other.x), y(other.y), z(other.z) {
        std::cerr << "Copied point" << std::endl;
    }
    Point3D(Point3D&& other) noexcept : x(other.x), y(other.y), z(other.z) {
        std::cerr << "Moved point" << std::endl;
    }
    ~Point3D() { std::cerr << "Destroyed point" << std::endl; }

    Point3D& operator= (const Point3D& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        std::cerr << "Copy assigned point" << std::endl;
        return *this;
    }
    Point3D& operator= (Point3D&& other) noexcept {
        x = other.x;
        y = other.y;
        z = other.z;
        std::cerr << "Move assigned point" << std::endl;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& out, Point3D& pt) {
        out << " Point3D(" << pt.x << "," << pt.y << "," << pt.z << ") ";
        return out;
    }
};


int main()
{
    using std::cout, std::endl, std::string;

    //Vector<int> nums;
    {
        Vector<Point3D> words;

        words.push(Point3D(5));
        cout << endl;

        words.push(Point3D());
        cout << endl;

        words.push(Point3D(69, 420, 3));
        cout << endl;

        words.print();
        
        words.pop();
        cout << endl;
        
        words.print();
        cout << endl;
    }
    cout << "done done" << endl;
}
