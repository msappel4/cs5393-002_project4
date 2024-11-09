#include "SearchEngine.h"
#include <iostream>
#include <cstdio>
#include <chrono>



#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class SearchEngine {
public:
    SearchEngine(const std::string& dataDir) 
        : docParser(), termIndex(), orgIndex(), personIndex() {
        this->dataDir = dataDir;
    }

    void indexDocuments() {
        // Process all files in the directory
        for (const std::string& filename : getFilesInDirectory(dataDir)) {
            DocumentParser::Document doc = docParser.parseFile(filename);
            indexDocument(doc);
        }

        // Save the indices
        termIndex.saveIndex("term_index.txt");
        orgIndex.saveIndex("org_index.txt");
        personIndex.saveIndex("person_index.txt");

        std::cout << "Indexing complete!" << std::endl;
    }

    void loadIndex() {
        termIndex.loadIndex("term_index.txt");
        orgIndex.loadIndex("org_index.txt");
        personIndex.loadIndex("person_index.txt");

        std::cout << "Index loaded!" << std::endl;
    }

    void search(const std::string& query) {
        queryProcessor.processQuery(query);
    }

private:
    DocumentParser docParser;
    IndexHandler termIndex;
    IndexHandler orgIndex;
    IndexHandler personIndex;
    QueryProcessor queryProcessor;
    std::string dataDir;

    std::vector<std::string> getFilesInDirectory(const std::string& dir) {
        // This is just a placeholder. Implement directory listing based on your platform.
        return { "sample_file_1.json", "sample_file_2.json" }; // Example files
    }

    void indexDocument(const DocumentParser::Document& doc) {
        // Index terms
        std::istringstream stream(doc.fullText);
        std::string word;
        while (stream >> word) {
            termIndex.addTerm(word, doc.filename);
        }

        // Index organizations and persons (Assume we extract these entities)
        orgIndex.addTerm("Facebook", doc.filename);
        personIndex.addTerm("Mark Zuckerberg", doc.filename);
    }
};
