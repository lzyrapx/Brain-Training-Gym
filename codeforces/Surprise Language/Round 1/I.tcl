set colums [split [gets stdin]]
set orders [split [gets stdin] ","]

while {[gets stdin line]>=0} {
	lappend list $line
}

foreach i [lreverse $orders] {
    scan $i "%s %s" a b
    if {$b == "ASC"} {
        set list [lsort -index [lsearch $colums $a] -increasing $list]
    } else {
        set list [lsort -index [lsearch $colums $a] -decreasing $list]
    }
    
}

foreach {line} $list {
	puts $line
}