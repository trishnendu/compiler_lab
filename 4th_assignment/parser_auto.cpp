//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#define EPS "eps"

using namespace std;


class Grammer{
    private:
        set <string> v;
        set <string> sigma;
        string S;
        vector <pair <string, vector <string>>> rules;
        map <pair <string, string>, vector <string>> parsing_table;
        
        map <string, set<string>> FIRST;
        map <string, set<string>> FOLLOW;
    public:    
        Grammer(){
            sigma.insert("$");
        }

        Grammer(set<string> V, set<string> SIGMA, string START){
            v = V;
            sigma = SIGMA;
            S = START;
        }

        int insert_rule(string lhs, vector<string> rhss){
            rules.push_back(make_pair(lhs, rhss));
            return 1;
        }

    /*    int insert_ptable(string row, string col, vector<string> rhss){
            parsing_table.insert(make_pair(make_pair(row, col), rhss));
            return 1;
        }*/

        set<string> create_firstset(string symb){
            if(FIRST.find(symb) == FIRST.end()){
                FIRST.insert(make_pair(symb, set<string>()));
                for(vector <pair <string, vector <string>>>::iterator it = rules.begin(); it != rules.end(); it++){
                    if(it->first == symb){
                        if((it->second.front() == EPS) || (sigma.find(it->second.front()) != sigma.end())){
                            //cout << "inserting " << it->second.front() << " @ " << symb << endl; 
                            FIRST[symb].insert(it->second.front());
                        } else{
                            set<string> tmp = create_firstset(it->second.front());
                            //cout << "inserting FIRST of " << it->second.front() << " @ " << symb << endl;
                            FIRST[symb].insert(tmp.begin(), tmp.end());    
                        }
                    }
                }
            }
            return FIRST[symb];
        }

        bool create_firstset(){
            for(set<string>::iterator it = sigma.begin(); it != sigma.end(); it++)
                FIRST.insert(make_pair(*it, set<string>{*it}));
            for(set<string>::iterator it = v.begin(); it!= v.end(); it++)
                create_firstset(*it);
            return true;
        }

        bool create_followset(){
            map <string, set<string>> EQU;  
            FOLLOW.insert(make_pair(S, set<string>{"$"}));
            for(set<string>::iterator it = v.begin(); it != v.end(); it++){
                if(FOLLOW.find(*it) == FOLLOW.end())
                    FOLLOW.insert(make_pair(*it, set<string>()));
                EQU.insert(make_pair(*it, set<string>()));
                for(vector <pair <string, vector <string>>>::iterator iit = rules.begin(); iit != rules.end(); iit++){
                    if (*it != iit->first){
                    //cout << iit->second.front() << endl;
                        vector<string>::iterator tmp = find(iit->second.begin(), iit->second.end(), *it);
                        if(tmp < iit->second.end() - 1){
                            FOLLOW[*it].insert(FIRST[*(tmp+1)].begin(),FIRST[*(tmp+1)].end());
                            if(FIRST[*(tmp+1)].find(EPS) != FIRST[*(tmp+1)].end())
                                EQU[*it].insert(iit->first);
                        } else if(tmp == iit->second.end() - 1)
                            EQU[*it].insert(iit->first);
                    }
                    FOLLOW[*it].erase(EPS);
                }
            }
            for(set<string>::iterator it = v.begin(); it != v.end(); it++){
                for(set<string>::iterator iit = v.begin(); iit != v.end(); iit++){
                    for(set<string>::iterator ele = EQU[*iit].begin(); ele != EQU[*iit].end(); ele++){
                        //cout << "updating " << *iit << " with " << *ele << endl;
                        FOLLOW[*iit].insert(FOLLOW[*ele].begin(), FOLLOW[*ele].end());
                    }
                }
            }
            return true;
        }

