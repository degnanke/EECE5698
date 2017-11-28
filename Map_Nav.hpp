//
//  Map_Nav.hpp
//  Map_Nav
//
//  Created by Kurt Jaisle on 11/28/17.
//  Copyright © 2017 Kurt Jaisle. All rights reserved.
//

#ifndef Map_Nav_hpp
#define Map_Nav_hpp

#include <stdio.h>
#include <cstdint>
#include <vector>

class Map_Nav {
private:
    int width;
    int height;
    int openCode;
    int obstCode;
    int unexCode;
    std::vector<std::vector<uint8_t>> map;
public:
    Map_Nav();
    Map_Nav(int w, int h);
    void findBestFrontierPoint(int currentRow, int currentCol, int& pointRow, int& pointCol);
    void print();
};

#endif /* Map_Nav_hpp */
