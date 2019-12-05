#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

struct Node{
    char c;
    int prev;
    int status;
    vector<Node*> nexts;
    Node(char project);
};

Node::Node(char project){
    c = project;
    nexts = vector<Node*>();
    prev = 0;
}

void findNext(unordered_map<char, Node*>* projectMap, vector<char>* ans){
    if(projectMap->empty()){
        return;
    }
    for(auto it = projectMap->begin(); it != projectMap->end(); it++){
        if(it->second->prev == 0){
            ans->push_back(it->first);
            Node* node = it->second;
            vector<Node*> nexts = node->nexts;
            for(Node* next: nexts){
                next->prev--;
            }
            projectMap->erase(it);
            findNext(projectMap, ans);
            // ALEX: don't forget to free the heap memory you allocated!
            delete node;
            break;
        }
    }
}

vector<char> decideOrder(const vector<char>& projects, const vector<pair<char, char>> dependencies){
    unordered_map<char, Node*> projectMap;
    for(char project: projects){
        Node* node = new Node(project);
        projectMap.insert({project, node});
    }

    for(auto pair: dependencies){
        Node* current = projectMap[pair.second];
        Node* next = projectMap[pair.first];
        current->nexts.push_back(next);
        next->prev++;
    }

    vector<char> ans;
    findNext(&projectMap, &ans);
    if(ans.size() != projects.size()){
        cout << "Error" << endl;
        return vector<char>();
    }
    return ans;
}

#define COMPLETED 2
#define PARTIAL 1
#define BLANK 0

Node* findNext2(Node* node){
    if(node){}
    findNext2(node->nexts[0]);
}

vector<char> decideOrder2(const vector<char>& projects, const vector<pair<char, char>> dependencies){
    unordered_map<char, Node*> projectMap;
    Node* node;
    for(char project: projects){
        node = new Node(project);
        projectMap.insert({project, node});
    }

    for(auto pair: dependencies){
        Node* current = projectMap[pair.second];
        Node* next = projectMap[pair.first];
        current->nexts.push_back(next);
    }

    findNext2(node);
}


int main(void){
    vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<pair<char, char>> dependencies = {
        make_pair('d', 'a'),
        make_pair('b', 'f'),
        make_pair('d', 'b'),
        make_pair('a', 'f'),
        make_pair('c', 'd')};
    vector<char> ans = decideOrder(projects, dependencies);
    for(char c: ans){
        cout << c << " ";
    }
    cout << endl;
    return 0;
}