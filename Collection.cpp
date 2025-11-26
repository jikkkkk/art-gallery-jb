#include "Collection.h"

Collection::Collection(int &m) : maxNofExhibits(m){}

Collection::Collection(string n, int m) : name(n), maxNofExhibits(m){}

Collection::~Collection(){}

void Collection::setExhibits(Collection *cPtr){
    // use STL function to assign elements of one vector to another vector
    exhibits.assign(cPtr->exhibits.begin(), cPtr->exhibits.end());
}

// display function to display all variables of the object
void Collection::display(){
    cout << "Name of the collection: " << name << endl
    << "Maximum number of exhibits: " << maxNofExhibits << endl
    << "Number of exhibits: " << exhibits.size() << endl
    << "Exhibits in the collection: " << endl << endl;
    //displaying all exhibits in the collection
    for (int  i=0; i < exhibits.size(); i++){
        exhibits[i]->display();
    }
}

// function to add objects into vector
void Collection::add_exhibit(Exhibit *e){
    //check if there is space in the collection
    if (exhibits.size() < maxNofExhibits){
        // check if the exhibit was already added to a collection
        if (e->getIsAdded() == false){
            exhibits.push_back(e);
            e->setIsAdded(true); // this exhibit cannot be added to a collection anymore
        }
        else{
            if (Collection::findExhibit(e) == false){//check if the exibit was added into another collection
                cout << "This exhibit is already in a different collection. You cannot add it to this collection." << endl;
            }
            else{// this exhibit is added into this collection
                cout << "This exhibit is already in this collection. You cannot add the same exhibit twice." << endl;
            }
        }
    }
    else{
        //throw collection is full exception
        CollectionIsFullException ex; //create the objects of that class
        throw ex;
    }
}

void Collection::remove_exhibit(Exhibit *e){
    exhibits.erase(remove(exhibits.begin(), exhibits.end(), e), exhibits.end());
    e->setIsAdded(false);
    cout << "Exhibit was removed from this collection." << endl;
}

bool Collection::findExhibit(Exhibit *e){
    vector <Exhibit *>::iterator it; // create an iterator to iterate through the vector
    it = find (exhibits.begin(), exhibits.end(), e); // find an element
    if (it != exhibits.end()){ //print out a message whether the element was found
        //cout << "Element " << e->getName() << " found in this collection" << endl;
        return true;
    }else{
        //cout << "Element " << e->getName() << " not found in this collection\n" << endl;
        return false;
    }
}

void Collection::sortByYearOfCreation(){ // sort algorithm to sort by year of creation
    sort(exhibits.begin(), exhibits.end(), orderByYear);
}

void Collection::sortByCost(){ // sort algorithm to sort by cost
    sort(exhibits.begin(), exhibits.end(), orderByCost);
}

bool orderByCost(Exhibit *e1, Exhibit *e2){ // sorting criteria (non-member)
    return(e1->getCost() < e2->getCost());
}

bool orderByYear(Exhibit *e1, Exhibit *e2){ // sorting criteria (non-member)
    return(e1->getYearOfCreation() < e2->getYearOfCreation());
}

Collection& Collection::operator=(Collection& other){ //overloaded assignment operator
    cout << "Assignment operator called" << endl;
    name = other.name;
    other.exhibits.assign(exhibits.begin(), exhibits.end()); //assign vector using STL functin 'assign'
    return *this;
}
