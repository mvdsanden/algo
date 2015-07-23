//
//  TopologicalSort.h
//  Algo
//
//  Created by Marten van de Sanden on 7/23/15.
//  Copyright (c) 2015 Marten van de Sanden. All rights reserved.
//

#ifndef __Algo__TopologicalSort__
#define __Algo__TopologicalSort__

#include <list>
#include <vector>
#include <string>

#include <iostream>

namespace me {
    
    class TopologicalSort {
        
        struct Vertex {
            std::string value;
            std::list<Vertex*> v;
            
            enum { WHITE, GRAY, BLACK } color;
            
            Vertex *parent;
            
            size_t d, f;
            
            Vertex(std::string const &v)
            : value(v)
            {}
        };
        
        std::vector<Vertex*> adj;
        
        size_t d_time;
        
        std::list<Vertex*> d_result;
        
    public:
        
        TopologicalSort()
        {
            Vertex *v0 = new Vertex("undershorts");
            Vertex *v1 = new Vertex("socks");
            Vertex *v2 = new Vertex("watch");
            Vertex *v3 = new Vertex("pants");
            Vertex *v4 = new Vertex("shoes");
            Vertex *v5 = new Vertex("shirt");
            Vertex *v6 = new Vertex("belt");
            Vertex *v7 = new Vertex("tie");
            Vertex *v8 = new Vertex("jacket");
            
            v0->v.push_back(v4);
            v0->v.push_back(v3);
            
            v1->v.push_back(v4);
            
            v3->v.push_back(v4);
            v3->v.push_back(v6);
            
            v5->v.push_back(v6);
            v5->v.push_back(v7);
            
            v6->v.push_back(v8);
            
            v7->v.push_back(v8);
            
            adj.push_back(v0);
            adj.push_back(v1);
            adj.push_back(v2);
            adj.push_back(v3);
            adj.push_back(v4);
            adj.push_back(v5);
            adj.push_back(v6);
            adj.push_back(v7);
            adj.push_back(v8);
        }
        
        ~TopologicalSort()
        {
            
        }
        
        void dfs()
        {
            std::cout << "Starting DFS...\n";
            
            d_result.clear();
            
            for (auto i = adj.begin(); i != adj.end(); ++i) {
                (*i)->color = Vertex::WHITE;
                (*i)->parent = NULL;
            }
            
            d_time = 0;
            
            for (auto i = adj.begin(); i != adj.end(); ++i) {
                if ((*i)->color == Vertex::WHITE) {
                    dfsVisit(*i);
                }
            }
            
            printResult();
            
            std::cout << "Fished DFS...\n";
        }
        
    private:
        
        void dfsVisit(Vertex *u) {
            std::cout << "Visited: " << u->value << ".\n";
            
            ++d_time;
            
            u->d = d_time;
            u->color = Vertex::GRAY;
            
            for (auto i = u->v.begin(); i != u->v.end(); ++i) {
                if ((*i)->color == Vertex::WHITE) {
                    (*i)->parent = u;
                    dfsVisit(*i);
                }
            }
            
            u->color = Vertex::BLACK;
            ++d_time;
            u->f = d_time;
            
            d_result.push_front(u);
        }
        
        void printResult()
        {
            std::cout << "Topological sort:\n";
            
            for (auto i = d_result.begin(); i != d_result.end(); ++i) {
                std::cout << (*i)->value << ".\n";
            }
        }
        
    };
    
}

#endif /* defined(__Algo__TopologicalSort__) */
