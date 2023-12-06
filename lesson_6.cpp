// -*- coding: utf-8 -*-
//Двоичное дерево поиска

//#include <iostream>
//#include <set>
//
//int main() {
//    std::set<int> bst;
//
//    // Заполнение дерева
//    bst.insert(5);
//    bst.insert(3);
//    bst.insert(8);
//
//    // Поиск значения
//    if (bst.find(3) != bst.end()) {
//        std::cout << "Значение 3 найдено" << std::endl;
//    } else {
//        std::cout << "Значение 3 не найдено" << std::endl;
//    }
//
//    return 0;
//}

//Неар
//
//#include <iostream>
//#include <queue>
//
//int main() {
//    std::priority_queue<int> heap;
//
//    // Заполнение кучи
//    heap.push(5);
//    heap.push(3);
//    heap.push(8);
//
//    // Поиск максимального значения
//    int max_value = heap.top();
//    std::cout << "Максимальное значение: " << max_value << std::endl;
//
//    return 0;
//}

//Связные списки

//#include <iostream>
//#include <list>
//
//int main() {
//    std::list<int> linkedList;
//
//    // Заполнение связного списка
//    linkedList.push_back(5);
//    linkedList.push_back(3);
//    linkedList.push_back(8);
//
//    // Поиск значения
//    for (const int& value : linkedList) {
//        if (value == 3) {
//            std::cout << "Значение 3 найдено" << std::endl;
//            break;
//        }
//    }
//
//    return 0;
//}

//Префиксное дерево

//#include <iostream>
//#include <unordered_map>
//
//class TrieNode {
//public:
//    std::unordered_map<char, TrieNode*> children;
//    bool isEndOfWord;
//
//    TrieNode() : isEndOfWord(false) {}
//};
//
//class Trie {
//public:
//    Trie() {
//        root = new TrieNode();
//    }
//
//    void insert(const std::string& word) {
//        TrieNode* current = root;
//        for (char c : word) {
//            if (current->children.find(c) == current->children.end()) {
//                current->children[c] = new TrieNode();
//            }
//            current = current->children[c];
//        }
//        current->isEndOfWord = true;
//    }
//
//    bool search(const std::string& word) {
//        TrieNode* current = root;
//        for (char c : word) {
//            if (current->children.find(c) == current->children.end()) {
//                return false;
//            }
//            current = current->children[c];
//        }
//        return current->isEndOfWord;
//    }
//
//private:
//    TrieNode* root;
//};
//
//int main() {
//    Trie trie;
//
//    // Заполнение префиксного дерева
//    trie.insert("apple");
//    trie.insert("app");
//    trie.insert("banana");
//
//    // Поиск значения
//    if (trie.search("app")) {
//        std::cout << "Слово 'app' найдено" << std::endl;
//    } else {
//        std::cout << "Слово 'app' не найдено" << std::endl;
//    }
//
//    return 0;
//}
