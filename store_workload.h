#include "hashmap.h"
#include <fstream>

using namespace std;

#ifndef _STORE_WORKLOAD_H_
#define _STORE_WORKLOAD_H_

#define _SORT_KEYS_ 0

class StoreWorkload : public Hashmap {
private:
    ofstream keys_file;
    ofstream ops_file;

    char fetchOpcode = 0;
    char insertOpcode = 1;
    char deleteOpcode = 2;
public:
    StoreWorkload();
    void initHashpower(int);
    void bulkLoad(ulong*, ulong);
    Metrics processRequests(HashmapReq*, ulong);
    void rehash();
    void free();

    void _heapify(ulong*, long, long);
    void _heapSort(ulong*, long);
};

#endif // _STORE_WORKLOAD_H_
