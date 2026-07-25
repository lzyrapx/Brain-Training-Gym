import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

class Pupil(val name: String, val height: Int)

fun solve() {
    val n = scanInt()
    val list = ArrayList<Pupil>(n)
    for (i in 0 until n) {
        val name = scanString()
        val h = scanInt()
        list.add(Pupil(name, h))
    }
    list.sortBy { it.height }
    for (p in list) {
        out.println(p.name)
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