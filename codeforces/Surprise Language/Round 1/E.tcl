proc isPrime {n} {
    for {set i 2} {[expr $i * $i] <= $n} {incr i} { if {[expr $n % $i] == 0} { return false; } }
    return true; 
}
 
proc upperPrime {n} {
    if {[isPrime $n]} { return $n; }
    return [upperPrime [expr $n + 1]];
}
 
proc lowerPrime {n} {
    if {[isPrime $n]} { return $n; }
    return [lowerPrime [expr $n - 1]];
}
 
set input [gets stdin]
scan $input "%d" n
puts [list [lowerPrime $n] [upperPrime $n]]