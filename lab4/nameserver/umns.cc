#include "umns.h"

void UMNS::insert(const HostName& host, const IPAddress& ip) {
    dns[host] = ip;
}

bool UMNS::remove(const HostName& host) {
    if (dns.erase(host) > 0) {
        return true;
    }
    return false;
}

IPAddress UMNS::lookup(const HostName& host) const {
    auto it = dns.find(host);
    if (it != dns.end()) {
        return it->second;
    }
    return NON_EXISTING_ADDRESS;
}
