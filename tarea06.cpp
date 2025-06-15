#include <iostream>
#include <string>

class Printer {
public:
    Printer(const std::string& name) : name(name) {}

    void print(const std::string& document) {
        std::cout << "Imprimiendo: " << document << " en " << name << std::endl;
    }

    void status() {
        std::cout << "Estado de la impresora " << name << ": Listo para imprimir." << std::endl;
    }

private:
    std::string name;
};

int main() {
    Printer myPrinter("HP LaserJet");
    myPrinter.status();
    myPrinter.print("Informe de ventas");
    return 0;
}
