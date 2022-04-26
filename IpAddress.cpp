/*
 * @Author: hongdong.liao
 * @Date: 2022-04-26 09:46:52
 * @LastEditors: hongdong.liao
 * @LastEditTime: 2022-04-26 10:32:50
 * @FilePath: /test/IpAddress.cpp
 */
#include "IpAddress.hpp"

std::string IpAddress::getIp() {
    struct ifaddrs* ptr_ifaddrs = nullptr;
    auto result = getifaddrs(&ptr_ifaddrs);
    if( result != 0 ){
        std::cout << "`getifaddrs()` failed: " << strerror(errno) << std::endl;
        // return EX_OSERR;
        return "";
    }
    std::string ipaddress = "";
    for(
        struct ifaddrs* ptr_entry = ptr_ifaddrs;
        ptr_entry != nullptr;
        ptr_entry = ptr_entry->ifa_next
    ){
        std::string ipaddress_human_readable_form;
        std::string netmask_human_readable_form;
        std::string interface_name = std::string(ptr_entry->ifa_name);
        sa_family_t address_family = ptr_entry->ifa_addr->sa_family;
        if( address_family == AF_INET ){
            if( ptr_entry->ifa_addr != nullptr ){
                char buffer[INET_ADDRSTRLEN] = {0, };
                inet_ntop(
                    address_family,
                    &((struct sockaddr_in*)(ptr_entry->ifa_addr))->sin_addr,
                    buffer,
                    INET_ADDRSTRLEN
                );
                ipaddress_human_readable_form = std::string(buffer);
            }
            if( ptr_entry->ifa_netmask != nullptr ){
                char buffer[INET_ADDRSTRLEN] = {0, };
                inet_ntop(
                    address_family,
                    &((struct sockaddr_in*)(ptr_entry->ifa_netmask))->sin_addr,
                    buffer,
                    INET_ADDRSTRLEN
                );
                netmask_human_readable_form = std::string(buffer);
            }
            std::cout << interface_name << ": IP address = " << ipaddress_human_readable_form << ", netmask = " << netmask_human_readable_form << std::endl;
            ipaddress = ipaddress_human_readable_form;
        }
        // else if( address_family == AF_INET6 ){
        //     // IPv6
        //     uint32_t scope_id = 0;
        //     if( ptr_entry->ifa_addr != nullptr ){
        //         char buffer[INET6_ADDRSTRLEN] = {0, };
        //         inet_ntop(
        //             address_family,
        //             &((struct sockaddr_in6*)(ptr_entry->ifa_addr))->sin6_addr,
        //             buffer,
        //             INET6_ADDRSTRLEN
        //         );
        //         ipaddress_human_readable_form = std::string(buffer);
        //         scope_id = ((struct sockaddr_in6*)(ptr_entry->ifa_addr))->sin6_scope_id;
        //     }
        //     if( ptr_entry->ifa_netmask != nullptr ){
        //         char buffer[INET6_ADDRSTRLEN] = {0, };
        //         inet_ntop(
        //             address_family,
        //             &((struct sockaddr_in6*)(ptr_entry->ifa_netmask))->sin6_addr,
        //             buffer,
        //             INET6_ADDRSTRLEN
        //         );
        //         netmask_human_readable_form = std::string(buffer);
        //     }
        //     std::cout << interface_name << ": IP address = " << ipaddress_human_readable_form << ", netmask = " << netmask_human_readable_form << ", Scope-ID = " << scope_id << std::endl;
        // }
        else {
            // AF_UNIX, AF_UNSPEC, AF_PACKET etc.
            // If ignored, delete this section.
        }
    }
    freeifaddrs(ptr_ifaddrs);
    return ipaddress;
};

bool IpAddress::checkIpIsIntranet() {
    std::cout << "Checking" << std::endl;
    return true;
};