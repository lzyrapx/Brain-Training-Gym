gets stdin line
set cnt [regexp -all {[a-z0-9\.]} $line]
set len [string length $line]
if {$cnt < $len} {
    puts "NO"
    exit 0
}
 
set fchar [string index $line 0]
set lchar [string index $line [expr $len - 1]]
if {$fchar == "."} {
    puts "NO"
    exit 0
}

if {$lchar == "."} {
    puts "NO"
    exit 0
}

set pos [string first ".." $line]
if {$pos >= 0} {
    puts "NO"
    exit 0
}
 
set a [split $line "."]
set dom [lindex $a [expr [llength $a] - 1]]
set domlen [string length $dom]

if {$domlen > 3} {
    puts "NO"
    exit 0
}

if {$domlen < 2} {
    puts "NO"
    exit 0
}
puts "YES"