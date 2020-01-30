//
// Created by Gandifil on 26.01.2020.
//

#ifndef COSMO_BLOCKALLOCATOR_H
#define COSMO_BLOCKALLOCATOR_H

#include <cstdint>
#include <array>
#include <bitset>

namespace Cosmo::Entities {
    template<typename T, size_t BlockCount, size_t BlockSize>
    class BlockAllocator {
    public:
        constexpr static size_t size = BlockCount * BlockSize;
        using pointer = T*;
        using M = uint8_t;

        BlockAllocator() {
            map.set();
        }

        pointer allocate(size_t n) {
            if (n > BlockSize)
                throw std::bad_alloc();

            for (size_t i = 0; i < BlockCount; ++i)
                if (map[i]) {
                    map[i] = false;
                    return getPointer(i);
                }

            throw std::bad_alloc();
        }

        void deallocate(pointer p) {
            map[getIndex(p)] = true;
        }

        void deallocateAll() {
            map.set();
        }

    private:
        std::bitset<BlockCount> map;

        using Block = std::array<uint8_t, BlockSize>;
        std::array<Block, BlockCount> memory;

        [[nodiscard]] inline pointer getPointer(size_t index) {
            return reinterpret_cast<pointer>(
                    reinterpret_cast<M *>(&memory) + BlockSize * index);
        }

        inline size_t getIndex(pointer p) {
            auto difference = reinterpret_cast<M *>(p) - reinterpret_cast<M *>(&memory);
            return difference / BlockSize;
        }
    };
}

#endif //COSMO_BLOCKALLOCATOR_H
