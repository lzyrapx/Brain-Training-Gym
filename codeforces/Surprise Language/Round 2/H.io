// https://github.com/IoLanguage/io
// https://iolanguage.org/repl/index.html

s := File standardInput readLine
if(s at(0) == 45, "-" print)
s strip("-0") reverse print