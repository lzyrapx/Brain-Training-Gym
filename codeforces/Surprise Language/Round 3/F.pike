int main() {
    int n = (int)Stdio.stdin->gets();
    array(int) c = ({ 1 });
    for (int i = 0; i < n; i++) {
        int a = (int)Stdio.stdin->gets();

        array(int) nxt_c = allocate(sizeof(c) + 1, 0);
        
        for (int j = 0; j < sizeof(c); j++) {
            nxt_c[j + 1] += c[j];
            nxt_c[j]     += c[j] * a;
        }
        c = nxt_c; // 更新多项式
    }
    int is_first = 1; // 是否输出正号
    
    for (int k = n; k >= 0; --k) {
        int val = c[k];
        if (val == 0) continue; // 系数为 0

        if (is_first) {
            if (val < 0) write("-");
            is_first = 0;
        } else {
            if (val > 0) write("+");
            else write("-");
        }

        int abs_val = abs(val);

        // X^0
        if (k == 0) {
            write("%d", abs_val);
            continue;
        }
        // 常数
        if (abs_val != 1) {
            write("%d*", abs_val);
        }
        if (k == 1) {
            write("X");  // X^1
        } else {
            write("X^%d", k); // X^k
        }
    }
    write("\n");
    return 0;
}