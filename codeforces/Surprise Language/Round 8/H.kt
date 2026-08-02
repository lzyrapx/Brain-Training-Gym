import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun solve() {
    val n = scanInt()
    val k = scanLong()
    val a = IntArray(n + 1)
    for (i in 1..n) {
        a[i] = scanInt()
    }
    // 本质上是一个由若干个互不相交的置换环组成的图
    val p = IntArray(n + 1)
    for (i in 1..n) {
        p[a[i]] = i  // a[i] 把书给 i
    }
    val ans = IntArray(n + 1)
    val vis = BooleanArray(n + 1)
    for (i in 1..n) {
        if (!vis[i]) {
            val cyc = ArrayList<Int>()  // 环上所有节点
            var cur = i
            while (!vis[cur]) {
                vis[cur] = true
                cyc.add(cur)
                cur = p[cur]
            }
            val len = cyc.size  // 环长
            val shift = (k % len).toInt()
            for (idx in 0 until len) {
                val tidx = (idx + shift) % len
                ans[cyc[idx]] = cyc[tidx]
            }
        }
    }
    for (i in 1..n) {
        if (i > 1) out.print(" ")
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