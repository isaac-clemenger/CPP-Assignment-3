// PHYS 30762 Programming in C++
// Assignment 3
// Isaac Clemeneger 07/03/2024
// Header for detector class, contains variables of type and status

#ifndef DETECTOR_H
#define DETECTOR_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"particle.h"

// Initialise constants
const double electron_rest_mass{0.511}, muon_rest_mass{105.7};

class detector
{
  private:
    std::string detector_type;
    bool status; // 0 for off, or 1 for on
    int detected_particles{0};

  public:
    // Default constructor
    detector() = default;
    // Parameterised constructor
    detector(std::string new_type, bool new_status) :
    detector_type{new_type}, status{new_status}
    {}
    // Destructor
    ~detector(){}

    // Turn off and on functions
    void turn_on() {status = 1;}
    void turn_off() {status = 0;}

    // Function to check if particles are detected
    bool what_is_detected(particle partcile_data);
    void print_detector_data();
};

#endif