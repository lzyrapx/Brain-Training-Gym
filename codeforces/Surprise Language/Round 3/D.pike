int main() {
    string s;
    int n;
    string a, b;
    
    s = Stdio.stdin->gets();
    sscanf(s, "%d", n);
    a = Stdio.stdin->gets();
    b = Stdio.stdin->gets();
    
    int an = sizeof(a), bn = sizeof(b);
    
    int i = 0;
    for (i = 0; i < an && i < bn; i++) {
        if (a[i] != b[i]) break;
    }
    
    int need = (an - i) + (bn - i);
    write((need <= n) ? "Yes\n" : "No\n");
    
    return 0;
}