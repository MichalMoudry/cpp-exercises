#include <iostream>
#include <vector>

// Abstract base class
class Shape {
private:
public:
    virtual void draw() const = 0;
    virtual void rotate() const = 0;
    virtual ~Shape() {}
};

// Abstract class
class OpenShape : public Shape {
public:
    virtual ~OpenShape() {}
};

// Abstract class
class ClosedShape : public Shape {
public:
    virtual ~ClosedShape() {}
};

// Concrete class
class Line final : public OpenShape {
public:
    virtual void draw() const override {
        std::cout << "Drawing a line\n";
    }
    virtual void rotate() const override {
        std::cout << "Rotating a line\n";
    }
    virtual ~Line() {}
};

class Circle final : public ClosedShape {
public:
    virtual void draw() const override {
        std::cout << "Drawing a circle\n";
    }
    virtual void rotate() const override {
        std::cout << "Rotating a circle\n";
    }
    virtual ~Circle() {}
};

void draw_and_rotate(const Shape& shape) {
    shape.draw();
    shape.rotate();
}

int main() {
    Line line1 {};
    draw_and_rotate(line1);

    Circle circle1 {};
    draw_and_rotate(circle1);

    Shape* s {new Circle()};
    s->draw();
    s->rotate();

    Shape* lptr {new Line()};

    std::cout << std::endl;
    std::vector<Shape*> shapes {s, lptr};
    for (const auto shape : shapes) {
        shape->draw();
    }

    delete s;
    delete lptr;
    return 0;
}