#include "hns.h"
#include <algorithm>
using namespace std;

HNS::HNS(size_t size) : size(size), hmap(size) {}

void HNS::insert(const HostName& host, const IPAddress& ip) {
    size_t index = hash<HostName>{}(host) % size;
    hmap[index].push_back(make_pair(host, ip));
}


bool HNS::remove(const HostName& host) {
    size_t index = hash<HostName>{}(host) % size;
    auto it = find_if(hmap[index].begin(), hmap[index].end(), [host](const pair<string, IPAddress>& p) {
        return p.first == host;
    });
    if (it != hmap[index].end()) {
        hmap[index].erase(it);
        return true;
    }
    return false;
}

IPAddress HNS::lookup(const HostName& host) const {
    size_t index = hash<HostName>{}(host) % size;
    auto it = find_if(hmap[index].begin(), hmap[index].end(), [host](const pair<string, IPAddress>& p) {
        return p.first == host;
    });
    if (it != hmap[index].end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}