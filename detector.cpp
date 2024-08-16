// PHYS 30762 Programming in C++
// Assignment 3
// Isaac Clemeneger 07/03/2024
// File including all member functions of the class detector

#include<iostream>
#include"detector.h"
#include"particle.h"

// Function which finds what is detected
bool detector::what_is_detected(particle partcile_data)
{
  if (status == 1)
  {
    if (detector_type == "muon_chamber")
   {
      // Checking mass so we get both particles and their antiparticles
      if (partcile_data.get_rest_mass() == muon_rest_mass)
      {
        std::cout<<partcile_data.get_type()<<" was detected by "<<detector_type<<"\n";
        detected_particles ++;
        return 1;
      }
      else 
      {
        return 0; 
      }
    }
    if (detector_type == "calorimeter")
    {
      if (partcile_data.get_rest_mass() == electron_rest_mass)
      {
        std::cout<<partcile_data.get_type()<<" was detected by "<<detector_type<<"\n";
        detected_particles ++;
        return 1;
      }
      else 
      {
        // Calorimeter only detects electrons
        return 0; 
      }
    }
    if (detector_type == "tracker")
      {
        // Detects all particles
        std::cout<<partcile_data.get_type()<<" was detected by "<<detector_type<<"\n";
        detected_particles ++;
        return 1;
      }
  }
  else 
  {
    std::cout<<"Detector is off\n";
    return 0;
  } 
  return 0;
}

// Function to print detector data
void detector::print_detector_data()
{
  if (status == 1)
  {
    std::cout<<"Detector: [type,status,particles detected] = ["<<detector_type<<", on, "<<detected_particles<<"]\n";
  }
  else
  {
    std::cout<<"Detector: [type,status,particles detected] = ["<<detector_type<<", off, "<<detected_particles<<"]\n";
  }
}