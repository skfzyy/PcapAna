//
// Created by shenhangke on 2022-4-14.
//

#ifndef PCAPANA_PCAPANALYSIS_HPP
#define PCAPANA_PCAPANALYSIS_HPP

typedef uint32_t u_int32_t;
typedef uint16_t u_int16_t;

struct pcap_file_header {
    union uMagic {
        u_int32_t magic;
        uint8_t arrMagic[4];
    } magic;
    //u_int32_t magic;
    /* 0xa1b2c3d4 */
    u_int16_t version_major;
    /* magjor Version 2 */
    u_int16_t version_minor;
    /* magjor Version 4 */
    int32_t thiszone;
    /* gmt to local correction */
    u_int32_t sigfigs;
    /* accuracy of timestamps */
    u_int32_t snaplen;
    /* max length saved portion of each pkt */
    u_int32_t linktype;
    /* data link type (LINKTYPE_*) */
};


struct time_val {
    u_int32_t tv_sec;
    /* seconds 含义同 time_t 对象的值 */
    u_int32_t tv_usec;
    /* and microseconds */
};

//pcap数据包头结构体
struct pcap_pkthdr {
    struct time_val ts;
    /* time stamp */
    u_int32_t caplen;
    /* length of portion present */
    u_int32_t len;
    /* length this packet (off wire) */
};



#endif//PCAPANA_PCAPANALYSIS_HPP
