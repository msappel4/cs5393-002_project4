#include <iostream>
#include "SearchEngine.h" //include the search engine
#include "UserInterface.h"
using namespace std;

int main()




#include <iostream>
#include <string>
#include <vector>
#include "DocumentParser.h"  // Include your DocumentParser class
#include "IndexHandler.h"    // Include your IndexHandler class
#include "QueryProcessor.h"  // Include your QueryProcessor class
#include "SearchEngine.h"    // Include your SearchEngine class
#include "UserInterface.h"   // Include your UserInterface class

// Main entry point
int main(int argc, char* argv[]) {
    // First, check if we have a command-line argument
    if (argc < 2) {
        std::cerr << "Usage: supersearch <command> [arguments]" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    // Initialize the SearchEngine object
    std::string dataDirectory = "data";  // Example directory name where JSON files are stored
    SearchEngine engine(dataDirectory);
    UserInterface ui(engine);

    if (command == "index") {
        // Index all documents in the directory
        if (argc < 3) {
            std::cerr << "Please provide the directory to index." << std::endl;
            return 1;
        }

        std::string directory = argv[2];
        engine.indexDocuments();
    } 
    else if (command == "query") {
        // Query the search engine
        if (argc < 3) {
            std::cerr << "Please provide a query string." << std::endl;
            return 1;
        }

        std::string query = argv[2];
        engine.search(query);
    } 
    else if (command == "load") {
        // Load existing index from files
        engine.loadIndex();
    } 
    else if (command == "ui") {
        // Start the User Interface for interacting with the engine
        ui.displayMenu();
    } 
    else {
        std::cerr << "Unknown command: " << command << std::endl;
        return 1;
    }

    return 0;
}
