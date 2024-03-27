import com.sng.CalculusTasks
import spock.lang.Specification

import static java.lang.Integer.MAX_VALUE
import static java.lang.Integer.MIN_VALUE
import static spock.util.matcher.HamcrestMatchers.closeTo

class CalculusSpec extends Specification {
    def static arr02 = new int[]{0, 1, 2}
    def static veryLongStr = String.join("", Collections.nCopies(10000, "rwxrwxrwx"))
    def "1: simple swap"() {
        given:
        def result = CalculusTasks.swap(i, j, inputArray)


        expect:
        result == expectedRetVal
        (inputArray == null && expectedArray == null) || Arrays.equals(inputArray, expectedArray)

        where:
        inputArray    |  i     |  j   ||   expectedRetVal | expectedArray
        arr02         |  0     |  1   ||   true           | new int[]{1, 0, 2}
        arr02         |  1     |  1   ||   true           | arr02
        arr02         |  2     |  1   ||   false          | arr02
        arr02         |  0     |  5   ||   false          | arr02
        arr02         |  -1    |  2   ||   false          | arr02
        arr02         |  1     |  -2  ||   false          | arr02
        arr02         |  null  |  5   ||   false          | arr02
        new int[]{0}  |  0     |  0   ||   true           | new int[]{0}
        new int[]{}   |  0     |  0   ||   false          | new int[]{}
        null          |  0     |  0   ||   false          | null
    }

    def "2: min3"() {
        given:
        def result = CalculusTasks.min3(a, b, c)

        expect:
        result == expectedRetVal

        where:
        a  |   b |  c   ||   expectedRetVal
        1  |   2 |  3   ||   1
        -1 |  -2 | -3   ||   -3
        1  |   0 |  3   ||   0
    }

    def "3: sum2"() {
        given:
        def result = CalculusTasks.sum2(a, b)

        expect:
        result == expectedRetVal

        where:
        a         |   b     ||   expectedRetVal
        1         |   2     ||   3
        100500    |   -1    ||   100499
        MAX_VALUE |   1     ||   null
        MAX_VALUE |   -1    ||   MAX_VALUE-1
        MIN_VALUE |   -1    ||   null
    }

    def "4: div2"() {
        given:
        def result = CalculusTasks.div2(a as Double, b)

        expect:
        result as double closeTo(expectedRetVal, 0.01d)

        where:
        a      |   b      ||   expectedRetVal
        1.5    |   2.4    ||   0.625d
        -1.5   |   2.4    ||   -0.625d
        0      |   2.4    ||   0d
        null   |   -1.0   ||   0d
    }

    def "4.1: div2 null"() {
        given:
        def result = CalculusTasks.div2(a, b)

        expect:
        result == expectedRetVal

        where:
        a                        |   b        ||   expectedRetVal
        Double.POSITIVE_INFINITY |   2        ||   null
        1/0.0d                   |   null     ||   null
    }

    def "5: avg"() {
        given:
        def result = CalculusTasks.avg(a, b)

        expect:
        result as double closeTo(expectedRetVal, error)

        where:
        a         |   b                               | error ||   expectedRetVal
        15        |   new int[]{20, -5}               | 0.1   ||   10d
        15        |   new int[]{0}                    | 0.1   ||   7.5d
        15        |   null                            | 0.1   ||   15d
        16        |   new int[]{MAX_VALUE, 4, 8}      | 0.1   ||   536870918.75d
        MAX_VALUE |   new int[]{MAX_VALUE}            | 1.0   ||   MAX_VALUE
        MAX_VALUE |   new int[]{MAX_VALUE, MAX_VALUE} | 1.0   ||   MAX_VALUE
    }

    def "6: sumN"() {
        given:
        def result = CalculusTasks.sumN(a, b)

        expect:
        result == expectedRetVal

        where:
        a           |   b                     ||  expectedRetVal
        4           |   new int[]{5, 7}       ||  16
        4           |   new int[]{}           ||  4
        54          |   null                  ||  54
        MAX_VALUE   |   null                  ||  MAX_VALUE
        MAX_VALUE   |   new int[] {1}         ||  null
        MAX_VALUE   |   new int[] {-1}        ||  MAX_VALUE-1
        MAX_VALUE   |   new int[] {1, -1}     ||  MAX_VALUE
        MIN_VALUE   |   new int[] {-1}        ||  null
        MAX_VALUE   |   new int[] {MIN_VALUE} ||  -1
    }

    def "6.1: sumN big and small"() {
        given:
        def arrOfSmallDoubles = new double[5_000_000]
        Arrays.fill(arrOfSmallDoubles,  0.0000001d)

        when:
        def result = CalculusTasks.sumN(1234567890, arrOfSmallDoubles)

        then:
        result closeTo(1234567890.5d, 0.00001d)
    }

    def "7: rwx"() {
        given:
        def result = CalculusTasks.rwx(rwxStr)


        expect:
        result == expectedRetVal

        where:
        rwxStr       ||  expectedRetVal
        "rw-r--r--"  ||  644
        "rwxr--r--"  ||  744
        "rwxrwxrwx"  ||  777
        "r--------"  ||  400
        "r---w---x"  ||  421
        "rwx-w---x"  ||  721
        "------rwx"  ||  007
        "xwr-w---x"  ||  null
        "rwr-w---x"  ||  null
        "rwx-w-x--"  ||  null
        "rwx-w-x-"   ||  null
        " rwx-w-x--" ||  null
        "         "  ||  null
        "rwxrwxrw "  ||  null
        ""           ||  null
        null         ||  null
        veryLongStr  ||  null
    }

    def "8: bit mask"() {
        given:
        def result = CalculusTasks.checkMask(value, mask)

        expect:
        result == expectedRetVal

        where:
        value                   |   mask                        ||  expectedRetVal
        CalculusTasks.MASK_READ |   CalculusTasks.MASK_READ     ||  true
        1                       |   CalculusTasks.MASK_READ     ||  true
        7                       |   CalculusTasks.MASK_READ     ||  true
        0x111                   |   CalculusTasks.MASK_EXEC     ||  true
        0b10001                 |   CalculusTasks.MASK_WRITE    ||  true
        0b100010001             |   CalculusTasks.MASK_EXEC     ||  true
        0b100010001             |   CalculusTasks.MASK_READ     ||  true
        CalculusTasks.MASK_EXEC |   CalculusTasks.MASK_READ     ||  false
        CalculusTasks.MASK_READ |   CalculusTasks.MASK_WRITE    ||  false
        0x001                   |   CalculusTasks.MASK_WRITE    ||  false
    }

    def "9: can modify"() {
        given:
        def result = CalculusTasks.canModify(from, to)

        expect:
        result == expectedRetVal

        where:
        from        |   to      ||  expectedRetVal
        "cat"       | "dog"     || false
        "cat"       | "acts"    || false
        "cat"       | "cats"    || true
        "cat"       | "cast"    || true
        "cat"       | "at"      || true
        "cat"       | "cut"     || true
    }


}
