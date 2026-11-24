#pragma once
#include <vector>
#include <string>

using namespace std;

struct Node{
    int val;
    bool is_end = false;
    vector<Node*> children;
    int cnt_v = 0;

    Node(int v);
    Node();
};

class Trie{
    Node* root;

    //слова в лексиграфичкском порядке
    void lex(Node* cur, string& pref, vector<string>& words);

    //даление всех элементов
    void clear(Node* n);

public:
    Trie();
    ~Trie();

    //добавление слова
    void insert(string& word);

    //проверка содержится ли слово
    bool contains(string& word);

    //есть ли слова начинающиеся на данный префикс
    bool starts_with(string& pref);

    //вектор слов в лексиграфическом порядке
    vector<string> sort_words();
};