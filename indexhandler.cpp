#include <map>
#include <vector>
#include <string>
#include <iostream>

class IndexHandler {
public:
    void addTerm(const std::string& term, const std::string& docId) {
        index[term].push_back(docId);
    }

    std::vector<std::string> searchTerm(const std::string& term) {
        if (index.find(term) != index.end()) {
            return index[term];
        }
        return {};
    }

    void saveIndex(const std::string& filename) {
        std::ofstream file(filename);
        for (auto& entry : index) {
            file << entry.first << ": ";
            for (const std::string& docId : entry.second) {
                file << docId << " ";
            }
            file << std::endl;
        }
    }

    void loadIndex(const std::string& filename) {
        std::ifstream file(filename);
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string term = line.substr(0, pos);
                std::string docs = line.substr(pos + 2);  // Skip ": "
                std::istringstream docStream(docs);
                std::string docId;
                while (docStream >> docId) {
                    index[term].push_back(docId);
                }
            }
        }
    }

private:
    std::map<std::string, std::vector<std::string>> index;  // term -> doc IDs
};
