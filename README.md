cs5393-002_project4 search engine

Megan Appel and Diego Mejia

Instructions on how to run code are in howtorun.txt file

This C++ search engine is built to efficiently process and search through a collection of documents. It consists of several main components: the documentparser, which reads and extracts important terms and data from the documents; the indexhandler, which stores these terms in a self-balancing dsavltree for fast searching; and the queryprocessor, which takes user queries, searches the index, and ranks the results based on relevance. The searchengine ties everything together, handling the overall process of parsing documents, indexing terms, and processing queries. Finally, the userinterface allows users to enter search terms and view the results in a simple, clear format. This design makes the system efficient, easy to scale, and easy to maintain, as each component has a specific role in the search process.

Resources: Chatgpt.com, Ria Mukherji, Anekah Kelley
