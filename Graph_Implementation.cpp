#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>

class Towns{
    private:
        
    public:
        std::string name;
        std::vector<std::pair<Towns*, int>> neighbors;
        Towns() : name("") {};
        Towns(std::string nme) : name(nme) {};
        Towns(std::string nme, std::vector<std::pair<Towns*, int>> n) : name(nme), neighbors(n) {};
        
        void dfs_preorder(Towns* current, std::set<Towns*>& visited){
            std::cout << current->name << " - ";
            visited.insert(current);
            for(const auto& neighbor : current->neighbors){
                if(visited.find(neighbor.first) == visited.end()){
                    dfs_preorder(neighbor.first, visited);
                }
            }
        }
        
        void dfs(Towns* current) {
            std::set<Towns*> visited;
            std::stack<Towns*> trav;
            trav.push(current);
            std::vector<Towns*> visited_v;
            visited_v.push_back(current);
            
            while (!trav.empty()) {
                Towns* c = trav.top();
                trav.pop();
                for(int i = 0; i < visited_v.size(); i++){
                    std::cout << visited_v[i]->name << " - ";
                }
                if (visited.find(c) == visited.end()) {
                    visited_v.push_back(c);
                    visited.insert(c);
                    for (const auto& neighbor : c->neighbors) {
                        trav.push(neighbor.first);
                    }
                }
                system("cls");
            }
        }
        
        void bfs(Towns* current){
            std::set<Towns*> visited;
            std::queue<Towns*> trav;
            trav.push(current);
            
            while(!trav.empty()){
                Towns* c = trav.front();
                trav.pop();
                
                if(visited.find(c) == visited.end()){
                    std::cout << c->name << " - ";
                    visited.insert(c);
                    
                    for(const auto& neighbor : c->neighbors){
                        trav.push(neighbor.first);
                    }
                }
            }
        }
};

int main() {
    const int SIZE = 23;
    std::string towns_of_ilocos_norte[SIZE] = {
        "Adams", "Bacarra", "Badoc", "Bangui", "Banna", "Batac", "Burgos", 
        "Carasi", "Currimao", "Dingras", "Dumalneg", "Laoag", "Marcos", 
        "Nueva Era", "Pagudpud", "Paoay", "Pasuquin", "Piddig", "Pinili", 
        "San Nicolas", "Sarrat", "Solsona", "Vintar"
    };
    std::vector<std::vector<std::string>> neighbor_pairs = {
        {"Pagudpud", "Laoag"}, //Adams
        {"Vintar", "Pasuquin", "Laoag"}, //Bacarra
        {"Pinili", "Currimao", "Laoag"}, //Badoc
        {"Pagudpud", "Burgos", "Laoag"}, //Bangui
        {"Dingras", "Marcos", "Laoag"}, //Banna
        {"San Nicolas", "Paoay", "Laoag"}, //Batac
        {"Pasuquin", "Bangui", "Laoag"}, //Burgos
        {"Laoag"}, //Carasi
        {"Paoay", "Pinili", "Badoc", "Laoag"}, //Currimao
        {"Banna", "Marcos", "Solsona", "Laoag"}, //Dingras
        {"Pagudpud", "Laoag"}, //Dumalneg
        {"Adams", "Bacarra", "Badoc", "Bangui", "Banna", "Batac", "Burgos", 
        "Carasi", "Currimao", "Dingras", "Dumalneg", "Marcos", 
        "Nueva Era", "Pagudpud", "Paoay", "Pasuquin", "Piddig", "Pinili", 
        "San Nicolas", "Sarrat", "Solsona", "Vintar"}, // Laoag
        {"Banna", "Dingras", "Laoag"}, //Marcos
        {"Pinili", "Laoag"}, //Nueva Era
        {"Bangui", "Adams", "Dumalneg", "Laoag"}, //Pagudpud
        {"Batac", "Currimao", "Laoag"}, //Paoay
        {"Bacarra", "Burgos", "Laoag"}, //Pasuquin
        {"Sarrat", "Solsona", "Laoag"}, //Piddig
        {"Badoc", "Currimao", "Nueva Era", "Laoag"}, //Pinili
        {"Batac", "Laoag"}, //San Nicolas
        {"Piddig", "Laoag"}, //Sarrat
        {"Dingras", "Piddig", "Laoag"}, //Solsona
        {"Bacarra", "Laoag"} //Vintar
    };
    
    std::map<std::string, Towns*> IN;
    for(int i = 0; i < SIZE; i++){
        std::string temp = towns_of_ilocos_norte[i];
        IN[temp] = new Towns(temp);
    }

    for(int i = 0; i < SIZE; i++){
        std::string temp = towns_of_ilocos_norte[i];
        for(const auto& town : neighbor_pairs[i]){
            IN[temp]->neighbors.push_back({IN[town], - 1});
        }
    }

    Towns trav;
    std::string input = " ";
    
    while(input != ""){
        std::cout << "Set a starting point : ";
        std::getline(std::cin, input);
        
        if(std::count(std::begin(towns_of_ilocos_norte), std::end(towns_of_ilocos_norte), input) > 0){
            std::cout << "BFS TRAVEL " << std::endl; 
            trav.bfs(IN[input]);
        }
        
        std::cout << std::endl;
    }
    return 0;
}
