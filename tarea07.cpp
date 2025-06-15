#include <iostream>
#include <memory>

// Clase base
class Shape {
public:
    virtual void draw() = 0; // Método virtual puro
    virtual ~Shape() = default; // Destructor virtual
};

// Clases concretas
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Dibujando un círculo." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Dibujando un cuadrado." << std::endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        std::cout << "Dibujando un triángulo." << std::endl;
    }
};

// Clase Factory
class ShapeFactory {
public:
    std::unique_ptr<Shape> createShape(const std::string& shapeType) {
        if (shapeType == "Círculo") {
            return std::make_unique<Circle>();
        } else if (shapeType == "Cuadro") {
            return std::make_unique<Square>();
        } else if (shapeType == "Triángulo") {
            return std::make_unique<Triangle>();
        }
        return nullptr; // Retorna nullptr si no se encuentra la figura
    }
};

int main() {
    ShapeFactory shapeFactory;

    auto circle = shapeFactory.createShape("Círculo");
    if (circle) circle->draw();

    auto square = shapeFactory.createShape("Cuadro");
    if (square) square->draw();

    auto triangle = shapeFactory.createShape("Triángulo");
    if (triangle) triangle->draw();

    return 0;
}
