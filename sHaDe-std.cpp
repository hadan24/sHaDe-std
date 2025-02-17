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
    friend std::ostream& operator << (std::ostream& out, const Point3D& pt) {
        out << " Point3D(" << pt.x << "," << pt.y << "," << pt.z << ") ";
        return out;
    }
};


int main()
{
    using std::cout, std::endl, std::string;

    const Array<Point3D, 3> con{0,6,9};
    cout << "Built con\n" << endl;

    Array<Point3D, 3> woo {
    Point3D(),
    Point3D(69),
    Point3D(4, 2, 0),
    };
    woo[0] = Point3D(24);
    cout << "Built woo\n" << endl;

    cout << "Iterator testing!\n" << endl;

    cout << "No iters" << endl;
    for (int i = 0; i < woo.len(); i++)
        cout << woo[i] << ",";
    cout << endl;
    for (int i = 0; i < con.len(); i++)
        cout << con[i] << ",";
    cout << endl << endl;

    cout << "Range for loop" << endl;
    for (Point3D& i : woo)
        cout << i << ",";
    cout << endl;
    for (const Point3D& i : con)
        cout << i << ",";
    cout << endl << endl;

    cout << "Explicit iter" << endl;
    for (Array<Point3D, 3>::Iter it = woo.begin(); it != woo.end(); it++)
        cout << *it << ",";
    cout << endl;
    
    for (Array<Point3D, 3>::ConstIter it = con.begin(); it != con.end(); it++)
        cout << *it << ",";
    cout << endl << endl;
}
