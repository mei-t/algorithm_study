#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 27分45秒
unordered_map<string, int> trueNameCount(const vector<pair<string, string>>& synonyms, const unordered_map<string, int>& names){
    unordered_map<string, string> nameGroup;
    unordered_map<string, vector<string>> dict;
    for(const pair<string, string>& synonym: synonyms){
        auto itFirst = nameGroup.find(synonym.first);
        auto itSecond = nameGroup.find(synonym.second);
        if(itFirst == nameGroup.end() && itSecond == nameGroup.end()){
            nameGroup.insert({synonym.first, synonym.first});
            nameGroup.insert({synonym.second, synonym.first});
            dict.insert({synonym.first, {synonym.first, synonym.second}});
        }else if(itFirst != nameGroup.end() && itSecond != nameGroup.end() && itFirst->second != itSecond->second){
            vector<string> change = dict[itFirst->second].size() < dict[itSecond->second].size() ? dict[itFirst->second] : dict[itSecond->second];
            string newName = dict[itFirst->second].size() < dict[itSecond->second].size() ? itSecond->second : itFirst->second;
            for(string name : change){
                nameGroup[name] = newName;
            }
            // vectorではなく連結リストならmergeにO(1)しかかからない気がする
            dict[newName].insert(dict[newName].end(), change.begin(), change.end());
        }else if(itFirst != nameGroup.end() && itSecond == nameGroup.end()){
            nameGroup.insert({synonym.second, itFirst->second});
            dict[itFirst->second].push_back(synonym.second);
        }else if(itFirst == nameGroup.end() && itSecond != nameGroup.end()){
            nameGroup.insert({synonym.first, itSecond->second});
            dict[itSecond->second].push_back(synonym.first);
        }
    }

    unordered_map<string, int> nameMap;
    for(auto it = names.begin(); it != names.end(); it++){
        if(nameMap.find(nameGroup[it->first]) == nameMap.end()){
            nameMap.insert({nameGroup[it->first], 0});
        }
        nameMap[nameGroup[it->first]] += it->second;
    }
    return nameMap;
}

struct Graph{
    string name;
    int count;
    bool isVisited;
    Graph* next;
    vector<Graph*> neighbers;
};

Graph* createNewGraph(const vector<pair<string, int>>& names, size_t i, unordered_map<string, Graph*>* nameMap){
    if(i == names.size()){
        return nullptr;
    }
    Graph* graph = new Graph{names[i].first, names[i].second, false, nullptr, vector<Graph*>()};
    graph->next = createNewGraph(names, i+1, nameMap);
    nameMap->insert({names[i].first, graph});
    return graph;
}

unordered_map<string, int> trueNameCount2(const vector<pair<string, string>>& synonyms, const vector<pair<string, int>>& names){
    unordered_map<string, Graph*> nameMap;
    Graph* root = createNewGraph(names, 0, &nameMap);

    for(const auto& synonym: synonyms){
        if(!nameMap[synonym.first]){
            nameMap[synonym.first] = new Graph{synonym.first, 0, false, nullptr, vector<Graph*>()};
        }
        if(!nameMap[synonym.second]){
            nameMap[synonym.second] = new Graph{synonym.first, 0, false, nullptr, vector<Graph*>()};
        }
        nameMap[synonym.first]->neighbers.push_back(nameMap[synonym.second]);
        nameMap[synonym.second]->neighbers.push_back(nameMap[synonym.first]);
    }

    unordered_map<string, int> ans;
    Graph* current = root->next;
    Graph* prev;
    while(current){
        if(current->isVisited){
            current = current->next;
            continue;
        }
        current->isVisited = true;
        ans[current->name] = current->count;
        for(Graph* neighber : current->neighbers){
            if(neighber->isVisited){
                continue;
            }
            neighber->isVisited = true;
            ans[current->name] += neighber->count;
            if(!neighber->next){
                delete(neighber);
            }
        }
        prev = current;
        current = current->next;
        delete(prev);
    }
    return ans;
}


int main(void){
    unordered_map<string, int> names = {
        {"John", 15},
        {"Jon", 12},
        {"Chris", 13},
        {"Kris", 4},
        {"Christopher", 19}
    };
    vector<pair<string, string>> synonyms = {
        make_pair("Jon", "John"),
        make_pair("John", "Johnny"),
        make_pair("Chris", "Kris"),
        make_pair("Chris", "Christopher")
    };
    unordered_map<string, int> ans = trueNameCount(synonyms, names);
    for(auto it : ans){
        cout << it.first << ", " << it.second << endl;
    }

    vector<pair<string, int>> names2 = {
        {"John", 15},
        {"Jon", 12},
        {"Chris", 13},
        {"Kris", 4},
        {"Christopher", 19}
    };
    ans = trueNameCount2(synonyms, names2);
    for(auto it : ans){
        cout << it.first << ", " << it.second << endl;
    }
    return 0;
}