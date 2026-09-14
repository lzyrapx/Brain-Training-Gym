int main() {
    float k;
    sscanf(Stdio.stdin->gets(), "%f", k);
    
    float pi = acos(-1.0);
    k = k * pi / 180.0;
    
    float x, y;
    sscanf(Stdio.stdin->gets(), "%f %f", x, y);

    float xx,yy;
    // 二维平面标准旋转公式
    xx = x * cos(k) - y * sin(k);
    yy = x * sin(k) + y * cos(k);
    write(xx + " " + yy);
}