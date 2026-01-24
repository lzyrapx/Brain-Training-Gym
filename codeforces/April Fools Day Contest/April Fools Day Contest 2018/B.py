#coding: utf-8
import sys

def main():
    flag = 0
    for num in range(0,10):
        print(num)
        sys.stdout.flush()
        s = input()
        if(s in ['cool', 'not bad', "don't think so", "don't touch me!", "don't touch me", "great", "great!"]):
            print("normal")
            sys.stdout.flush();flag = 1
            break
        if(s in ['worse', 'terrible', 'are you serious?', 'are you serious', 'go die in a hole', "don't even",'no way']):
            print("grumpy")
            sys.stdout.flush();flag = 1
            break
        sys.stdout.flush()
    if flag == 0:
        print ("grumpy")
        
if __name__ =="__main__":
    main()