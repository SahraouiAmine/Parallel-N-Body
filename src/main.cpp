#include <types.hpp>
#include <random>
#include <cstddef>

int main() {

    std::size_t N = 1000;
    std::size_t alignment = 64;

    Particles system;
    system.init(N, alignment);



    std::random_device rd;
    std::mt19937 gen(rd());



}