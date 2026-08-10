// https://github.com/IoLanguage/io
// https://iolanguage.org/repl/index.html

n := File standardInput readLine asNumber
 
odd := List clone
even := List clone
 
for(i, 1, n, 
    if((i % 2 == 0) and (n % i == 0),
        even append(i / n)
    )
    if((i % 2 == 1) and (n % i == 0),
        odd append(i / n)
    )
)
 
if(even size == odd size, 
    "yes" println
,
    "no" println
)
