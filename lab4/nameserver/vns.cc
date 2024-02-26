#include <algorithm>

#include "vns.h"


void VNS::insert(const HostName& host, const IPAddress& ip) {
    dns.push_back(make_pair(host, ip));
}

bool VNS::remove(const HostName& host) {
    auto it = find_if(dns.begin(), dns.end(), [host](const pair<string, IPAddress>& p) {
        return p.first == host;
    });
    if (it != dns.end()) {
        dns.erase(it);
        return true;
    }
    return false;
}

IPAddress VNS::lookup(const HostName& host) const {
    auto it = find_if(dns.begin(), dns.end(), [host](const pair<string, IPAddress>& p) {
        return p.first == host;
    });
    if (it != dns.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}