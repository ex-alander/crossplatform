#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#define mega (1024 * 1024)
using namespace std;

// so that it automatically renews
void printMeSta() {
    MEMORYSTATUSEX meSta;
    meSta.dwLength = sizeof(meSta);
    GlobalMemoryStatusEx(&meSta);
    cout << "Available virtual memory: " << meSta.ullAvailVirtual / mega << " MB" << endl;
}

int main() {
    vector<void*> allocMemBlocks;
    MEMORYSTATUSEX meSta;
    meSta.dwLength = sizeof(meSta);
    GlobalMemoryStatusEx(&meSta);
    cout << "Total virtual memory: " << meSta.ullTotalVirtual / mega << " MB" << endl;
    printMeSta();

    // alloc till the end
    const int blockSize = 100 * mega; // 100 MB
    int iter = 0;
    while (true) {
        void* block = VirtualAlloc(nullptr, blockSize, MEM_COMMIT, PAGE_READWRITE); // allocate a physical block of memory with the given size and permissions
        if (block == nullptr) {
            break;
        }
        allocMemBlocks.push_back(block);
        cout << "iter " << iter++ <<":\t";
        printMeSta();
    }
    cin.get();
    printMeSta();

    // delete every second
    for (auto i = 0; i < allocMemBlocks.size(); i += 2) {
        VirtualFree(allocMemBlocks[i], 0, MEM_RELEASE);
    }
    cin.get();
    printMeSta();

    // trying to alloc all available memory
    meSta.dwLength = sizeof(meSta);
    GlobalMemoryStatusEx(&meSta);
    int available = meSta.ullTotalVirtual;
    void* resBlock = VirtualAlloc(nullptr, available, MEM_RESERVE, PAGE_READWRITE);

    // free all
    for (auto block : allocMemBlocks) {
        VirtualFree(block, 0, MEM_RELEASE);
    }
    cin.get();
    printMeSta();
}