        bool create_ptable(){
            cout << "RULES" << endl;
            for(vector <pair <string, vector <string>>>::iterator iit = rules.begin(); iit != rules.end(); iit++){
                cout << iit->first << " -> ";
                for(vector<string>::iterator str = iit->second.begin(); str != iit->second.end(); str++){
                    cout << *str;
                }
                cout << endl;
            }
            create_firstset();
            cout << "\nFIRST SET" << endl;
            for(map <string, set<string>>::iterator it = FIRST.begin(); it != FIRST.end(); it++){
                cout << it->first << " -> ";
                for(set<string>::iterator iit = it->second.begin(); iit != it->second.end(); iit++){
                    cout << *iit << ", ";
                }
                cout << endl;
            }  
            create_followset();
            cout << "\nFOLLOW SET" << endl;
            for(map <string, set<string>>::iterator it = FOLLOW.begin(); it != FOLLOW.end(); it++){
                cout << it->first << " -> ";
                for(set<string>::iterator iit = it->second.begin(); iit != it->second.end(); iit++){
                    cout << *iit << ", ";
                }
                cout << endl;
            }  
            for(vector <pair <string, vector <string>>>::iterator iit = rules.begin(); iit != rules.end(); iit++){
                for(vector<string>::iterator rhs_symb =  iit->second.begin(); rhs_symb != iit->second.end(); iit++){
                    bool eps_exists = false;
                    if(*rhs_symb == EPS){
                        for(set<string>::iterator b = FOLLOW[iit->first].begin(); b != FOLLOW[iit->first].end(); b++){
                            parsing_table.insert(make_pair(make_pair(iit->first, *b), iit->second));    
                        }
                        break;
                    } 
                    for(set<string>::iterator a = FIRST[*rhs_symb].begin(); a != FIRST[*rhs_symb].end(); a++){
                        if(*a == EPS){
                            eps_exists = true;
                            cout << "debugging ... found EPS @" << iit->first << endl; 
                            for(set<string>::iterator b = FOLLOW[iit->first].begin(); b != FOLLOW[iit->first].end(); b++){
                                parsing_table.insert(make_pair(make_pair(iit->first, *b), iit->second));    
                            }
                        }    
                        else
                            parsing_table.insert(make_pair(make_pair(iit->first, *a), iit->second));
                    }
                    if(!eps_exists)
                        break;
                }
            }
            cout << "\nPARSING TABLE" << endl;
            for(set <string>::iterator row = v.begin(); row != v.end(); row++){
                for(set<string>::iterator col = sigma.begin(); col != sigma.end(); col++){
                    if(parsing_table.find(make_pair(*row, *col)) != parsing_table.end()){
                        cout << *row << " AND " << *col << "| " << *row << " =>";
                        vector<string> derivation = parsing_table[make_pair(*row, *col)];
                        for(int i = 0; i < derivation.size(); i++)
                            cout << derivation[i];
                        cout << endl;
                    }
                }
            }
            return true;
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
                    //cout << "stack-head: "  << head << ", "<< "current symb: " << *buffer_index << endl;
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
    G.insert_rule("F", vector<string>{"id"});
    if(G.create_ptable()){
        cout << ":)" << endl;
    }
    if(G.parse_string(vector<string>{"id","+","id","*","id"})){
        cout << "Parsing successful! Correct syntax :)" << endl;
    } else{
        cout << "Parsing faild! Incorrect syntax :(" << endl;
    }
    return 0;
    
}

/*
int main(){
    Grammer G(set<string>{"S","A","B"}, set<string>{"a","b","c","$"}, "S");    
    G.insert_rule("S", vector<string>{"a","A","a"});
    G.insert_rule("S", vector<string>{"B","A","a"});
    G.insert_rule("S", vector<string>{EPS});
    G.insert_rule("A", vector<string>{"c","A"});
    G.insert_rule("A", vector<string>{"b","A"});
    G.insert_rule("A", vector<string>{EPS});
    G.insert_rule("B", vector<string>{"b"});
    if(G.create_ptable()){
        cout << ":)" << endl;
    }
    if(G.parse_string(vector<string>{"b","c","b","a"})){
        cout << "Parsing successful! Correct syntax :)" << endl;
    } else{
        cout << "Parsing faild! Incorrect syntax :(" << endl;
    }
    return 0;
}*/