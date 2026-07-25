import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun solve() {
    val n = scanInt()
    val a = IntArray(n)
    for (i in 0 until n) {
        a[i] = scanInt()
    }
    val ans = ArrayList<Int>()
    for (i in n downTo 1) {
        out.println(a[i - 1])
        out.println(i)
        ans.add(a[i - 1], i)
    }
    for (i in 0 until n) {
        if (i > 0) out.print(" ")
        out.print(ans[i])
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