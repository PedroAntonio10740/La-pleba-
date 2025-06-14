#include <iostream>
#include <string>

using namespace std;

// Clase base
class Notificacion {
public:
    virtual void enviar(string mensaje) = 0;
};

// Clases derivadas
class Email : public Notificacion {
public:
    void enviar(string mensaje) override {
        cout << " Enviando email: " << mensaje << endl;
    }
};

class Push : public Notificacion {
public:
    void enviar(string mensaje) override {
        cout << " Enviando notificación push: " << mensaje << endl;
    }
};

class SMS : public Notificacion {
public:
    void enviar(string mensaje) override {
        cout << " Enviando mensaje SMS: " << mensaje << endl;
    }
};

// Fábrica
class NotificationFactory {
public:
    static Notificacion* crear(string tipo) {
        if (tipo == "email") {
            return new Email();
        } else if (tipo == "push") {
            return new Push();
        } else if (tipo == "sms") {
            return new SMS();
        } else {
            return nullptr;
        }
    }
};

// Función principal
int main() {
    Notificacion* email = NotificationFactory::crear("email");
    if (email) {
        email->enviar("Hola desde email");
        delete email;
    }

    Notificacion* push = NotificationFactory::crear("push");
    if (push) {
        push->enviar("Hola desde push");
        delete push;
    }

    Notificacion* sms = NotificationFactory::crear("sms");
    if (sms) {
        sms->enviar("Hola desde SMS");
        delete sms;
    }

    return 0;
}
