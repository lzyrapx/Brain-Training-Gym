// https://github.com/IoLanguage/io
// https://iolanguage.org/repl/index.html


data := Map clone
key := ""
data atPut(key, Map clone)
File standardInput readLines foreach (i, line,
    if (i > 0,
        line = line strip
        if (line at(0) == 59,  // ";"
            continue
        )
        if (line at(0) == 91,  // "["
            key = line strip("[ ]")
            data atIfAbsentPut(key, Map clone),
            kv := line split("=")
            data at(key) atPut (kv at(0) strip, kv at(1) strip)
        )
    )
)
data keys sort foreach(key,
    if (key != "",
        ("[" .. key .. "]") println
    )
    subs := data at(key)
    subs keys sort foreach (sub,
        (sub .. "=" .. subs at(sub)) println
    )
)