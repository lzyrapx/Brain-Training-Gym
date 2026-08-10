// https://github.com/IoLanguage/io
// https://iolanguage.org/repl/index.html


a := 0
b := 1
for (i, 1, File standardInput readLine asNumber, b = a + b
a = b - a)
b println