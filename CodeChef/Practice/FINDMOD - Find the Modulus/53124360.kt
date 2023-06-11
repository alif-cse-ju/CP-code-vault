import java.io.BufferedInputStream
import java.lang.IllegalArgumentException
const val LIMIT = 1000000000000000000L
fun main(omkar: Array<String>) {
    val jin = FastScanner()
    repeat(jin.nextInt(100)) {
        fun query(x: Long): Long {
            println("? $x")
            val res = jin.nextLong(true)
            if (res !in 0L until LIMIT) {
                throw IllegalArgumentException("query result $res not in range 0 until 10^18")
            }
            return res
        }
        val x1 = LIMIT + 3L
        val y1 = query(x1)
        if (y1 == 0L) {
            println("! 1")
        } else {
            val z1 = x1 - y1
            val x2 = z1 - y1
            val y2 = query(x2)
            val answer = y1 + y2
            println("! $answer")
        }
    }
}
class FastScanner {
    private val BS = 1 shl 16
    private val NC = 0.toChar()
    private val buf = ByteArray(BS)
    private var bId = 0
    private var size = 0
    private var c = NC
    private var `in`: BufferedInputStream? = null
    constructor() {
        `in` = BufferedInputStream(System.`in`, BS)
    }
    private val char: Char
        private get() {
            while (bId == size) {
                size = try {
                    `in`!!.read(buf)
                } catch (e: Exception) {
                    return NC
                }
                if (size == -1) return NC
                bId = 0
            }
            return buf[bId++].toChar()
        }
    fun assureInputDone() {
        if (char != NC) {
            throw IllegalArgumentException("excessive input")
        }
    }
    fun nextInt(endsLine: Boolean): Int {
        var neg = false
        c = char
        if (c !in '0'..'9' && c != '-' && c != ' ' && c != '\n') {
            throw IllegalArgumentException("found character other than digit, negative sign, space, and newline)
        }
        if (c == '-') {
            neg = true
            c = char
        }
        var res = 0
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0')
            c = char
        }
        if (endsLine) {
            if (c != '\n') {
                throw IllegalArgumentException("found character other than newline")
            }
        } else {
            if (c != ' ') {
                throw IllegalArgumentException("found character other than space")
            }
        }
        return if (neg) -res else res
    }
    fun nextInt(from: Int, to: Int, endsLine: Boolean = true): Int {
        val res = nextInt(endsLine)
        if (res !in from..to) {
            throw IllegalArgumentException("$res not in range $from..$to")
        }
        return res
    }
    fun nextInt(to: Int, endsLine: Boolean = true) = nextInt(1, to, endsLine)
    fun nextLong(endsLine: Boolean): Long {
        var neg = false
        c = char
        if (c !in '0'..'9' && c != '-' && c != ' ' && c != '\n') {
            throw IllegalArgumentException("found character other than digit, negative sign, space, and newline, character code = )
        }
        if (c == '-') {
            neg = true
            c = char
        }
        var res = 0L
        while (c in '0'..'9') {
            res = (res shl 3) + (res shl 1) + (c - '0').toLong()
            c = char
        }
        if (endsLine) {
            if (c != '\n') {
                throw IllegalArgumentException("found character other than newline")
            }
        } else {
            if (c != ' ') {
                throw IllegalArgumentException("found character other than space")
            }
        }
        return if (neg) -res else res
    }
}