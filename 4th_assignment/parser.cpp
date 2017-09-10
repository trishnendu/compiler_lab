//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#define EPS "eps"

using namespace std;


class Grammer{
    private:
        vector <string> v;
        vector <string> sigma;
        vector <pair <string, vector <string>>> rules;
        map <pair <string, string>, vector <string>> parsing_table;

    private:
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
        }
        
    
    public:    
        Grammer(){
            sigma.push_back("$");
        }

        Grammer(vector<string> V, vector<string> SIGMA){
            v = V;
            sigma = SIGMA;
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
            vector<string> pstack = {"$", v[0]};
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