import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun solve() {
    val n = scanInt()
    val set1 = HashSet<Int>()
    for (i in 0 until n) {
        set1.add(scanInt())
    }
    val m = scanInt()
    val set2 = HashSet<Int>()
    for (i in 0 until m) {
        set2.add(scanInt())
    }
    val res = ArrayList<Int>()
    for (x in set1) {
        if (!set2.contains(x)) {
            res.add(x)
        }
    }
    for (x in set2) {
        if (!set1.contains(x)) {
            res.add(x)
        }
    }
    res.sort()
    out.print(res.size)
    for (v in res) {
        out.print(" $v")
    }
    out.println()
}

fun scanInt(): Int {
    return scanString().toInt()
}

fun scanLong(): Long {
    return scanString().toLong()
}

fun scanString(): String {
    var t = tok
    while (t == null || !t.hasMoreTokens()) {
        t = StringTokenizer(inp.readLine())
        tok = t
    }
    return t.nextToken()
}

val inp = BufferedReader(InputStreamReader(System.`in`))
val out = PrintWriter(System.out)
var tok: StringTokenizer? = null

fun main() {
    // val t = readln().toInt()
    var t = 1
    repeat (t) {
        solve()
    }
    inp.close()
    out.close()
}