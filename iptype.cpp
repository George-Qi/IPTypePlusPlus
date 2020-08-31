#include "iptype.h"

/**
 *  c'tor
 * */ 
IPv4Type::IPv4Type(){
    ip_m = 0;
}

IPv4Type::IPv4Type(const string& ip){
    ip_m = str_to_uint32(ip);
}

IPv4Type::IPv4Type(unsigned int ip_uint32){
    ip_m = ip_uint32;
}

IPv4Type::IPv4Type(IPv4Type& ip_t){
    ip_m = ip_t.dec_format();
}



/**
 *  utils
 * */ 

unsigned int IPv4Type::getDecSeg(unsigned int num, unsigned int i){
    if(i == 0)  return (num>>24)&0xff;
    if(i == 1)  return (num>>16)&0xff;
    if(i == 2)  return (num>>8)&0xff;
    if(i == 3)  return (num)&0xff;
    return 0;
}


unsigned int IPv4Type::str_to_uint32(string ip_str){
    int point[3];  /** Position of 3 points **/ 
    unsigned int seg[4];
    
    /** find first point **/ 
    point[0] = ip_str.find('.', 0);
    // printf("Point %d in %d\n", 0, point[0]);
    /** find second point **/ 
    point[1] = ip_str.find('.', point[0]+1);
    // printf("Point %d in %d\n", 1, point[1]);
    /** find third point **/ 
    point[2] = ip_str.find('.', point[1]+1);
    // printf("Point %d in %d\n", 2, point[2]);

    seg[0] = stoi(ip_str.substr(0, point[0]));
    seg[1] = stoi(ip_str.substr(point[0]+1, point[1]-point[0]-1));
    seg[2] = stoi(ip_str.substr(point[1]+1, point[2]-point[1]-1));
    seg[3] = stoi(ip_str.substr(point[2]+1, ip_str.length()-1));

    return (seg[0]<<24)|(seg[1]<<16)|(seg[2]<<8)|(seg[3]);
}


string IPv4Type::uint32_to_str(unsigned int ip_uint32){
    return to_string(getDecSeg(ip_uint32, 0)) + "." + to_string(getDecSeg(ip_uint32, 1)) + "." +\
            to_string(getDecSeg(ip_uint32, 2)) + "." + to_string(getDecSeg(ip_uint32, 3));
}


/**
 *  Return IP String
 * */ 
string IPv4Type::str_format(){
    return uint32_to_str(ip_m);
}

/**
 *  Return Decimal ip
 * */ 
unsigned int IPv4Type::dec_format(){
    return ip_m;
}

/**
 * Operator reload
 * */ 
void IPv4Type::operator=(string ip_str){
    ip_m = str_to_uint32(ip_str);
}

bool IPv4Type::operator==(IPv4Type ip_t){
    if(ip_m == ip_t.ip_m)   return true;
    return false;
}

unsigned int IPv4Type::operator[](const int i){
    if(i>=0 && i<=3)  return getDecSeg(ip_m, i);
    return 0;
}

std::ostream & operator<<(std::ostream & os, IPv4Type & ip_t){
    os << ip_t.str_format();
    return os;
}
