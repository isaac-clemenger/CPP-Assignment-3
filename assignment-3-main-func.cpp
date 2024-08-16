// PHYS 30762 Programming in C++
// Assignment 3
// Isaac Clemeneger 07/03/2024
/* Main function for code that creates a vector of particle objects, then creates detector objects
and passes the particle vector through them and prints what is detected*/
/* To compile paste C:/msys64/ucrt64/bin/g++ --std=c++17 -g assignment-3-main-func.cpp particle.cpp detector.cpp -o main.exe
Then run the output file main.exe*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"particle.h"
#include"detector.h"

// Main program
int main()
{

  // Create the following particles: 
  // Two electrons, four muons, one antielectron, one antimuon
  std::vector<particle> particles;
  int number_of_electrons_wanted{2};
  int number_of_muons_wanted{4};
  int number_of_positrons_wanted{1};
  int number_of_antimuons_wanted{1};
  // Electrons and positrons, fill vector with set numbers of particles
  for (int i{}; i < (number_of_electrons_wanted + number_of_positrons_wanted); i++)
  {
    try
    {
      // Try and add an electron to the vector
      particles.push_back(particle("electron", -1, electron_rest_mass, rand()));
    } catch(...){
      // Skip over the rest of this iteration, as particle is not created due to unphysical parameters
      continue;
    }
    if (i < number_of_positrons_wanted)
    {
      // Reinstate a set number of electrons as positrons, note they have the same mass so don't change that
      particles[particles.size() - 1].set_type("positron");
      particles[particles.size() - 1].set_charge(+1);    
    }
  }
  // Muons and antimuons, repeat same process as for electrons
  for (int i{}; i < (number_of_muons_wanted + number_of_antimuons_wanted); i++)
  {
    try
    {
    particles.push_back(particle("muon", -1, muon_rest_mass, rand()));
    } catch(...)
    {
      continue;
    }
    if (i < number_of_antimuons_wanted)
    {
      particles[particles.size() - 1].set_type("antimuon");
      particles[particles.size() - 1].set_charge(+1);    
    }
  }

  // Print out the data from all the particles
  for (auto particle_it{particles.begin()}; particle_it < particles.end(); particle_it++)
  {
    particle_it->print_particle_data();
  }

  // Create the following detectors: a tracker, a calorimeter, a muon chamber, and initialising them as off
  detector tracker("tracker", 0);
  detector calorimeter("calorimeter", 0);
  detector muon_chamber("muon_chamber", 0 );

  // Turn the detectors on
  tracker.turn_on();
  calorimeter.turn_on();
  muon_chamber.turn_on();
  
  // Pass the list of particles into each detector
  for (auto particle_it{particles.begin()}; particle_it < particles.end(); particle_it++)
  {
    tracker.what_is_detected(*particle_it);
    calorimeter.what_is_detected(*particle_it);
    muon_chamber.what_is_detected(*particle_it);
  }

  // Turn the detectors off
  tracker.turn_off();
  calorimeter.turn_off();
  muon_chamber.turn_off();

  // Print a summary of how many particles were detected
  tracker.print_detector_data();
  calorimeter.print_detector_data();
  muon_chamber.print_detector_data();
  return 0;
}