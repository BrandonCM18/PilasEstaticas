#include <iostream>
#include <string>

const int TAM = 100;

class Empleado {
private:
    std::string nombre;
    int edad;
public:
    Empleado() : nombre("Juanito"), edad(13) {}
    Empleado(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

    friend std::ostream& operator<<(std::ostream& o, const Empleado& e) {
        o << "Nombre: " << e.nombre << "\tEdad: " << e.edad << std::endl;
        return o;
    }
};

class Pila {
private:
    Empleado datos[TAM];
    int top;
public:
    Pila() : top(-1) {}

    bool vacia() const {
        return top == -1;
    }

    bool llena() const {
        return top == TAM - 1;
    }

    bool push(const Empleado& elem) {
        if (llena()) {
            std::cout << "\n Pila llena, no se puede apilar mas." << std::endl;
            return false;
        }
        datos[++top] = elem;
        return true;
    }

    bool pop() {
        if (vacia()) {
            std::cout << "\n Pila vacia, no se puede desapilar mas." << std::endl;
            return false;
        }
        top--;
        return true;
    }

    Empleado topElem() const {
        if (vacia()) {
            std::cout << "\n Pila vacia, no se puede obtener el elemento en la cima de la pila." << std::endl;
            return Empleado();
        }
        return datos[top];
    }
};

int main() {
    Pila miPila;
    int opcion;

    do {
        std::cout << "\nMenu de Pila:\n";
        std::cout << "1. Push (Apilara un objeto de la clase empleado)\n";
        std::cout << "2. Pop (Desapilara un objeto de la clase empleado)\n";
        std::cout << "3. Top (Imprimira en pantalla la informacion del objeto que se encuentra en la cima de la pila)\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre;
                int edad;
                std::cout << "Ingrese el nombre del empleado: ";
                std::cin >> nombre;
                std::cout << "Ingrese la edad del empleado: ";
                std::cin >> edad;
                Empleado empleado(nombre, edad);
                miPila.push(empleado);
                break;
            }
            case 2:
                miPila.pop();
                break;
            case 3: {
                Empleado elementoCima = miPila.topElem();
                std::cout << "Elemento en la cima de la pila:\n" << elementoCima;
                break;
            }
            case 4:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no válida. Ingrese una opcion valida.\n";
        }
    } while (opcion != 4);

    return 0;
}

