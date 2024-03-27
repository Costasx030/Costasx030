package com.sng;

@SuppressWarnings("unused")
public class CalculusTasks {

    /**
     * Реализуйте метод, меняющий местами элементы по индексам i и j в массиве anArray и
     * возвращающий false, если невозможно выполнить данную операцию. Индекс j нестрого больше i.
     */
    public static boolean swap(Integer i, int j, int[] anArray) {
        if (i == null || anArray == null || i < 0 || j >= anArray.length || j < i) return false;
        var temp = anArray[i];
        anArray[i] = anArray[j];
        anArray[j] = temp;
        return true;

    }

    /**
     * @return минимальный из трех аргументов, не используя функции стандартной библиотеки
     */
    public static int min3(int a, int b, int c) {


        if (a > b) {
            if (a <= c)
                return b;
            else if (b >= c)
                return c;
        } else {
            if (a <= c)
                return a;
        }
        return c;
    }

    /**
     * @return сумму двух аргументов или null если невозможно подсчитать сумму корректно
     * с математической точки зрения. Реализация не должна использовать функции стандартной библиотеки.
     */
    public static Integer sum2(int a, int b) {

        if (a > 0 && b > 0 && Integer.MAX_VALUE - a < b) {
            return null;
        }
        if (a < 0 && b < 0 && Integer.MIN_VALUE - a > b) {
            return null; // Переполнение
        }
        return a + b;
    }


    /**
     * Возвращает отношение двух аргументов, считая null аргумент как 0.
     *
     * @return a/b или null если результат выполнения операции
     * не является вещественным числом.
     */
    public static Double div2(Double a, Double b) {
        if (a == null) a = 0.0;
        if (b == null) return null;
        double c = a / b;
        if (!Double.isFinite(c)) return null;

        return c;


    }

    /**
     * Вычисляет сумму a0 и всех элементов массива ai или null, если это сделать невозможно.
     * Если ai пустой, то считаем сумму ai равной нулю.
     *
     * @param a0 - первый аргумент последовательности
     * @param ai - массив остальных аргументов
     * @return сумма всех аргументов
     */
    public static Integer sumN(int a0, int... ai) {

        long sum = a0;
        if (ai != null) {
            for (var a : ai)
                sum += a;
        }
        if (sum < Integer.MIN_VALUE || sum > Integer.MAX_VALUE) return null;
        return (int) sum;

    }

    /**
     * Вычисляет сумму a0 и всех элементов массива ai или null, если это сделать невозможно.
     * Если ai пустой, то считаем сумму ai равной нулю.
     *
     * @param a0 - первый аргумент последовательности
     * @param ai - массив остальных аргументов
     * @return сумма всех аргументов
     */
    public static Double sumN(double a0, double... ai) {

        double sum = 0.000000000;
        if (ai != null) {
            for (var a : ai)
                sum += a;
        }
        sum += a0;
        if (!Double.isFinite(sum)) return null;
        return sum;
    }

    /**
     * Вычисляет среднее между всеми аргументами функции или вернет null если результат
     * не является вещественным числом.
     *
     * @param a0 - первый аргумент последовательности
     * @param ai - массив остальных аргументов
     * @return среднее всех аргументов
     */
    public static Double avg(int a0, int... ai) {
        double avg = a0;
        if (ai != null) {
            for (var a : ai) {
                avg += a;
            }
            avg = avg / (ai.length + 1);
        }
        if (!Double.isFinite(avg)) return null;
        return avg;

    }

    /**
     * Возвращает число, которое соответствует запрошенным правам в команде `chmod`
     * в unix подобных операционных системах.
     *
     * @param unixAccess строка в формате `rwxrwxrwx`, где любой символ может
     *                   быть заменен на `-`, что означает отсутствие данного права
     * @return числовое представление прав доступа или null, если преобразование выполнить невозможно
     * Пример работы: на входе `rwxrw-r--` на выходе число 764
     */


    public static Integer rwx(String unixAccess) {

        //      throw new UnsupportedOperationException("not implemented yet");
        if (unixAccess == null || !unixAccess.matches("^[r-][w-][x-][r-][w-][x-][r-][w-][x-]$")) {
            return null;
        }
        int rwx = 0;
        for (int i = 0; i < 3; i++) {
            int value = 0;
            for (int j = 0; j < 3; j++) {
                char permission = unixAccess.charAt(i * 3 + j);
                switch (permission) {
                    case 'r' -> value += 4; // Ставим бит чтения

                    case 'w' -> value += 2; // Ставим бит записи

                    case 'x' -> value += 1; // Ставим бит выполнения

                    case '-' -> {
                    }
                    default -> {
                        return null; // Некорректный символ
                    }
                }
            }
            rwx = rwx * 10 + value;
        }


        return rwx;
    }

    public static final int MASK_READ = 0x0001;
    public static final int MASK_WRITE = 0x0010;
    public static final int MASK_EXEC = 0x0100;

    /**
     * Проверяет, соответствует ли переданное значение битовой маске
     *
     * @param aValue проверяемое значение
     * @param aMask  битовая маска
     *               Корректные маски {@value MASK_READ}, {@value MASK_WRITE}, {@value MASK_EXEC}
     */
    public static boolean checkMask(int aValue, int aMask) {

        return (aValue & aMask) == aMask;
    }

    /**
     * Напишите функцию, проверяющую, можно ли из одной строки получить вторую
     * изменением только одного символа. Под модификацией (изменением) понимается -
     * замена символа другим, вставка символа, удаление символа. Сложность алгоритма
     * не должна превышать O(n).
     * Примеры работы функции:
     * canModify("cat", "cats") -> true
     * canModify("cat", "acts") -> false
     */
    public static boolean canModify(String from, String to) {
        if (from.equals(to) || Math.abs(from.length() - to.length()) > 1) {
            return false;
        }

        int i = 0, j = 0, mismatches = 0;

        while (i < from.length() && j < to.length()) {
            if (from.charAt(i) != to.charAt(j)) {
                // Если уже было несоответствие, то больше одного изменения не допускается
                if (++mismatches > 1) return false;

                // Если одна строка длиннее, пропускаем символ в более длинной строке
                if (from.length() > to.length()) {
                    i++;
                    continue;
                } else if (from.length() < to.length()) {
                    j++;
                    continue;
                }
            }
            i++;
            j++; // Перемещаемся дальше по обеим строкам
        }

        // Учитываем возможность вставки/удаления последнего символа
        return mismatches == 1 || Math.abs(from.length() - to.length()) == 1;
    }
}

