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
    static friend std::ostream& operator<< (std::ostream& out, const Point3D& pt) {
        out << " Point3D(" << pt.x << "," << pt.y << "," << pt.z << ") ";
        return out;
    }
};


int main()
{
    using std::cout, std::endl, std::string;

    Vector<Point3D> swp;
    swp.emplace();
    swp.emplace(69.0f);
    swp.emplace(4.0f, 2.0f, 0.0f);
    cout << "Built swp\n" << endl;
    cout << *(swp.insert(swp.const_begin() + 2, 30.0f)) << endl;
    swp.print();
    swp.erase(swp.const_begin() + 3);

    cout << endl;

    Vector<Point3D> woo;
    woo.emplace(4.0f);
    woo.print();
    cout << "Built woo\n" << endl;

    woo.swap(swp);
    woo.print();
    swp.print();
    cout << woo[-1] << endl;
    woo.resize(2);

    const Vector<Point3D> con(std::move(swp));
    cout << "Built con\n" << endl;

    cout << "Woo (2 elements): ";
    woo.print();

    cout << "Con (1 element): ";
    con.print();

    cout << endl << endl;
}
