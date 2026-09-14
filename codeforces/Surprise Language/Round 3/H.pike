int main() {
    int n = (int)Stdio.stdin->gets();
    while (n--) {
        array(string) board = allocate(10);
        for (int i = 0; i < 10; i++) {
            board[i] = Stdio.stdin->gets();
        }
        bool flag = true;
        for (int i = 0; i < 9 && flag; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '*' && board[i + 1][j + 1] == '*') {
                    flag = false;
                    break;
                }
                if (board[i + 1][j] == '*' && board[i][j + 1] == '*') {
                    flag = false;
                    break;
                }
            }
        }
        array(int) count = allocate(5);
        for (int i = 0; i < 10 && flag; i++) {
            for (int j = 0; j < 10; ++j) {
                if (board[i][j] == '*') {
                    int h, v;
                    for (h = j; h < 10; h++) {
                        if (board[i][h] != '*') {
                            break;
                        }
                        board[i][h] = '0';
                    }
                    h -= j;
                    board[i][j] = '*';
                    for (v = i; v < 10; v++) {
                        if (board[v][j] != '*') {
                            break;
                        }
                        board[v][j] = '0';
                    }
                    v -= i;
                    if (h > 1 && v > 1) {
                        flag = false;
                        break;
                    }
                    if (max(h, v) > 4) {
                        flag = false;
                        break;
                    }
                    count[max(h, v)]++;
                }
            }
        }
        if (flag && count[4] == 1 && count[3] == 2
                 && count[2] == 3 && count[4] == 1) {
            write("YES\n");
        } else {
            write("NO\n");
        }
        Stdio.stdin->gets();
    }
    return 0;
}
