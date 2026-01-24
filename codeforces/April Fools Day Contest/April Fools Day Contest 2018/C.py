#coding: utf-8

import sys

def main():
    n = int(input())
    a = [int(i) for i in input().split()]
    if(n == 1):
        print("YES")
    else:
        flag = 1
        while len(a) > 1:
            Len = len(a)
            # print  Len
            for i in range(0,Len - 1):
                if (a[i] - a[i+1] > 1 or a[i+1] - a[i] > 1):
                    flag = 0
            if flag == 0: 
                break
            idx = max(a)
            # print idx
            now = a.index(idx)
            a.pop(now)
            
        if flag == 1:
            print("YES")
        else:
            print("NO")

if __name__ =="__main__":
    main()