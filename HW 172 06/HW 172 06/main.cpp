//
//  main.cpp
//  HW 172 06
//
//  Created by Eric Klicker on 11/7/16.
//  Copyright © 2016 Eric Klicker. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "Circle.hpp"
#include "Comlex.hpp"

using namespace std;
void babyNames()
{
    string year;
    string gender;
    string name;
    string fileName = "Babynameranking.txt";
    cout << "Enter the year (2010-2014): ";
    cin >> year;
    cout << "Enter the gender (M/F): ";
    cin >> gender;
    cout << "Enter the name: ";
    cin >> name;
    
    fileName.insert(fileName.size()-4, year);
    cout << fileName << endl;
    
    ifstream fileIO(fileName);
    if(!fileIO)
    {
        cout << "ERROR: Could not open file" << endl;
    }
    else
    {
        string searchName;
        string count = "";
        while(!fileIO.eof())
        {
            int rank;
            string bname;
            string bnum;
            string gname;
            string gnum;
            fileIO >> rank >> bname >> bnum >> gname >> gnum;
            if(gender == "M")
            {
                if(name == bname)
                {
                    cout << bname << " is ranked #" << rank << " in year " << year << endl;
                }
            }
            if(gender == "F")
            {
                if(name == gname)
                {
                    cout << gname << " is ranked #" << rank << " in year " << year << endl;
                }
            }
        }
    }
    
    fileIO.close();
}

void testCircleOperators()
{
    Circle c1(5);
    Circle c2(10);
    
    if(c1 < c2)
        cout << "The first circle is smaller than the second." << endl;
    if(c1 <= c2)
        cout << "The fist circle is smaller than or equal to the second." << endl;
    if(c1 == c2)
        cout << "The first circle is equal to the second." << endl;
    if(c1 != c2)
        cout << "The first circle is not equal to the second." << endl;
    if(c1 > c2)
        cout << "The first circle is greater than the second." << endl;
    if(c1 >= c2)
        cout << "The first circle is greater than or equal to the second." << endl;
}

void testComplex()
{
    int A, B;
    int C, D;
    cout << "Enter the first complex number: ";
    cin >> A >> B;
    cout << "Enter the second complex number: ";
    cin >> C >> D;
    Complex c1(A, B);
    Complex c2(C, D);
    Complex c3 = c1.add(c2);
    cout << c3.toString() << endl;
    
}

int main()
{
    //Excercise 13.1
    ofstream output;
    
    
    output.open("Exercise13_1.txt");     //create a file
    srand(time(NULL));
    
    int number = rand() % 100;
    for (int i = 0; i < 100; i++)
    {
        output << number << " ";
        number = rand() % 100;
    }
    output.close();
    
    cout << "done" << endl;
    
    
    
    //Excercise 13.2
    string fileName;
    char c;
    int count = -1;
    cout << "Enter a file name: " << endl;
    cin >> fileName;
    
    ifstream input(fileName.c_str());
    
    if (input.fail())
        cout << fileName << " does not exist" << endl;
    else
        cout << fileName << " exists " << endl;
    
    while (!input.eof())
    {
        input >> c;
        ++count;
    }
    cout << count << endl;
    
    
    
    
;    //13.5 Baby names
    babyNames();
    
    
    //14.3
    testCircleOperators();
    
    //14.7
    testComplex();
    
    return 0;
}
    
   