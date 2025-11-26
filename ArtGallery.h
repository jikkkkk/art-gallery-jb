/* Aleksandra Dozorova */

#ifndef ARTGALLERY_H
#define ARTGALLERY_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Collection.h"
#include <stdlib.h>

using namespace std;

class ArtGallery
{
    public:
        ArtGallery();
        ArtGallery(string, string);
        ArtGallery(ArtGallery&);
        virtual ~ArtGallery();

        string getName() { return name; }
        void setName(string val) { name = val; }
        string getLocation() { return location; }
        void setLocation(string val) { location = val; }
        Collection* getCollection() { return collectionPtr; }
        void setCollection(Collection* val);

        //overloaded assignment operators
        ArtGallery& operator=(ArtGallery&);
        //overloaded istream and ostream operators
        friend istream& operator>> (istream &cin, ArtGallery&);
        friend ostream& operator<< (ostream &cout, ArtGallery&);

        void write_to_file();
        void read_from_file();

        void display();

    private:
        string name;
        string location;
        Collection* collectionPtr; // each art gallery will have 1 collection (1 to 1 aggregartion relationship)
};

#endif // ARTGALLERY_H
