import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun solve() {
    val n = scanInt()
    val m = scanInt()
    val p = scanInt()
    var ok = false
    for (a in 1..n) {
        if (p % a == 0) {
            val b = p / a
            if (b <= m) {
                ok = true
                break
            }
        }
    }
    if (ok) out.println("Yes")
    else out.println("No")

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
    val t = readln().toInt()
    // var t = 1
    repeat (t) {
        solve()
    }
    inp.close()
    out.close()
}