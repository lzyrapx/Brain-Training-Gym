import java.io.*
import java.util.*
import kotlin.math.*
import kotlin.system.*
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter

val dx = intArrayOf(-1, 0, 0, 1)
val dy = intArrayOf(0, -1, 1, 0)
val dir = "NWES"

// 局部 5x5 模拟窗口数据结构，用来计算放置炸弹后的 3 步逃生路径
val tmpGrid = Array(5) { IntArray(5) { -1 } } 
val tmpMove = Array(5) { CharArray(5) { ' ' } }

var n = -1
var m = -1
var grid = arrayOf<CharArray>()

// 出口
var ex = -1
var ey = -1

var vis = arrayOf<BooleanArray>()
var res = mutableListOf<Char>()
var path = mutableListOf<Char>()
var found = false

fun clear() {
    for (arr in tmpGrid) {
        arr.fill(-1)
    }
}

fun check(x: Int, y: Int): Boolean {
    return x in 0 until n && y in 0 until m
}

fun check2(x: Int, y: Int): Boolean {
    return x in 0 until 5 && y in 0 until 5
}

// 找在放炸弹后能到达的所有空地点
fun dfs2(x: Int, y: Int, t: Int, sx: Int, sy: Int) {
    // 将地图坐标 (x, y) 映射到 5x5 窗口坐标 [x - sx + 2][y - sy + 2]
    tmpGrid[x - sx + 2][y - sy + 2] = t
    if (t < 3) { // 炸弹会在 3 次移动后爆炸，所以逃生搜索深度最多为 3
        for (i in 0..3) {
            val x2 = x + dx[i]
            val y2 = y + dy[i]
            val rx = x2 - sx + 2
            val ry = y2 - sy + 2
            if (check(x2, y2) && check2(rx, ry) && tmpGrid[rx][ry] == -1 && grid[x2][y2] != 'X') {
                tmpMove[rx][ry] = dir[i]
                dfs2(x2, y2, t + 1, sx, sy)
            }
        }
    }
}

// 回溯
fun backtrace(x: Int, y: Int): MutableList<Char> {
    if (tmpGrid[x][y] == 0) {
        return mutableListOf()
    }
    // 取得反方向编号（3 - i 得到相反的方向，比如 N <-> S, W <-> E）
    val d = 3 - dir.indexOf(tmpMove[x][y])
    val x2 = x + dx[d]
    val y2 = y + dy[d]
    val ans = backtrace(x2, y2)
    ans.add(tmpMove[x][y])
    return ans
}

// 将逃生路径反转并把每个方向取反，计算爆炸后原路折返回到炸弹点的路径
fun getrev(str: List<Char>): List<Char> {
    return str.reversed().map { c -> dir[3 - dir.indexOf(c)] }
}

fun try_bomb(sx: Int, sy: Int, d: Int): MutableList<Char> {
    clear()
    dfs2(sx, sy, 0, sx, sy)

    // 检查出口 'T' 是否在炸弹 3x3 爆炸范围内，在就不能放炸弹
    for (i in 1..3) {
        for (j in 1..3) {
            val rx = sx + i - 2
            val ry = sy + j - 2
            if (check(rx, ry) && grid[rx][ry] == 'T') {
                return mutableListOf()
            }
        }
    }

    // 在 5x5 窗口边界上找一个可以在 3 步内到的安全逃生点
    var x = -1
    var y = -1
    for (i in 0..4) {
        for (j in 0..4) {
            if (i == 0 || i == 4 || j == 0 || j == 4) {
                if (tmpGrid[i][j] != -1) {
                    x = i
                    y = j
                    break
                }
            }
        }
        if (x != -1) break
    }

    // 没有安全逃生点，不放炸弹
    if (x == -1) {
        return mutableListOf()
    }

    // 炸毁障碍物
    for (i in 1..3) {
        for (j in 1..3) {
            val rx = sx + i - 2
            val ry = sy + j - 2
            if (check(rx, ry) && grid[rx][ry] == 'X') {
                grid[rx][ry] = '.'
            }
        }
    }

    val str = backtrace(x, y) // 逃生路径（<= 3 步）
    val rts = getrev(str)  // 爆炸后原路返回的路径

    val seq = mutableListOf('M') // 放炸弹 'M'
    seq.addAll(str)  // 逃离炸弹

    if (str.size == 1) {  // 至少要 2~3 步才能脱离
        return mutableListOf()
    }

    // 逃生不足 3 步，用 'T' 原地等到第 3 步才爆炸
    seq.addAll(List(3 - str.size) { 'T' }) 

    seq.addAll(rts)  // 爆炸后返回原炸弹点
    seq.add(dir[d])  // 走进刚被炸开的格子
    
    return seq
}

// 不要求路径最短，可以不用撤销，直接炸完就返回...不超过 10w 步就行...
fun dfs(x: Int, y: Int) {
    // if (found) return
    vis[x][y] = true

    // 到出口 T
    if (x == ex && y == ey) {
        res = ArrayList(path)
        // found = true
        // return
    }

    for (i in 0..3) {
        // if (found) return
        val x2 = x + dx[i]
        val y2 = y + dy[i]

        if (check(x2, y2) && !vis[x2][y2]) {
            if (grid[x2][y2] != 'X') {
                // 情况 1：目标格子是空地，直接移动过去
                path.add(dir[i])
                dfs(x2, y2)
                // if (found) return
                path.add(dir[3 - i]) // 回溯
            } else {
                // 情况 2：目标格子是障碍物 'X'，尝试放炸弹炸开它
                val seq = try_bomb(x, y, i)
                if (seq.isNotEmpty()) {
                    path.addAll(seq)
                    dfs(x2, y2)
                    // if (found) return
                    path.add(dir[3 - i])
                }
            }
        }
    }
}

fun solve() {
    n = scanInt()
    m = scanInt()

    // init
    grid = Array(n) { CharArray(m) }
    vis = Array(n) { BooleanArray(m) { false } }
    res = mutableListOf()
    path = mutableListOf()
    found = false

    var sx = -1
    var sy = -1
    ex = -1
    ey = -1

    for (i in 0 until n) {
        val row = scanString()
        for (j in 0 until m) {
            grid[i][j] = row[j]
            if (grid[i][j] == 'E') {  // 人
                sx = i
                sy = j
            } else if (grid[i][j] == 'T') {  // 出口
                ex = i
                ey = j
            }
        }
    }
    
    // out.println("$sx $sy $ex $ey")

    dfs(sx, sy)

    if (res.isEmpty()) {
        out.println("No solution")
    } else {
        out.println(res.joinToString(""))
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