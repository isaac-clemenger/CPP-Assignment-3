// PHYS 30762 Programming in C++
// Assignment 3
// Isaac Clemeneger 07/03/2024
// Header for particle class, contains variables: type, mass, charge, velocity for any particle

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// Define constants
const double speed_of_light_in_vacuo{2.99792458e8};

class particle
{
private:
  std::string type;
  int charge;
  double rest_mass, velocity;

public:
  // Default constructor
  particle() = default;
  // Parameterised constructor
  particle(std::string particle_type, int particle_charge, double particle_rest_mass,
  double partcile_velocity) :
  type{particle_type}, charge{particle_charge}, rest_mass{particle_rest_mass},
  velocity{check_velocity(partcile_velocity)}
  {} 
  // Destructor
  ~particle(){}

  // Getter functions (accessors) to:
  std::string get_type() const {return type;}
  int get_charge() const {return charge;}
  double get_rest_mass() const {return rest_mass;}
  double get_velocity() const {return velocity;}

  // Function returning beta value 
  double calculate_beta() {return velocity / speed_of_light_in_vacuo;}

  // Setter functions, to change value of data members
  void set_type(const std::string particle_type) {type = particle_type;}
  void set_charge(const int particle_charge) {charge = particle_charge;}
  void set_rest_mass(const double particle_rest_mass) {rest_mass = particle_rest_mass;}
  void set_velocity(const double particle_velocity) {velocity = check_velocity(particle_velocity);}

  // Make sure you check input validity before changing something
  double check_velocity(double v);
  // Function to print info about a particle
  void print_particle_data();
};

#endif