#include <types.hpp>
#include <random>
#include <cstddef>
#include "io.hpp"

int main() {
    constexpr std::size_t NUM_PARTICLES = 8192;
    LocalDomain full_domain{};
    full_domain.start_id = 0;
    full_domain.num_particles = NUM_PARTICLES;

    double dt = 0.01;
    int steps = 10000;
    double epsilon = 0.01;
    float box_size = 35.0f;



}