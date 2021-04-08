/*---------------- 
Debanjan Saha
19CS30014
-----------------*/
// Disability.cpp
#include <string>
using namespace std;

#include "Disability.h"

// Names defined as static constants
template<>
const string Disability::Blind::sName = "Blind";
template<>
const string Disability::Orthopaedic::sName = "Orthopaedic";
template<>
const string Disability::Cancer::sName = "Cancer";
template<>
const string Disability::TB::sName = "TB";

// Salutations defined as static constants
template<>
const string Disability::Blind::sKey = "Blind";
template<>
const string Disability::Orthopaedic::sKey = "Orthopaedic";
template<>
const string Disability::Cancer::sKey = "Cancer";
template<>
const string Disability::TB::sKey = "TB";
