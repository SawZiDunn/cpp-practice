#include <iostream>

class Box {
private:
    double width;

public:
    Box(double wid) : width(wid) {}

    // Friend class declaration
    friend class BoxInspector;
};

// Friend class definition
class BoxInspector {
public:
    void revealWidth(const Box& box) {
        // Direct access to private member 'width'
        std::cout << "Inspecting width of box: " << box.width << std::endl;
    }
};

int main() {
    Box box(8.3);
    BoxInspector inspector;

    // The friend class can access the private members of Box
    inspector.revealWidth(box);

    return 0;
}
