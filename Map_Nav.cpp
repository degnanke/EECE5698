//
//  Map_Nav.cpp
//  Map_Nav
//
//  Created by Kurt Jaisle on 11/28/17.
//  Copyright © 2017 Kurt Jaisle. All rights reserved.
//

#include "Map_Nav.hpp"
#include <iostream>

Map_Nav::Map_Nav(){
    width = 0;
    height = 0;
    openCode = 254;
    unexCode = 205;
    obstCode = 0;
}

Map_Nav::Map_Nav(vector<vector <int> > matrix) {
    
    map = matrix;
    
    width = matrix.size();
    height = matrix[0].size();
    openCode = 254;
    unexCode = 205;
    obstCode = 0;
    
}


Map_Nav::Map_Nav(int w, int h){
    width = w;
    height = h;
    map.resize(h, std::vector<uint8_t>(w));
    openCode = 254;
    unexCode = 205;
    obstCode = 0;
}

void Map_Nav::findBestFrontierPoint(int currentRow, int currentCol, int& pointRow, int& pointCol){
    std::vector<int> pointRows;
    std::vector<int> pointCols;
    int row, col;
    for (row=1;row<height-1;row++){
        for (col=1;col<width-1;col++){
            if (map[row][col] == openCode){
                if (map[row+1][col]==unexCode || map[row-1][col]==unexCode || map[row][col-1]==unexCode || map[row][col+1]==unexCode){
                    pointRows.push_back(row);
                    pointCols.push_back(col);
                }
            }
        }
    }
    int bestRowSoFar = 0;
    int bestColSoFar = 0;
    float bestDistSoFar = 9999999;
    float tempDist;
    int i;
    for (i=0;i<pointRows.size();i++){
        tempDist = (pointRows[i]-currentRow) + (pointCols[i]-currentCol);
        if (tempDist < bestDistSoFar){
            bestDistSoFar = tempDist;
            bestRowSoFar = pointRows[i];
            bestColSoFar = pointCols[i];
        }
    }
    pointRow = bestRowSoFar;
    pointCol = bestColSoFar;
}


void Map_Nav::print(){
    int h, w;
    for (h=0;h<height;h++){
        for (w=0;w<width;w++){
            std::cout << int(map[h][w]) << " ";
        }
        std::cout << std::endl;
    }
}
