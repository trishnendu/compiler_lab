//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define EPS "eps"

using namespace std;


class Grammer{
    private:
        set <string> v;
        set <string> sigma;
        string S;
        vector <pair <string, vector <string>>> rules;
        map <pair <string, string>, vector <string>> parsing_table;

    /*private:
        int find_dep(string s){
            if (s==EPS){
                return 0;
            }
            
            for(int i = 0; i < v.size(); i++){
                if(s==v[i])
                    return i+1;
            }
            for(int i = 0; i < sigma.size(); i++){
                if(s==sigma[i])
                    return v.size()+i+1;
            }
            cout << "symbol " << s <<" not found! :| EXITING..." << endl;
            exit(0);
        }*/
        
    
    public:    
        Grammer(){
            sigma.insert("$");
        }

        Grammer(set<string> V, set<string> SIGMA, string start_symb){
            v = V;
            sigma = SIGMA;
            S = start_symb;
        }

        int insert_rule(string lhs, vector<string> rhss){
            rules.push_back(make_pair(lhs, rhss));
            return 1;
        }

        int insert_ptable(string row, string col, vector<string> rhss){
            parsing_table.insert(make_pair(make_pair(row, col), rhss));
            return 1;
        }
    
        bool parse_string(vector<string> input_string){
            vector<string> pstack = {"$", S};
            input_string.push_back("$");
            vector<string>::iterator buffer_index = input_string.begin();
            while(!pstack.empty()){
                if(buffer_index == input_string.end()){
                    return false;
                } else{
                    string head = *(pstack.end()-1);
                    pstack.pop_back();
                    cout << "stack-head: "  << head << ", "<< "current symb: " << *buffer_index << endl;
                    if (*buffer_index == head){
                        buffer_index++;
                    } else if(parsing_table.find(make_pair(head,*buffer_index)) != parsing_table.end()){
                        vector<string> derivation = parsing_table[make_pair(head, *buffer_index)];
                        for(int i = derivation.size()-1; i >= 0; i--){
                            if(derivation[i] != EPS)
                            pstack.push_back(derivation[i]);
                        }
                    } else{
                        return false;  
                    }
                }
            }
            return true;
        }
};

int main(){
    Grammer G(set<string>{"E","E'","T","T'","F"}, set<string>{"id","+","*","(","$",")"}, "E");    
    G.insert_rule("E", vector<string>{"T","E'"});
    G.insert_rule("E'", vector<string>{"+","T","E'"});
    G.insert_rule("E'", vector<string>{EPS});
    G.insert_rule("T", vector<string>{"F","T'"});
    G.insert_rule("T'", vector<string>{"*","F","T'"});
    G.insert_rule("T'", vector<string>{EPS});
    G.insert_rule("F", vector<string>{"(","E",")"});
    G.insert_rule("F", vector<string>{EPS});
    G.insert_ptable("E", "id", vector<string>{"T","E'"});
    G.insert_ptable("T", "id", vector<string>{"F","T'"});
    G.insert_ptable("F", "id", vector<string>{"id"});
    G.insert_ptable("E'", "+", vector<string>{"+","T","E'"});
    G.insert_ptable("T'", "+", vector<string>{EPS});
    G.insert_ptable("T'", "*", vector<string>{"*","F","T'"});
    G.insert_ptable("E", "(", vector<string>{"T","E'"});
    G.insert_ptable("T", "(", vector<string>{"F","T'"});
    G.insert_ptable("F", "(", vector<string>{"(","E",")"});
    G.insert_ptable("E'", ")", vector<string>{EPS});
    G.insert_ptable("T'", ")", vector<string>{EPS});
    G.insert_ptable("E'", "$", vector<string>{EPS});
    G.insert_ptable("T'", "$", vector<string>{EPS});
    if(G.parse_string(vector<string>{"id","+","id","*","id"})){
        cout << "Parsing successful! Correct syntax :)" << endl;
    } else{
        cout << "Parsing faild! Incorrect syntax :(" << endl;
    }
    return 0;
    
}
/*
int main1(){
    Grammer G(vector<string>{"S","A","B"}, vector<string>{"a","b","c","$"});    
    G.insert_rule("S", vector<string>{"a","A","a"});
    G.insert_rule("S", vector<string>{"B","A","a"});
    G.insert_rule("S", vector<string>{EPS});
    G.insert_rule("A", vector<string>{"c","A"});
    G.insert_rule("A", vector<string>{"b","A"});
    G.insert_rule("A", vector<string>{EPS});
    G.insert_rule("B", vector<string>{"b"});
    G.insert_ptable("S", "a", vector<string>{"a","A","a"}); 
    G.insert_ptable("A", "a", vector<string>{EPS}); 
    G.insert_ptable("S", "b", vector<string>{"B","A","a"}); 
    G.insert_ptable("A", "b", vector<string>{"b","A"}); 
    G.insert_ptable("B", "b", vector<string>{"b"}); 
    G.insert_ptable("A", "c", vector<string>{"c","A"}); 
    G.insert_ptable("S", "$", vector<string>{EPS}); 
    if(G.parse_string(vector<string>{"b","c","b","a"})){
        cout << "Parsing successful! Correct syntax :)" << endl;
    } else{
        cout << "Parsing faild! Incorrect syntax :(" << endl;
    }
    return 0;
}
*/