import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun gcd(a: Long, b: Long): Long {
    var x = a
    var y = b
    while (y != 0L) {
        val t = x % y
        x = y
        y = t
    }
    return x
}

fun pow10(n: Int): Long {
    var res = 1L
    repeat(n) { res *= 10L }
    return res
}

fun solve() {
    val s = scanString()
    val dot = s.indexOf('.')
    val open = s.indexOf('(')
    val close = s.indexOf(')')
    
    val a = s.substring(dot + 1, open)
    val b = s.substring(open + 1, close)  // 循环节长度

    val k = a.length
    val m = b.length
    
    // a 可能是空
    val va = if (a.isEmpty()) 0L else a.toLong()
    val vab = (a + b).toLong()

    val num = vab - va
    val den = pow10(k + m) - pow10(k)
    val g = gcd(num, den)
    out.println("${num / g}/${den / g}")
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