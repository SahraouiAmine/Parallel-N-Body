#include "physics.hpp"
#include <cmath>
#include "types.hpp"

void physics::clear_forces(Particles &system, const LocalDomain &local_domain) {

    for (int i = 0; i < local_domain.num_particles; i++) {
        const int target = local_domain.start_id + i;
        system.fx[target] = 0.0;
        system.fy[target] = 0.0;
        system.fz[target] = 0.0;
    }

}

void physics::compute_forces_sequential(Particles &system, const LocalDomain &local_domain, double epsilon) {
    // force felt by particles in the domain
    // from particles in the whole system
    const double soft = epsilon * epsilon;

    for (int i = 0; i < local_domain.num_particles; i++) {
        const int target = local_domain.start_id + i;
        const double M = system.mass[target];
        double Fx = 0.0;
        double Fy = 0.0;
        double Fz = 0.0;
        for (int j = 0; j < system.num_particles; j++) {
            const double m = system.mass[j];

            const double dx = system.x[j] - system.x[target];
            const double dy = system.y[j] - system.y[target];
            const double dz = system.z[j] - system.z[target];

            const double r_squared = dx * dx + dy * dy + dz * dz + soft;
            const double inv_r = 1.0 / std::sqrt(r_squared);

            Fx += dx * m * inv_r * inv_r * inv_r;
            Fy += dy * m * inv_r * inv_r * inv_r;
            Fz += dz * m * inv_r * inv_r * inv_r;

        }

        Fx *= M;
        Fy *= M;
        Fz *= M;

        system.fx[target] = Fx;
        system.fy[target] = Fy;
        system.fz[target] = Fz;

    }
}

void physics::update_positions(Particles& system, const LocalDomain& local_domain, double dt) {
    for (int i = 0; i < local_domain.num_particles; i++) {
        int target = local_domain.start_id + i;
        const double inv_M = 1.0 / system.mass[target];

        system.vx[target] += dt * 0.5 * (system.fx[target] * inv_M);
        system.vy[target] += dt * 0.5 * (system.fy[target] * inv_M);
        system.vz[target] += dt * 0.5 * (system.fz[target] * inv_M);

        system.x[target] += dt * system.vx[target];
        system.y[target] += dt * system.vy[target];
        system.z[target] += dt * system.vz[target];
    }
}

void physics::update_velocities(Particles& system, const LocalDomain& local_domain, double dt) {

    for (int i = 0; i < local_domain.num_particles; i++) {
        int target = local_domain.start_id + i;
        const double inv_M = 1.0 / system.mass[target];

        system.vx[target] += dt * 0.5 * (system.fx[target] * inv_M);
        system.vy[target] += dt * 0.5 * (system.fy[target] * inv_M);
        system.vz[target] += dt * 0.5 * (system.fz[target] * inv_M);
    }

}

void step(Particles& system, const LocalDomain& local_domain, double dt, double epsilon) {
    physics::update_positions(system, local_domain, dt);
    physics::clear_forces(system, local_domain);
    physics::compute_forces_sequential(system, local_domain, epsilon);
    physics::update_velocities(system, local_domain, dt);
}

double compute_local_energy(Particles& system, const LocalDomain& local_domain, double epsilon) {
    return 0.0;
}