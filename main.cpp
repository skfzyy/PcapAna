#include <iostream>
#include <fstream>
#include "PcapAnalysis.hpp"
#include "Dataframe.hpp"
#include "IPData.hpp"

#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")


int main() {
    std::ifstream capFile("F:\\project\\c++\\PCapAna\\data\\无附件邮件.pcap");
    pcap_file_header pcapHead;
    capFile.read((char*)&pcapHead,sizeof(pcap_file_header));
    pcap_pkthdr pcapSubHead;
    capFile.read((char *) &pcapSubHead, sizeof(pcap_pkthdr));
    char *data = new char[pcapSubHead.caplen];
    capFile.read((char *) data, pcapSubHead.caplen);

    //the next data is data frame
    FramHeader_t *frameHeader = (FramHeader_t*)data;
    if (frameHeader->FrameType==FrameType::IPV6) {
        //do next thing
        IPv6Header *ipv6Header = (IPv6Header *) (data + sizeof(FramHeader_t));
        auto version = ipv6Header->getVersion();
        auto comType = ipv6Header->getComType();
        auto streamTap = ipv6Header->getSteamTag();
        auto len = htons(ipv6Header->_header2._len);
        std::cout << "version: " << version << std::endl;
    }


    delete data;
    return 0;
}
