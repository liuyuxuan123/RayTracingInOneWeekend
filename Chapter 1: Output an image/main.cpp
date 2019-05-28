//
//  main.cpp
//  Chapter 1: Output an image
//
//  Created by 刘宇轩 on 2019/5/28.
//  Copyright © 2019 yuxuanliu. All rights reserved.
//

#include <iostream>
#include <fstream>

const std::string currentPath = "/Users/liuyuxuan/Desktop/RayTracingInOneWeekend/Chapter 1: Output an image/";

int main() {
    int nx = 200;
    int ny = 100;
    std::ofstream pixelFile(currentPath + "pixel.ppm");
    
    pixelFile <<  "P3\n" << nx << " " << ny << "\n255\n";
    for(int j = ny - 1; j >= 0; j --){
        for(int i = 0;i < nx;i ++){
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            pixelFile << ir << " " << ig << " " << ib << "\n";
        }
    }
    pixelFile.close();
}
