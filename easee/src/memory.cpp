#include "memory.h"
#include "provider.h"

namespace {

int availableMemory() {
    int size = 32 * 1024;
    byte *buf;
    while ((buf = (byte *)malloc(--size)) == NULL)
        ;
    free(buf);
    return size;
}
}  // namespace

namespace easee {

Memory::Memory() {}

Memory::~Memory() {}

Memory::MemoryData Memory::getData(int t) {
    MemoryData data;
    data.data = ((float)availableMemory() / 1000);
    return data;
}

void Memory::setup() {}

void Memory::loop(int t) { Provider<MemoryData>::instance()->set(getData(t)); }

}  // namespace easee
