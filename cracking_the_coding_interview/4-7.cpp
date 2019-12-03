#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

struct Node{
    char c;
    vector<Node*> prevs;
    vector<Node*> nexts;
};

void findNext(unordered_map<char, Node*>* projectMap, vector<char>* ans){
    if(projectMap->empty()){
        return;
    }
    for(auto it = projectMap->begin(); it != projectMap->end(); it++){
        if(it->second->prevs.empty()){
            ans->push_back(it->first);
            Node* node = it->second;
            vector<Node*> nexts = node->nexts;
            for(Node* next: nexts){
                auto itr = next->prevs.begin();
                while(itr != next->prevs.end()){
                    if(*itr == node){
                        next->prevs.erase(itr);
                        break;
                    }
                    itr++;
                }
            }
            projectMap->erase(it);
            findNext(projectMap, ans);
            break;
        }
    }
}

vector<char> decideOrder(const vector<char>& projects, const vector<pair<char, char>> dependencies){
    unordered_map<char, Node*> projectMap;
    for(char project: projects){
        Node* node = new Node;
        node->c = project;
        node->prevs = vector<Node*>();
        node->nexts = vector<Node*>();
        projectMap.insert({project, node});
    }

    for(auto pair: dependencies){
        Node* current = projectMap[pair.second];
        Node* next = projectMap[pair.first];
        current->nexts.push_back(next);
        next->prevs.push_back(current);
    }
    vector<char> ans;
    findNext(&projectMap, &ans);
    return ans;
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