#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph planner;
    int choice;

    while (true)
    {
        cout << "\n==== Travel Planner ====\n";
        cout << "1. Add City\n";
        cout << "2. Add Route\n";
        cout << "3. Show All Cities and Routes\n";
        cout << "4. Find Shortest Route\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 1)
        {
            string city;
            cout << "Enter city name: ";
            cin >> city;
            planner.addCity(city);
        }
        else if (choice == 2)
        {
            string from, to;
            int dist;
            cout << "From city: ";
            cin >> from;
            cout << "To city: ";
            cin >> to;
            cout << "Distance (in km): ";
            cin >> dist;
            planner.addRoute(from, to, dist);
        }
        else if (choice == 3)
        {
            planner.showCities();
        }
        else if (choice == 4)
        {
            string src, dest;
            cout << "Source city: ";
            cin >> src;
            cout << "Destination city: ";
            cin >> dest;
            planner.findShortestPath(src, dest);
        }
        else if (choice == 5)
        {
            cout << "Thank you for using Travel Planner!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
