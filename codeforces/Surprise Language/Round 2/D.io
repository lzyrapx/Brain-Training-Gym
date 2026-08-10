// https://github.com/IoLanguage/io
// https://iolanguage.org/repl/index.html

// 去除去所有的特殊字符
in := File standardInput readLine replaceSeq(" ", "") replaceSeq("\t", "") replaceSeq("\r", "") replaceSeq("\n", "")

solve := method(input,
    if(input size == 0, return "")
    if(input at(0) asCharacter == "\"",
        return input slice(1, input size - 1)
    )
    
    cmd := ""
    for(i, 0, input size - 1,
        if(input at(i) asCharacter == "(", break)
        cmd = cmd .. ((input at(i) | 32) asCharacter)
    )
    
    // concat 
    if(cmd == "concat",
        dep := 0
        spl := 0
        for(i, 0, input size - 1,
            c := input at(i) asCharacter
            if(c == "(", dep = dep + 1)
            if(c == ")", dep = dep - 1)
            if(c == "," and dep == 1, spl = i)
        )
        return solve(input slice(7, spl)) .. solve(input slice(spl + 1, input size - 1))
    )
    
    // reverse
    if(cmd == "reverse",
        res := ""
        str := solve(input slice(8, input size - 1))
        for(i, 0, str size - 1,
            res = res .. (str at(str size - 1 - i) asCharacter)
        )
        return res
    )
    
    // substr
    if(cmd == "substr",
        dep := 0
        sp1 := -1
        sp2 := -1
        sp3 := -1
        for(i, 0, input size - 1,
            c := input at(i) asCharacter
            if(c == "(", dep = dep + 1)
            if(c == ")", dep = dep - 1)
            if(c == "," and dep == 1,
                if(sp1 == -1, sp1 = i,
                if(sp2 == -1, sp2 = i,
                if(sp3 == -1, sp3 = i)))
            )
        )
        if(sp3 >= 0,
            a := (input slice(sp1 + 1, sp2)) asNumber
            b := (input slice(sp2 + 1, sp3)) asNumber
            c := (input slice(sp3 + 1, input size - 1)) asNumber,
            a := (input slice(sp1 + 1, sp2)) asNumber
            b := (input slice(sp2 + 1, input size - 1)) asNumber
            c := 1
        )
        str := solve(input slice(7, sp1))
        res := ""
        i := a
        while(i <= b,
            res = res .. (str at(i - 1) asCharacter)
            i = i + c
        )
        return res
    )
)

"\"" print
solve(in) print
"\"" print