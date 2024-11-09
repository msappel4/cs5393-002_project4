#include "QueryProcessor.h"



#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

class QueryProcessor {
public:
    QueryProcessor(IndexHandler& termIndex, IndexHandler& orgIndex, IndexHandler& personIndex)
        : termIndex(termIndex), orgIndex(orgIndex), personIndex(personIndex) {}

    void processQuery(const std::string& query) {
        std::vector<std::string> terms;
        std::vector<std::string> orgTerms;
        std::vector<std::string> personTerms;
        
        // Tokenize the query
        std::istringstream stream(query);
        std::string token;
        while (stream >> token) {
            if (token.find("ORG:") == 0) {
                orgTerms.push_back(token.substr(4));  // Remove "ORG:" prefix
            } else if (token.find("PERSON:") == 0) {
                personTerms.push_back(token.substr(7));  // Remove "PERSON:" prefix
            } else {
                terms.push_back(token);
            }
        }

        // Search for terms in the appropriate indices
        std::vector<std::string> resultDocs = searchTerms(terms);

        // Filter by ORG and PERSON (if specified)
        resultDocs = filterByEntities(resultDocs, orgTerms, orgIndex);
        resultDocs = filterByEntities(resultDocs, personTerms, personIndex);

        // Output the results
        displayResults(resultDocs);
    }

private:
    IndexHandler& termIndex;
    IndexHandler& orgIndex;
    IndexHandler& personIndex;

    std::vector<std::string> searchTerms(const std::vector<std::string>& terms) {
        std::vector<std::string> docs;
        for (const std::string& term : terms) {
            std::vector<std::string> termDocs = termIndex.searchTerm(term);
            if (docs.empty()) {
                docs = termDocs;
            } else {
                std::vector<std::string> intersectedDocs;
                std::set_intersection(docs.begin(), docs.end(), termDocs.begin(), termDocs.end(), std::back_inserter(intersectedDocs));
                docs = intersectedDocs;
            }
        }
        return docs;
    }

    std::vector<std::string> filterByEntities(const std::vector<std::string>& docs, const std::vector<std::string>& entities, IndexHandler& entityIndex) {
        std::vector<std::string> filteredDocs = docs;
        for (const std::string& entity : entities) {
            std::vector<std::string> entityDocs = entityIndex.searchTerm(entity);
            std::vector<std::string> intersectedDocs;
            std::set_intersection(filteredDocs.begin(), filteredDocs.end(), entityDocs.begin(), entityDocs.end(), std::back_inserter(intersectedDocs));
            filteredDocs = intersectedDocs;
        }
        return filteredDocs;
    }

    void displayResults(const std::vector<std::string>& docs) {
        std::cout << "Found " << docs.size() << " results:" << std::endl;
        for (const std::string& docId : docs) {
            std::cout << docId << std::endl;
        }
    }
};
