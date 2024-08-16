// PHYS 30762 Programming in C++
// Assignment 3
// Isaac Clemeneger 07/03/2024
// File containing member functions of the class particle
#include<iostream>
#include"particle.h"

// Function that ensures the velocity is physical
double particle::check_velocity(double v)
{
    if (v > speed_of_light_in_vacuo || v < 0)
    { 
      std::cout<<"This velocity is non physical\n";
      // Throw so we can catch it in the try catch function in the main
      throw v;
    } 
    else 
    {
      return v;
    } 
}

// Function that prints particle data
void particle::print_particle_data()
{
  std::cout<<"Particle: [type,m,q,v,B] = ["<<type<<", "<<rest_mass<<", "<<charge<<", "<<velocity<<", "<<calculate_beta()<<"]\n";
  return;
}
