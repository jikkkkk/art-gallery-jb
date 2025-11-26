/*
    Created by Jack Brady
    Final Submission
    Last edied 21.05.2022
*/

#include <iostream>
#include <string>
#include "Sculpture.h"
#include "Exhibit.h"
#include "Painting.h"
#include "Collection.h"
#include "ArtGallery.h"

using namespace std;

int main()
{

    //CREATE ARTISTS

    Artist a1("Alexandros of Antioch", "Italian", 50);
    try{
        a1.setNofCreations(0);
    }
    catch (string e){
        cout << e << endl;
    }
    Artist a2("Gian Lorenzo Bernini", "Italian", 1602, 5);
    Artist a3("Leonardo Da Vinci", "Italian", 1452, 20);
    Artist a4("Sandro Botticelli", "Italian", 1543, 6);
    Artist a5("Johannes Vermeer", "Dutch", 1632, 34);

    //CREATE SCULPTURES

    Sculpture s1("Venus De Milo", 130, 8500000, "Ceramic");
    s1.setArtist(&a1);

    Sculpture s2("Ecstasy of Saint Teresa", 1963, 786000, "Wood");
    s2.setArtist(&a2);

    Sculpture s3;
    s3 = s2; // use assignment operator to assign one Exhibit to another

    Sculpture s4("Jesus Christ Statue", 1500, 3000, "Granite");

    Sculpture s5(s1); // use copy contructor in Exhibit

    //CREATE PAINTINGS

    Painting p1("Girl with a pearl earring", 1665, 0620000, false);
    p1.setArtist(&a5); // Information at the address &a5 is taken in to setArtist function where it is assigned to painting p1

    Painting p2 ("The birth of Venus", 1486, 50000000, true);
    p2.setArtist(&a4);

    Painting p3("The Last Supper",1498, 470000, false);
    p3.setArtist(&a3);

    Painting p4("Salvator Mundi", 1500, 700000, true);
    p4.setArtist(&a3);

    Painting p5("Mona Lisa", 1503, 40000000, true);
    p5.setArtist(&a3);

    Painting p6("Primavera", 1482, 40000000, true);
    p6.setArtist(&a4);

    // ADD CREATIONS TO THE SET

    a3.addCreation(&p4);
    a3.addCreation(&p3);
    a3.addCreation(&p5);
    a3.addCreation(&p1);

    cout << endl << "DISPLAY ARTIST AND THEIR CREATIONS" << endl;
    a3.display();

    // CREATING COLLECTIONS

    Collection collection1("Egypt", 15);
    Collection collection2("Ancient Rome", 3);

    //ADD EXHIBITS TO COLLECTIONS
    collection1.add_exhibit(&p4);
    collection1.add_exhibit(&p5);
    collection1.add_exhibit(&p6);
    collection1.add_exhibit(&s1);
    collection1.add_exhibit(&s4);

    //ADD THE SAME EXHIBIT TWICE
    collection1.add_exhibit(&s4);

    collection2.add_exhibit(&p1);
    collection2.add_exhibit(&s2);
    collection2.add_exhibit(&s5);
    //ADD EXHIBIT INTO A FULL COLLECTION
    try{
        collection2.add_exhibit(&s3);
    }
    catch (CollectionIsFullException ex){
        cout << "EXCEPTION: Collection is Full" << endl;
    }

    //DISPLAY STATIC MEMBERS
    cout << "DISPLAY STATIC MEMBERS" << endl << endl;
    cout << "Overall number of paintings: " << p1.getNofPaintings() << endl;
    cout << "Overall number of sculptures: " << s1.getNofSculptures() << endl << endl;

    //DISPLAY OVERLOADED OPERATORS
    cout << "DISPLAY OVERLOADED OPERATORS WORKING" << endl;
    cout << "Year of creation Sculpture 4 " << s4.getYearOfCreation() << endl;
    cout << "Year of creation Painitng 1 " << p1.getYearOfCreation() << endl;

    cout << endl << "Is sculpture 4 < painting 1?" << endl;
    if (s4 < p1){
        cout << "yes, s4 < p1" << endl << endl;
    }
    else cout << "no, s4 > p1" << endl << endl;

    cout << "Year of creation Sculpture 4 " << s4.getYearOfCreation() << endl;
    cout << "Year of creation Painitng 4 " << p4.getYearOfCreation() << endl;

    cout << endl << "Is sculpture 4 < painting 1?" << endl;
    if (s4 == p4){
        cout << "yes, s4 == p4" << endl << endl;
    }
    else cout << "no, s4 != p4" << endl << endl;

    //DISPLAY SORT ALGORITHM
    cout << "DISPLAY SORTING ALGORITHM" << endl;
    cout << "BEFORE" << endl;
    collection2.display(); // display order of exhibits in the collection

    collection2.sortByYearOfCreation(); // use sotring algorithm to sort by year of creation
    cout << "AFTER SORTING" << endl << endl;
    collection2.display(); // display new order of the exhibits in the collection

    collection1.sortByCost(); // use sorting algorithm to sort by cost

    //CREATING ART GALLERIES
    ArtGallery artGallery1("Louvre", "Paris");
    ArtGallery artGallery2("The National Art Gallery", "Dublin");

    //ADD COLLECTIONS TO ART GALLERIES
    artGallery1.setCollection(&collection1);
    artGallery2.setCollection(&collection2);

    // DISPLAY ALL ART GALLERIES
    cout << "DISPLAYING GALLERY 1" << endl << endl;
    artGallery1.display();
    cout << "DISPLAYING GALLERY 2" << endl << endl;
    artGallery2.display();

    //FIND AN EXHIBIT

    collection1.findExhibit(&p6); // find exhibit that is in the collection
    collection1.findExhibit(&s2); // find an exhibit that is in the collection

    //CHECK COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR
    ArtGallery artGallery3;
    artGallery3 = artGallery1; // use of assignment operator in ArtGallery class
    ArtGallery artGallery4(artGallery2); // use of copy constructor in ArtGallery class

    //DISPLAY COPIED ART GALLERIES
    cout << "\nDISPLAYING ART GALLERY 3" << endl;
    artGallery3.display();

    cout << "\nDISPLAYING ART GALLERY 4" << endl;
    artGallery4.display();

    // ISTREAM AND OSTREAM OPERATORS
    cout << artGallery4 << endl; // print out information about the art gallery
    cin >> artGallery4; // change the location
    cout << endl << artGallery4 << endl; // show the change

    //WRITE ART GALLERY INFORMATION TO FILES
    artGallery1.write_to_file();
    artGallery2.write_to_file();
    artGallery4.write_to_file();

    //READ INFORMATION ABOUT ART GALLERY FROM FILE
    artGallery1.read_from_file();

    return 0;
}
