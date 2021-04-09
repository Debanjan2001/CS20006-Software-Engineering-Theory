# Description of Source.zip

## Made by 19CS30014, DEBANJAN SAHA. 

## Files :

1. Date.h and Date.cpp - Implementation of class Date.
2. Station.h and Station.cpp - Implementation of class Station.
3. Passenger.h and Passenger.cpp - Implementation of class Passenger.
4. BookingClasses.h and BookingClasses.cpp - Implementation of class BookingClasses and its parametric hierarchy.
5. Railways.h and Railways.cpp - Implementation of class Railways.
6. Gender.h and Gender.cpp - Implementation of class Gender.
7. Exceptions.h and Exceptions.cpp - Implementation of hierarchy of class Exceptions.
8. Booking.h and Booking.cpp - Implementation of class Booking.
9. BookingCategory.h and BookingCategory.cpp - Implementation of class BookingCategory and its polymorphic hierarchy.
10. Disability.h and Disability.cpp - Implementation of class Disability and its hierarchy for disablity types of passengers.
11. UnitTesting.cpp - Implementation of UnitTesting for classes Booking,Passenger,Date,Station.
12. ApplicationTesting.cpp - Implementation of UnitTesting for the Booking Application.

## Compiler Information: 

#### g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 (GNU-GCC Compiler)
#### Tested on - C++14 and above in Ubuntu 20.04

## How to Run Tests?

Extract the sources.zip file in a folder and open the folder location in a terminal.

To run unit tests run the following commands:

1. `g++ -std=c++14 Date.cpp Gender.cpp Exceptions.cpp Disability.cpp BookingClasses.cpp Station.cpp Passenger.cpp BookingCategory.cpp Railways.cpp Booking.cpp UnitTesting.cpp -o a.out`
2. `./a.out`

To run application tests run the following command:

1. `g++ -std=c++14 Date.cpp Gender.cpp Exceptions.cpp Disability.cpp BookingClasses.cpp Station.cpp Passenger.cpp BookingCategory.cpp Railways.cpp Booking.cpp ApplicationTesting.cpp -o a.out`
2. `./a.out`

