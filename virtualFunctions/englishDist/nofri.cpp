// nofri.cpp
// Limitation to overloaded + operator
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////
class Distance { // English Distance class
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0) {} // No-arg constructor

    Distance(float fltfeet) { // Convert float to Distance
        feet = static_cast<int>(fltfeet);             // Feet is integer part
        inches = 12 * (fltfeet - feet);               // Inches is remainder
    }

    Distance(int ft, float in) { // Constructor with two args
        feet = ft;
        inches = in;
    }

    void showdist() const { // Display distance
        cout << feet << "'-" << inches << "\"";
    }

    Distance operator + (Distance); // Overloaded + operator

    // Optional: define conversion from float to Distance to allow float + Distance
    friend Distance operator + (float lhs, const Distance& rhs);
};

//--------------------------------------------------------------
// Add this distance to d2
Distance Distance::operator + (Distance d2) {
    int f = feet + d2.feet;           // Add feet
    float i = inches + d2.inches;     // Add inches
    if(i >= 12.0) {
        i -= 12.0;
        f++;                          // Convert extra inches to feet
    }
    return Distance(f, i);
}

//--------------------------------------------------------------
// Allow float + Distance (not just Distance + float)
Distance operator + (float lhs, const Distance& rhs) {
    Distance dtemp(lhs);             // Convert float to Distance
    return dtemp + rhs;              // Use member operator+
}

////////////////////////////////////////////////////////////////
int main() {
    Distance d1 = 2.5;              // Uses float-to-Distance constructor
    Distance d2 = 1.25;
    Distance d3;

    cout << "\nd1 = "; d1.showdist();
    cout << "\nd2 = "; d2.showdist();

    d3 = d1 + 10.0;                 // Distance + float: OK
    cout << "\nd3 = "; d3.showdist();

    d3 = 10.0 + d1;                 // float + Distance: now also OK
    cout << "\nd3 = "; d3.showdist();

    cout << endl;
    return 0;
}
