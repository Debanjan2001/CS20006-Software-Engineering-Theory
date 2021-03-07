/*----------------
Debanjan Saha
19CS30014
-----------------*/

//-------------------------FILE DESCRIPTIONS------------------------------------------------------------------------------------

Date.h - Header file of class Date
Date.cpp - Implementation of class Date

Station.h - Header file of class Station
Station.cpp - Implementation of class Station

Passenger.h - Header file of abstract base class Passenger.
Passenger.cpp - Implementation of class Passenger

Railways.h - Header file of Singleton Class Railways
Railways.cpp - Implementation of class Railways

BookingClasses.h - Header file of 3 abstract base classes - BookingClasses,SeatingClass,BerthClass and 7 concrete derived classes for a Booking in Railways System.
BookingClass.cpp - Implementation of all the abstract base classes and concrete classes

Booking.h - Header file of class Booking 
Booking.cpp - Implementation of class Booking

ApplicationTesting1.cpp - Invoking of Application Tests-1 inside main
ApplicationTesting2.cpp - Invoking of Application Tests-2 inside main
UnitTesting.cpp - Invoking of All unit tests inside main
--------------------------------------------------------------------------


// Additional Description------------------------------------------------------
Compiler Details - g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 (GNU-GCC Compiler)
Tested on - C++11 and above in Ubuntu 20.04
-------------------------------------------------------------------------------


//How to Run the program-------------------------------------------------------------------------------------------
Open the folder location containing all files in source.zip in a terminal
Run the following commands

1) To run the unit tests -

    (i) g++ -std=c++11 Passenger.cpp  Railways.cpp Booking.cpp BookingClasses.cpp Date.cpp Station.cpp UnitTesting.cpp 
    (ii) ./a.out

2) To run the application tests-

    (i) g++ -std=c++11 Passenger.cpp  Railways.cpp Booking.cpp BookingClasses.cpp Date.cpp Station.cpp ApplicationTesting1.cpp 
    (ii) ./a.out > Output1.txt
    (iii) g++ -std=c++11 Passenger.cpp  Railways.cpp Booking.cpp BookingClasses.cpp Date.cpp Station.cpp ApplicationTesting2.cpp 
    (iv) ./a.out > Output2.txt
-----------------------------------------------------------------------------------------------------------------------------------