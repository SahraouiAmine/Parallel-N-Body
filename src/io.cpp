#include <iostream>
#include <ostream>
#include <random>
#include "types.hpp"

void init_random_cube(Particles& system, float box_size, double total_mass) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, box_size);
    double unit_mass = total_mass / system.num_particles;

    for (int n = 0; n < system.num_particles; n++) {
        system.x[n] = static_cast<double>(dis(gen));
        system.y[n] = static_cast<double>(dis(gen));
        system.z[n] = static_cast<double>(dis(gen));

        system.vx[n] = 0.0;
        system.vy[n] = 0.0;
        system.vz[n] = 0.0;

        system.fx[n] = 0.0;
        system.fy[n] = 0.0;
        system.fz[n] = 0.0;

        system.mass[n] = unit_mass;
    }
}

void log_energy(const int step, const double kinetic, const double potential) {
    std::cout << kinetic << " " << potential << " " << step << std::endl;
}
