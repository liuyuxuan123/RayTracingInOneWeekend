#  Chapter 1: Output an image
## `PPM Format`
&emsp;`PPM`格式也就是`Portable Pixmap Format`。它的格式很简单：
```
P3
3 2
255
# The part above is the header
# "P3" means this is a RGB color image in ASCII
# "3 2" is the width and height of the image in pixels
# "255" is the maximum value for each color
# The part below is image data: RGB triplets
255   0   0     0 255   0     0   0 255
255 255   0   255 255 255     0   0   0
```
&emsp;我们可以用`C++语言`输出这一段：
```
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

```

![](RayTracingInOneWeekend/images/pixel.png)
`注意：`
1. The pixels are written out in rows with pixels left to right.
2. The rows are written out from top to bottom.
3. By convention, each of the `red/green/blue` components range from 0.0 to 1.0. We will
relax that later when we internally use high dynamic range, but before output we will tone
map to the zero to one range, so this code won’t change.
4. Red goes from black to fully on from left to right, and green goes from black at the
bottom to fully on at the top. Red and green together make yellow so we should expect
the upper right corner to be yellow.

