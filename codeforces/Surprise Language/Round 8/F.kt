import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

fun solve() {
    val s = inp.readLine()
    val tokens = ArrayList<String>()
    var i = 0
    while (i < s.length) {
        val ch = s[i]
        if (ch == '.') {
            tokens.add(".")
            i++
        } else if (ch == ',') {
            tokens.add(",")
            i++
        } else if (ch.isLetter()) {
            val sb = StringBuilder()
            while (i < s.length && s[i].isLetter()) {
                sb.append(s[i])
                i++
            }
            tokens.add(sb.toString())
        } else {
            i++
        }
    }
    val res = StringBuilder()
    var cap = true  // 下一个首字母要大写
    for (k in 0 until tokens.size) {
        val t = tokens[k]
        if (t == ".") {
            res.append(".")
            cap = true
        } else if (t == ",") {
            res.append(",")
        } else {
            if (res.isNotEmpty()) {
                res.append(" ")
            }
            val w = t.lowercase()
            if (cap) {
                res.append(w[0].uppercaseChar())
                res.append(w.substring(1))
                cap = false
            } else {
                res.append(w)
            }
        }
    }
    out.println(res.toString())
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