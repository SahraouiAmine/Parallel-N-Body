#pragma once
#include "types.hpp"

namespace io {
    // Fills the particle arrays with random coordinates between -box_size and +box_size,
    // zero initial velocity, and a standard mass.
    void init_random_cube(Particles& system, double box_size, double total_mass);

    // Prints the current time step and total energy (K + U) to the console.
    void log_energy(int step, double kinetic, double potential);
}