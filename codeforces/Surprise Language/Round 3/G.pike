int main() {
    string s = Stdio.stdin->gets();

    int n;
    sscanf(s, "%d", n);
    mapping(string:int) dict = ([]);
    for (int i = 0; i < n; i++) {
        s = Stdio.stdin->gets();
        string name;
        int year;
        sscanf(s, "%s %d", name, year);
        dict[name] = year;
    }
    s = Stdio.stdin->gets();
    int m;
    sscanf(s, "%d", m);
    string ans = "";
    int year = 3000;
    for (int i = 0; i < m; i++) {
        s = Stdio.stdin->gets();
        int y = dict[s];
        if (y < year) {
            year = y;
            ans = s;
        } else if (y == year) {
            ans = max(ans, s);
        }
    }
    write(ans + "\n");
    return 0;
}