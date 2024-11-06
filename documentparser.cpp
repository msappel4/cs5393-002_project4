#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <json/json.h>
#include <algorithm>
#include "porter_stemmer.h"  // You should have a Porter stemmer implementation

class DocumentParser {
public:
    DocumentParser() {
        // Load stopwords
        loadStopwords("stopwords.txt");
    }

    struct Document {
        std::string title;
        std::string author;
        std::string date;
        std::string fullText;
        std::string filename;
    };

    Document parseFile(const std::string& filepath) {
        // Parse the JSON file
        Json::Value root;
        std::ifstream file(filepath, std::ifstream::binary);
        file >> root;

        Document doc;
        doc.filename = filepath;
        doc.title = root["title"].asString();
        doc.author = root["author"].asString();
        doc.date = root["date"].asString();
        doc.fullText = root["content"].asString();

        // Process the text: remove stopwords and stem
        doc.fullText = removeStopwords(doc.fullText);
        doc.fullText = stemText(doc.fullText);

        return doc;
    }

private:
    std::set<std::string> stopwords;

    void loadStopwords(const std::string& stopwordFile) {
        std::ifstream file(stopwordFile);
        std::string word;
        while (file >> word) {
            stopwords.insert(word);
        }
    }

    std::string removeStopwords(const std::string& text) {
        std::istringstream stream(text);
        std::ostringstream result;
        std::string word;
        
        while (stream >> word) {
            if (stopwords.find(word) == stopwords.end()) {
                result << word << " ";
            }
        }
        return result.str();
    }

    std::string stemText(const std::string& text) {
        std::istringstream stream(text);
        std::ostringstream result;
        std::string word;
        
        while (stream >> word) {
            PorterStemmer::stem(word);  // Call Porter stemmer
            result << word << " ";
        }
        return result.str();
    }
};
