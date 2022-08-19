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

fun sol(dist: Int, arr: List<Int>, C: Int): Int {
    var ret = 1000000000
    var prev = arr.first()
    var cnt = 1
    for (x in arr) {
        if (x == arr.first()) continue
        if (cnt >= C) break;
        if (x - prev >= dist) {
            ret = ret.coerceAtMost(x - prev)
            prev = x
            cnt++
        }
    }
    if (cnt < C) return -1

    return ret
}

fun main() {
    val (N, C) = readInts(2);
    val v = readInts(N).sorted()
    var l = 0;
    var r = 1000000002
    var ans = 0
    while (l <= r) {
        val mid = (l + r) / 2
        val result = sol(mid, v, C)
        if (result == -1) {
            r = mid - 1
        } else {
            ans = ans.coerceAtLeast(result)
            l = mid + 1
        }
    }
    print(ans)
}