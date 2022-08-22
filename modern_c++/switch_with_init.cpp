#include <iostream>
#include <filesystem>

using namespace std::filesystem;

int main() {
    std::string name = "../shai_simonson/algo";

    switch (path p(name); status(p).type()) {
        case file_type::not_found:
            std::cout << p << " not found\n";
            break;
        case file_type::directory:
            std::cout << p << ":\n";
            for (auto& e : std::filesystem::directory_iterator(p))
                std::cout << "- " << e.path() << '\n';
            break;
        default:
            std::cout << p << " exists\n";
            break;
    }

    return 0;
}