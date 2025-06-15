#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// Clase base para figuras
class Shape {
public:
    virtual double GetArea() const = 0; // Método virtual puro
    virtual ~Shape() = default; // Destructor virtual
};

// Clase concreta: Círculo
class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}
    
    double GetArea() const override {
        return M_PI * radius * radius;
    }

private:
    double radius;
};

// Clase concreta: Cuadrado
class Square : public Shape {
public:
    Square(double side) : side(side) {}

    double GetArea() const override {
        return side * side;
    }

private:
    double side;
};

// Clase Repository
class RepoVector {
public:
    void Save(std::shared_ptr<Shape> shape) {
        shapes.push_back(shape);
    }

    double GetArea() const {
        double totalArea = 0;
        for (const auto& shape : shapes) {
            totalArea += shape->GetArea();
        }
        return totalArea;
    }

private:
    std::vector<std::shared_ptr<Shape>> shapes;
};

int main() {
    RepoVector repo;

    repo.Save(std::make_shared<Circle>(5.0)); // Guardar un círculo
    repo.Save(std::make_shared<Square>(4.0)); // Guardar un cuadrado

    std::cout << "Área total: " << repo.GetArea() << std::endl; // Obtener área total

    return 0;
}
