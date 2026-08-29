proc cmp {a b} {
    set scoreA [lindex $a 1]
    set scoreB [lindex $b 1] 
    if {$scoreA < $scoreB} { return 1; }
    if {$scoreA > $scoreB} { return -1; }
    return [string compare [lindex $a 0] [lindex $b 0]];
}
 
proc printTable { place lst } {
    set len [llength $lst];
    if {$len == 1} {
        puts "$place [lindex $lst 0 0]";
        return [expr $place + 1];  
    } else {
        set lastPlace [expr $place + $len - 1];
        foreach item $lst {
            puts "$place-$lastPlace [lindex $item 0 ]";
        } 
        return [expr $lastPlace + 1];
    }
}
 
#main
set n [gets stdin];
set items {};
 
for {set p 0} {$p < $n} {incr p} {
    set items [lappend items [split [gets stdin] { }]];
}
 
set items [lsort -command cmp $items];
 
set score [lindex $items 0 1]
set same {}
set place 1
 
foreach item $items {
    set curScore [lindex $item 1];
    if {$curScore == $score} {
        set same [lappend same $item];
    } else {
        set place [printTable $place $same];
        set same [list $item];
        set score $curScore; 
    }
}
printTable $place $same