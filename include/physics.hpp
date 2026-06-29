#pragma once
#include "types.hpp"

namespace physics {

    // call at beginning of every time step to set f = 0
    void clear_forces(Particles& system, const LocalDomain& local_domain);

    // baseline O(N^2)
    void compute_forces_sequential(Particles& system, const LocalDomain& local_domain, double epsilon);

    // parallel implementation
    void compute_forces_openmp(Particles& system, const LocalDomain& local_domain, double epsilon);

    // Verlet step 1, call before compute_forces
    void update_positions(Particles& system, const LocalDomain& local_domain, double dt);
    // Verlet step 2, call after compute_forces
    void update_velocities(Particles& system, const LocalDomain& local_domain, double dt);
    // full sequence
    void step(Particles& system, const LocalDomain& local_domain, double dt);

    // correctness: energy should be conserved
    double compute_local_energy(Particles& system, const LocalDomain& local_domain, double epsilon);
}