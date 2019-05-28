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

![](Chapter\ 1\:\ Output\ an\ image/pixel.png)
`注意：`
1. 像素以行从左到右的顺序写出。
2. 行从上到下写出。
3. 按照惯例，每个红色/绿色/蓝色分量范围从0.0到1.0。 我们会稍后我们在内部使用高动态范围时放松，但在输出之前我们会调整映射到零到一个范围，因此此代码不会更改。
4. 红色从左到右从黑色到完全打开，绿色从黑色到达
5. 在底部完全打开顶部。 红色和绿色一起变黄，所以我们应该期待
右上角是黄色的

