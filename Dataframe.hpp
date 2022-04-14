#pragma once
typedef struct FramHeader_t {
    //Pcap捕获的数据帧头
    uint8_t DstMAC[6];
    //目的MAC地址
    uint8_t SrcMAC[6];
    //源MAC地址
    u_int16_t FrameType;
    //帧类型
};

enum FrameType {
    IPV6 = 0xdd86,
};