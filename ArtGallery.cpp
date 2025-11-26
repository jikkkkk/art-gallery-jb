#include "ArtGallery.h"

ArtGallery::ArtGallery(){};

ArtGallery::ArtGallery(string n, string l) : name(n), location(l){}

ArtGallery::ArtGallery(ArtGallery &a){ //copy constructor
    cout << "Copy constructor called" << endl;
    //copy string and int variables from one object to another
    name = a.name;
    location = a.location;
    if (!collectionPtr){
        delete collectionPtr; // dealocate pointer if it was pointing to something already
    }
    int e = a.getCollection()->getMaxNofExhibits(); // get maxNofExhibits
    collectionPtr = new Collection(e); // allocate memory dynamically for the pointer
    collectionPtr->setName(a.getCollection()->getName()); // copy incformation from one pointer to another
    try{
        collectionPtr->setExhibits(a.getCollection());
    }
    catch (CollectionIsFullException ex){
        cout << "EXCEPTION: Collection is Full" << endl;
    }
}

ArtGallery::~ArtGallery(){
    // delete information pointer was pointing to and point it to NULL
    delete collectionPtr;
    collectionPtr = NULL;
}

void ArtGallery::setCollection(Collection *cPtr){
    if (!collectionPtr){
        delete collectionPtr; //dealocate pointer
    }
    int e = cPtr->getMaxNofExhibits(); //get maxNofexhibits
    collectionPtr = new Collection(e); //allocate memory dynamically
    collectionPtr->setName(cPtr->getName()); // set name
    collectionPtr->setExhibits(cPtr); // set vector from one collection to another
}

void ArtGallery::display(){
    cout << "The Art Gallery '" << name << "' is located in " << location << "." <<endl;
    cout << "Information about this collection: " << endl;
    collectionPtr->display();
    cout << endl;
}

istream& operator>> (istream &cin, ArtGallery &a) { //overloaded istream operator
    cout << "Enter location for the Art Gallery " << a.name << endl;
    cin >> a.location; // enter string that will be a location of the art gallery
    return cin;
}

ostream& operator<< (ostream &cout, ArtGallery &a) { //overloaded ostream operator
    cout << "The Art Gallery " << a.name << " is located in " << a.location << endl;
    return cout;
}

ArtGallery& ArtGallery::operator=(ArtGallery &a){ // overloaded assignment operator
    cout << "Assignment operator called" << endl;
    // copy strandard variables from one art gallery to another
    name = a.name;
    location = a.location;
    if (!collectionPtr){
        delete collectionPtr; // dealocate pointer
    }
    int e = a.getCollection()->getMaxNofExhibits(); // get const variable
    collectionPtr = new Collection(e); //allocate memory dynamically
    collectionPtr->setName(a.getCollection()->getName());
    collectionPtr->setExhibits(a.getCollection());
    return *this;
}

void ArtGallery::write_to_file(){
    ofstream file("Art Galleries/" + name + "_" + location + ".txt"); //open/create the file with an art gallery name in Art Galleries folder
    //write info into the file
    file << "\t\t\t" << "Art Gallery: " << name << endl;
    file << "Location: " << location << endl << endl;
    file << "Collection available: " << collectionPtr->getName() << endl;
    file << "Exhibits available:" << endl << endl;
    for (int  i=0; i < collectionPtr->getNofExhibits(); i++){
        file << collectionPtr->getExhibit(i) << endl;
    }
    file.close(); //close the file
}

void ArtGallery::read_from_file(){
    cout << "Information about " << name << " art gallery: " << endl;
    ifstream file("Art Galleries/" + name + "_" + location + ".txt"); //open the file corresponding to the art gallery
    //check if you are able to open the file
    if(!file){
        cout << "Unable to open file" << endl;
    }
    string temp;// create a string
    for (int i = 0; i < 4; i++){
        getline(file, temp); // get line with the available collection
    }
    cout << temp << endl; // print out the name of the collection available at the art gallery
    file.close(); //close the file
}
