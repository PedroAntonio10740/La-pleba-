#include <iostream>

int main() {
    int value = 42;
    int* ptr = &value; // Puntero que apunta a la dirección de 'value'

    std::cout << "Valor: " << value << std::endl;
    std::cout << "Valor a través del puntero: " << *ptr << std::endl;
    std::cout << "Dirección de 'value': " << &value << std::endl;
    std::cout << "Dirección almacenada en 'ptr': " << ptr << std::endl;

    return 0;
}
