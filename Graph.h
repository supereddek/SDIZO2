//
// Created by super on 16.06.2022.
//

#ifndef SDIZO2_GRAPH_H
#define SDIZO2_GRAPH_H

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <limits>

class Graph
{

    struct Edge {
        size_t src;
        size_t dest;
        size_t weight;


        Edge(size_t src)
        // To compare edges, only compare their weights,
        // and not the source/destination vertices
        inline bool operator< (const Edge& e) const
        {
            return this->weight < e.weight;
        }

        inline bool operator> (const Edge& e) const
        {
            return this->weight > e.weight;
        }
    };




public:
    // Initialize the graph with N vertices
    Graph(size_t N) : V(N)
    {}

    // Return number of vertices in the graph
    auto vertices() const
    {
        return V;
    }

    // Return all edges in the graph
    auto& edges() const
    {
        return edge_list;
    }

    void add_edge(Edge&& e)
    {
        // Check if the source and destination vertices are within range
        if (e.src >= 0 && e.src <= V &&
            e.dest >= 0 && e.dest <= V)
            edge_list.emplace_back(e);

        else
            std::cerr << "Vertex out of bounds" << std::endl;
    }

    // Returns all outgoing edges from vertex v
    auto outgoing_edges(size_t v) const
    {
        std::vector<Edge> edges_from_v;
        for (auto& e : edge_list)
        {
            if (e.src == v)
                edges_from_v.emplace_back(e);
        }
        return edges_from_v;
    }

    // Overloads the << operator so a graph be written directly to a stream
    // Can be used as std::cout << obj << std::endl;
    //friend std::ostream& operator<< <>(std::ostream& os, const Graph& G);

//    std::ostream& operator << (std::ostream& os, const Graph& G)
//    {
//        for (auto i = 1; i < G.vertices(); i++)
//        {
//            os << i << ":\t";
//
//            auto edges = G.outgoing_edges(i);
//            for (auto& e : edges)
//                os << "{" << e.dest << ": " << e.weight << "}, ";
//
//            os << std::endl;
//        }
//
//        return os;
//    }

    void print() {
        for (auto i = 1; i < vertices(); i++)

        {

            std::cout << i << ":\t";

            auto edges = outgoing_edges(i);

            for (auto& e : edges)

                std::cout << "{" << e.dest << ": " << e.weight << "}, ";

            std::cout << std::endl;

        }
    }


private:
    size_t V;		// Stores number of vertices in graph
    std::vector<Edge> edge_list;
};








#endif //SDIZO2_GRAPH_H
