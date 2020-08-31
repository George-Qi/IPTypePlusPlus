/**
 *  Author；George
 *  Data: July/23/2020, Thursday.
 * */ 
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class IPv4Type{
    private:
        unsigned int ip_m;
    public:
        /** c'tor **/ 
        IPv4Type();           
        IPv4Type(const string& ip);                               /** Init through string **/ 
        IPv4Type(unsigned int ip_uint32);                         /** Init ip as 0 **/ 
        IPv4Type(IPv4Type& ip_t);

        /** 
         * utils 
         * */ 
        /**
         * ip string to uint32
         * "192.168.0.1" -> 12344
         * 
         * @param ipStr
         * @return uint32
         * */ 
        unsigned int str_to_uint32(string ip_str);
        /**
         * ip uint32 to ipStr
         * 1234 -> "192.168.0.1"
         * 
         * @param uint32
         * @return ipStr
         * */ 
        string uint32_to_str(unsigned int ip_uint32);
        /**
         * ip uint32 to decSegment
         * 123343 -> 192
         * 
         * @param uint32
         * @return decSeg
         * */ 
        unsigned int getDecSeg( unsigned int num, unsigned int i);

        /** 
         * operator reload **/ 
        /**
         * IPv4Type = "192.168.0.1"
         * */ 
        void operator=(string ip_str);              /** input through ip string **/ 
        /**
         * IPv4Type == IPv4Type
         * */ 
        bool operator==(IPv4Type ip_t);
        /**
         * IPv4Type[0], IPv4Type[1], IPv4Type[2], IPv4Type[3]
         * */ 
        unsigned int operator[](const int i);
        /**
         * cout << IPv4Type
         * */ 
        friend std::ostream & operator<<(std::ostream & os, IPv4Type & ip_t);

        /** Get decimal IP **/ 
        unsigned int dec_format();
        /** Get cpp string IP **/ 
        string str_format();
};

