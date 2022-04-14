#pragma once

static const uint32_t MASK_4 = 0x0000000f;
static const uint32_t MASK_8 = 0x00000ff0;
static const uint32_t MASK_20 = 0xfffff000;

#define MASK(value, mask, bit) (((value) >> (bit)) & (mask))


static uint32_t bswap_32(uint32_t x) {
    x = ((x << 8) & 0xFF00FF00) | ((x >> 8) & 0x00FF00FF);
    return (x >> 16) | (x << 16);
}


typedef struct IPv4Header {
    //IP数据报头
    uint8_t Ver_HLen;
    //版本+报头长度
    uint8_t TOS;
    //服务类型
    uint16_t TotalLen;
    //总长度
    uint16_t ID;
    //标识
    uint16_t Flag_Segment;
    //标志+片偏移
    uint8_t TTL;
    //生存周期
    uint8_t Protocol;
    //协议类型
    uint16_t Checksum;
    //头部校验和
    uint32_t SrcIP;
    //源IP地址
    uint32_t DstIP;
    //目的IP地址
};

typedef struct IPv6Header {
    //头32位
    struct IPHeaderDiv {
        uint16_t _len;
        uint8_t _nextHeader;
        uint8_t _jumpLim;
    };
    //第二个32位
    uint32_t _header1;
    IPHeaderDiv _header2;

    uint8_t sourceAddress[16];
    uint8_t desAddress[16];

    int getVersion() {
        auto tempVersion = this->_header1 & 0xff;
        return tempVersion >> 4;
    }

    int getComType() {
        uint8_t tempComType = this->_header1 & 0xff;
        tempComType = tempComType << 4;
        uint8_t tempComType2 = (this->_header1 >> 8) & 0xff;
        tempComType2 >> 4;
        uint8_t result = (tempComType << 4) | (tempComType2);
        return result;
    }

    int getSteamTag() {
        auto tempTag = this->_header1 & 0xffff0f00;
        return 0;
        //return tempTag>>
    }
};