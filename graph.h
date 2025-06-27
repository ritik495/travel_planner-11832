#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm> // for reverse
using namespace std;

class Graph
{
private:
    map<string, vector<pair<string, int>>> adj;

public:
    void addCity(string name)
    {
        if (adj.count(name) == 0)
            adj[name] = {};
    }

    void addRoute(string from, string to, int distance)
    {
        adj[from].push_back({to, distance});
        adj[to].push_back({from, distance}); // undirected
    }

    void showCities()
    {
        for (auto &city : adj)
        {
            cout << city.first << " --> ";
            for (auto &nbr : city.second)
            {
                cout << "(" << nbr.first << ", " << nbr.second << " km) ";
            }
            cout << endl;
        }
    }

    void findShortestPath(string src, string dest)
    {
        map<string, int> dist;
        map<string, string> parent;

        for (auto &city : adj)
        {
            dist[city.first] = INT_MAX;
        }

        dist[src] = 0;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            pair<int, string> top = pq.top();
            pq.pop();
            int d = top.first;
            string u = top.second;

            for (auto &nbr : adj[u])
            {
                string v = nbr.first;
                int weight = nbr.second;

                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[dest] == INT_MAX)
        {
            cout << "No route found from " << src << " to " << dest << endl;
            return;
        }

        // Print path
        vector<string> path;
        string current = dest;

        while (current != src)
        {
            path.push_back(current);
            current = parent[current];
        }

        path.push_back(src);
        reverse(path.begin(), path.end());

        cout << "Shortest path from " << src << " to " << dest << ": ";
        for (auto &city : path)
        {
            cout << city << " ";
        }
        cout << "\nDistance: " << dist[dest] << " km" << endl;
    }
};

#endif // GRAPH_H
