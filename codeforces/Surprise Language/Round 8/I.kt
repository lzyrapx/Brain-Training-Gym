import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

class Node(val cost: Long, val a: Int, val b: Int) : Comparable<Node> {
    override fun compareTo(other: Node): Int = this.cost.compareTo(other.cost)
}

fun solve() {
    val h = scanInt()
    val w = scanInt()
    val grid = Array(h) { scanString() }
    val idx = Array(h) { IntArray(w) { -1 } }
    var p = 0

    // 不是桩的位置
    for (x in 0 until h) {
        for (y in 0 until w) {
            if (grid[x][y] != 'X') {
                idx[x][y] = p++
            }
        }
    }

    val n = p
    val dr = intArrayOf(1, 0, -1, 0)
    val dc = intArrayOf(0, 1, 0, -1)
    val dirsUpper = "SENW"  // 大写：人的推货移动
    val dirsLower = "senw"  // 小写：人的普通移动

    // adj[u][d] 表示编号为 u 的格子向 d 方向移动后到达的格子编号（-1 表示出界或墙壁）
    val adj = Array(n) { IntArray(4) { -1 } }
    for (x in 0 until h) {
        for (y in 0 until w) {
            if (idx[x][y] == -1) continue
            val u = idx[x][y]
            for (d in 0 until 4) {
                val nx = x + dr[d]
                val ny = y + dc[d]
                if (nx in 0 until h && ny in 0 until w && idx[nx][ny] != -1) {
                    adj[u][d] = idx[nx][ny]
                }
            }
        }
    }

    var startA = -1
    var startB = -1
    var targetC = -1
    for (x in 0 until h) {
        for (y in 0 until w) {
            if (grid[x][y] == 'Y') startA = idx[x][y]  // 人
            if (grid[x][y] == 'B') startB = idx[x][y]  // 货物
            if (grid[x][y] == 'T') targetC = idx[x][y] // 目的地
        }
    }

    // dp[a][b] 记录人在 a，货物在 b 位置状态下的最小花销
    val dp = Array(n) { LongArray(n) { Long.MAX_VALUE } }

    // par[a][b] 记录到达状态 (a, b) 的上一步移动字符，用来逆向还原整条路径
    val par = Array(n) { CharArray(n) }
    val pq = PriorityQueue<Node>()

    dp[startA][startB] = 0L
    pq.add(Node(0L, startA, startB))

    // 总花销 = 推货次数 * K + 总移动步数
    val cost = 1L shl 30

    // dijkstra 最短路
    while (!pq.isEmpty()) {
        val top = pq.poll()
        val curCost = top.cost
        val curA = top.a  // 人
        val curB = top.b  // 货物

        // 懒删除
        if (curCost != dp[curA][curB]) continue

        // 货物到达目标点，找到最优解，开始还原路径
        if (curB == targetC) {
            out.println("YES")
            val ans = StringBuilder()
            var ca = curA
            var cb = curB
            while (true) {
                val ch = par[ca][cb]
                if (ch == '\u0000') break
                ans.append(ch)
                for (i in 0 until 4) {
                    if (ch == dirsUpper[i]) {  // 推货移动
                        ca = adj[ca][i xor 2]
                        cb = adj[cb][i xor 2]
                    } else if (ch == dirsLower[i]) {  // 普通移动
                        ca = adj[ca][i xor 2]
                    }
                }
            }
            out.println(ans.reverse().toString())
            return
        }

        for (d in 0 until 4) {
            val a1 = adj[curA][d]
            if (a1 == -1) continue // 碰壁
            if (a1 == curB) {
                // 情况 1：人下一步落点是货物所在位置 -> 触发推货
                val b1 = adj[curB][d]
                if (b1 == -1) continue  // 碰壁

                // 花销增加：推货次数+1（增加 cost），总移动步数+1
                val nxtCost = curCost + cost + 1L
                if (nxtCost < dp[a1][b1]) {
                    dp[a1][b1] = nxtCost
                    par[a1][b1] = dirsUpper[d]
                    pq.add(Node(nxtCost, a1, b1))
                }
            } else {
                // 情况 2：人走向空格 -> 普通移动
                // 花销增加：推货次数不变，总移动步数+1
                val nxtCost = curCost + 1L
                if (nxtCost < dp[a1][curB]) {
                    dp[a1][curB] = nxtCost
                    par[a1][curB] = dirsLower[d]
                    pq.add(Node(nxtCost, a1, curB))
                }
            }
        }
    }
    out.println("NO")
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