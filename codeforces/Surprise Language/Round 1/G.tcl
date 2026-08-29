gets stdin domin
set stack {}

foreach rec [split $domin "/"] {
    switch -exact -- $rec {
        "" -
        "." {
            # 忽略空字符和当前目录
        }
        ".." {
            if {[llength $stack] == 0} {
                puts "-1"
                exit
            }
            set stack [lrange $stack 0 end-1]
        }
        default {
            lappend stack $rec
        }
    }
}

puts "/[join $stack /]"