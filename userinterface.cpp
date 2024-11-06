#include <iostream>
#include <string>

class UserInterface {
public:
    UserInterface(SearchEngine& engine) : engine(engine) {}

    void displayMenu() {
        std::string command;
        while (true) {
            std::cout << "Enter a command (index, query, load, exit): ";
            std::cin >> command;

            if (command == "index") {
                std::string dir;
                std::cout << "Enter directory to index: ";
                std::cin >> dir;
                engine.indexDocuments();
            } else if (command == "query") {
                std::string query;
                std::cout << "Enter search query: ";
                std::getline(std::cin, query); // To capture multi-word queries
                engine.search(query);
            } else if (command == "load") {
                engine.loadIndex();
            } else if (command == "exit") {
                break;
            } else {
                std::cout << "Invalid command!" << std::endl;
            }
        }
    }

private:
    SearchEngine& engine;
};
