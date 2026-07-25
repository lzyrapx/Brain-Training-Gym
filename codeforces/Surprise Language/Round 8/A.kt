import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun solve() {
    val a = scanInt()
    val x = scanInt()
    val y = scanInt()
    if (x > 0 && x < a && y > 0 && y < a) {
        out.println(0)
    } else if (x >= 0 && x <= a && y >= 0 && y <= a) {
        out.println(1)
    } else {
        out.println(2)
    }
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