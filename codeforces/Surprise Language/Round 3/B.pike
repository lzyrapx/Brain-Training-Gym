int main() {
    int n;
    sscanf(Stdio.stdin.gets(), "%d", n);
    array(string) p = Stdio.stdin.gets() / ",";
    array(int) x = allocate(n);
    for(int i = 0; i < n; i++){
        sscanf(p[i], "%d", x[i]);
        for(int j = 0; j < i; j++)
        if(x[i] % x[j] != 0 && x[j] % x[i] != 0) {
                write("NOT FRIENDS");
                return 0;
            }
    }
    write("FRIENDS");
    return 0;
}
