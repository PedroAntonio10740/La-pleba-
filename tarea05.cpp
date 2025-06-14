#include <iostream>
#include <string>

class IGitHubRepository {
public:
    virtual void crearRepositorio(const std::string& nombre) = 0;
    virtual void eliminarRepositorio(const std::string& nombre) = 0;
    virtual void listarRepositorios() = 0;
    virtual ~IGitHubRepository() = default;
};

class GitHubRepository : public IGitHubRepository {
public:
    void crearRepositorio(const std::string& nombre) override {
        std::cout << "Repositorio '" << nombre << "' creado en GitHub." << std::endl;
    }

    void eliminarRepositorio(const std::string& nombre) override {
        std::cout << "Repositorio '" << nombre << "' eliminado de GitHub." << std::endl;
    }

    void listarRepositorios() override {
        std::cout << "Listando repositorios en GitHub..." << std::endl;
    }
};

int main() {
    GitHubRepository repo;
    repo.crearRepositorio("mi-repo");
    repo.listarRepositorios();
    repo.eliminarRepositorio("mi-repo");
    return 0;
}
