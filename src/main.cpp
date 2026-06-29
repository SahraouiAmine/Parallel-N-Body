#include <types.hpp>
#include <random>
#include <cstddef>

int main() {
    constexpr std::size_t num_particle = 8192;
    Particles system;
    system.init(num_particle);

}