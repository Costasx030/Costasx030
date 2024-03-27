package com.sng;

/**
 * Согласно приведенному меню столовой реализуйте методы классов Lunch и Lunch.Builder, имплементировав паттерн Строитель
 * МЕНЮ ДНЯ
 * (ChickenSoup) Куриный суп со шпинатом 100.- В порции 250 гр Ккал: 78 Белков: 3 г Жиров: 6 г Углеводов: 3 г
 * (Ramen) Рамен - суп с лапшой и яйцом 160.- В порции 250 гр Ккал: 201 Белков: 11 г Жиров: 11 г Углеводов: 15 г
 * (PotatoSoup) Картофельный крем-суп Сан-Жермен 120.- В порции 250 гр Ккал: 208 Белков: 6 г Жиров: 11 г Углеводов: 22 г
 * (ChickenMeatball) Куриная котлета с сыром, 1 шт 200.- В порции 120 гр Ккал: 358 Белков: 19 г Жиров: 29 г Углеводов: 7 г
 * (Chakhokhbili) Чахохбили из индейки с хмели-сунели 220.- В порции 250 гр Ккал: 200 Белков: 21 г Жиров: 2 г Углеводов: 24 г
 * (PorkChop) Отбивная из свиной корейки с медовой горчицей 200.- В порции 130 гр Ккал: 282 Белков: 23 г Жиров: 17 г Углеводов: 10 г
 * (PastaWithFish) Паста с красной рыбой и сливками 270.- В порции 250 гр Ккал: 301 Белков: 15 г Жиров: 19 г Углеводов: 17 г
 * (PotatoDraniki) Картофельные драники с грибами 140.- В порции 100 гр Ккал: 602 Белков: 3 г Жиров: 53 г Углеводов: 29 г
 */
@SuppressWarnings("unused")
public class Lunch {

    private final int totalWeight;
    private final long totalKcals;
    private final int cost;


    private Lunch(int totalWeight, long totalKcals, int cost) {
        this.totalWeight = totalWeight;
        this.totalKcals = totalKcals;
        this.cost = cost;
    }

    /**
     * @return общий вес блюд в заказанном обеде
     */
    public int getTotalWeight() {
        return totalWeight;
    }

    /**
     * @return общее количество Ккал всех блюд в заказанном обеде
     */
    public long getTotalKCals() {
        return totalKcals;
    }

    /**
     * @return стоимость обеда
     */
    public int getCost() {
        return cost;
    }

    public static Builder builder() {
        return new Builder();
    }

    /**
     * Реализуйте методы паттерна Строитель для формирования объекта Launch.
     * Реализуйте методы класса Launch.
     */
    public static class Builder {
        private int totalWeight = 0;
        private long totalKCals = 0;
        private int cost = 0;

        public Builder addDish(int cost, int weight, long kCals, int count) {
            this.cost += cost * count;
            this.totalWeight += weight * count;
            this.totalKCals += kCals * count;
            this.cost = Math.max(0, this.cost);
            this.totalWeight = Math.max(0, this.totalWeight);
            this.totalKCals = Math.max(0, this.totalKCals);
            return this;
        }

        public Lunch cook() {
            return new Lunch(totalWeight, totalKCals, cost);
        }

        public Builder addChickenSoup(int count) {
            return addDish(100, 250, 78, count);
        }

        public Builder addRamen(int count) {
            return addDish(160, 250, 201, count);
        }

        public Builder addPotatoSoup(int count) {
            return addDish(120, 250, 208, count);
        }

        public Builder addChickenMeatball(int count) {
            return addDish(200, 120, 358, count);
        }

        public Builder addChakhokhbili(int count) {
            return addDish(220, 250, 200, count);
        }

        public Builder addPorkChop(int count) {
            return addDish(200, 130, 282, count);
        }

        public Builder addPastaWithFish(int count) {
            return addDish(270, 250, 301, count);
        }

        public Builder addPotatoDraniki(int count) {
            return addDish(140, 100, 602, count);
        }

    }
}
