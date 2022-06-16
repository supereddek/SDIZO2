//
// Created by super on 16.06.2022.
//

#ifndef SDIZO2_PRIM_H
#define SDIZO2_PRIM_H
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <limits>
#include "Graph.h"


class Prim {
    struct Label
    {
        size_t vertex_ID;
        size_t distance_from_frontier;

        Label(size_t _id, size_t _distance) :
                vertex_ID(_id),
                distance_from_frontier(_distance)
        {}

        // To compare labels, only compare their distances from source
        inline bool operator< (const Label& l) const
        {
            return this->distance_from_frontier < l.distance_from_frontier;
        }

        inline bool operator> (const Label& l) const
        {
            return this->distance_from_frontier > l.distance_from_frontier;
        }

        inline bool operator() (const Label& l) const
        {
            return *this > l; //??
        }
    };

    auto prim_MST(const Graph& G, size_t src)
    {
        std::priority_queue<Label, std::vector<Label>, std::greater<Label>> heap;
        std::set<int> visited;

        std::vector<size_t> distance(G.vertices(), std::numeric_limits<size_t>::max());
        std::vector<size_t> MST;

        heap.emplace(src, 0);

        // Search for the destination vertex in the graph
        while (!heap.empty())
        {
            auto current_vertex = heap.top();
            heap.pop();

            // If the current vertex hasn't been visited in the past
            if (visited.find(current_vertex.vertex_ID) == visited.end())
            {
                MST.push_back(current_vertex.vertex_ID);

                // For each outgoing edge from the current vertex,
                // create a label for the destination vertex and add it to the heap
                for (auto e : G.outgoing_edges(current_vertex.vertex_ID))
                {
                    auto neighbor_vertex_ID = e.dest;
                    auto new_distance_to_frontier = e.weight;

                    // Check if the new path to the vertex is shorter
                    // than the previously known best path. If yes, update the distance
                    if (new_distance_to_frontier < distance[neighbor_vertex_ID])
                    {
                        heap.emplace(neighbor_vertex_ID, new_distance_to_frontier);
                        distance[e.dest] = new_distance_to_frontier;
                    }
                }

                visited.insert(current_vertex.vertex_ID);
            }
        }

        return MST;
    }


};


#endif //SDIZO2_PRIM_H
