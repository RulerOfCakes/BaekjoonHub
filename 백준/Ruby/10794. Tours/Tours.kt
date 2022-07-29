import java.io.PrintWriter
import java.util.*

@JvmField
val INPUT = System.`in`

@JvmField
val OUTPUT = System.out

@JvmField
val _reader = INPUT.bufferedReader()
val _writer = PrintWriter(OUTPUT, false)
fun readLine(): String = _reader.readLine()
fun readLn() = _reader.readLine()!!

@JvmField
var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}

fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

val adj = Array<MutableList<Int>>(2020) { emptyArray<Int>().toMutableList() }
val l = Array<Int>(2020) { 0 }
val edges = emptyArray<Pair<Int, Int>>().toMutableList()
var badEdges = emptyArray<Pair<Int, Int>>().toMutableList()
var bad = 0
var cnt = 0
var findEnabled = true
fun dfs(cx: Int, prt: Int): Int {
    l[cx] = ++cnt
    var ret = l[cx]

    for (nx in adj[cx]) {
        if (nx == prt) continue
        if (l[nx] == 0) {
            val low = dfs(nx, cx)
            if (low > l[cx]) {
                if (findEnabled) {
                    val cp = cx.coerceAtMost(nx) to nx.coerceAtLeast(cx)
                    badEdges.add(cp)
                }
                bad++
                // bad.add(cx.coerceAtMost(nx) to nx.coerceAtLeast(cx))
            }
            ret = ret.coerceAtMost(low)
        } else {
            ret = ret.coerceAtMost(l[nx])
        }
    }
    return ret
}

tailrec fun gcd(a: Int, b: Int): Int {
    if (b == 0) return a.coerceAtLeast(1)
    return gcd(b, a % b)
}

fun main() {
    val (N, M) = readInts(2);
    repeat(M) {
        val (a, b) = readInts(2);
        adj[a].add(b);
        adj[b].add(a);
        edges.add(a.coerceAtMost(b) to b.coerceAtLeast(a))
    }
    for (i in 1..N) {
        if (l[i] == 0) dfs(i, 0)
    }
    // dfs(1, 0);
    for ((a, b) in badEdges) {
        edges.remove(a to b)
        adj[a].remove(b)
        adj[b].remove(a)
    }
    var ans = 0
    findEnabled = false
    for ((a, b) in edges) {
        l.fill(0)
        bad = 1
        cnt = 0
        adj[a].remove(b);
        adj[b].remove(a);
        for (i in 1..N) {
            if (l[i] == 0) dfs(i, 0)
        }
        if (ans == 0) {
            ans = bad
        } else {
            ans = gcd(ans, bad)
        }
        adj[a].add(b);
        adj[b].add(a)
    }

    for (i in 1..ans) {
        if (ans % i == 0) _writer.print("$i ")
    }
    _writer.flush()
}