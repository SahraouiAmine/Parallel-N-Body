#pragma once
#include <cstddef>
#include <cstdlib>

struct Particles {
    // SoA
    double* x = nullptr;
    double* y = nullptr;
    double* z = nullptr;

    double* vx = nullptr;
    double* vy = nullptr;
    double* vz = nullptr;

    double* fx = nullptr;
    double* fy = nullptr;
    double* fz = nullptr;

    double* mass = nullptr;

    size_t num_particles = 8192;

    void init(const size_t alignment = 64) {
        // space needed
        const size_t bytes = num_particles * sizeof(double);

        // then we pad to be multiple of alignment
        const size_t padded_bytes = (bytes + alignment - 1) & ~(alignment - 1);

        x = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
        y = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
        z = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));

        vx = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
        vy = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
        vz = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));

        fx = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
        fy = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
        fz = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));

        mass = static_cast<double*>(std::aligned_alloc(alignment, padded_bytes));
    }

    void free_memory() const {
        std::free(x);
        std::free(y);
        std::free(z);
        std::free(vx);
        std::free(vy);
        std::free(vz);
        std::free(fx);
        std::free(fy);
        std::free(fz);
        std::free(mass);
    }
};

// particles owned by one MPI rank
struct LocalDomain {
    size_t start_id;
    size_t num_particles;
};