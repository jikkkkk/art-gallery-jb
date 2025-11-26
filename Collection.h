
#ifndef COLLECTION_H
#define COLLECTION_H
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Exhibit.h"
#include "CollectionIsFullException.h"

using namespace std;

class Collection
{
    public:
        Collection(int&); // new constructor to create a collection with a specific maxNofExhibits
        Collection(string, int);
        virtual ~Collection();

        string getName() { return name; }
        void setName(string val) { name = val; }
        int getNofExhibits() { return exhibits.size(); }
        int getMaxNofExhibits() { return maxNofExhibits; }
        void setExhibits(Collection*);
        Exhibit *getExhibit(int val) { return exhibits[val]; }

        void display();
        void add_exhibit(Exhibit*); // add exhibit into the vector
        void sortByCost();
        void sortByYearOfCreation();
        bool findExhibit(Exhibit*); // find the exhibit in the vector
        void remove_exhibit(Exhibit*);

        Collection& operator=(Collection& other);

    private:
        string name;
        const int maxNofExhibits; //constant variable that hold the max amount of exhibits that can be held in the collection
        vector <Exhibit *> exhibits; //vector containing addresses of exhibits
};

bool orderByCost(Exhibit*, Exhibit*); //sorting criteria (non-member)
bool orderByYear(Exhibit*, Exhibit*); //sorting criteria (non-member)

#endif // COLLECTION_H
