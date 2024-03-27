import com.sng.Lunch
import spock.lang.Specification

class LunchSpec extends Specification {

    def "1: eat them all"() {
        given:
        def builder = Lunch.builder()
                .addChickenSoup(1)
                .addRamen(1)
                .addPotatoSoup(1)
                .addChickenMeatball(1)
                .addChakhokhbili(1)
                .addPorkChop(1)
                .addPastaWithFish(1)
                .addPotatoDraniki(1)

        when:
        def lunch  = builder.cook()

        then:
        lunch.getCost() == 1410
        lunch.getTotalWeight() == 1600
        lunch.getTotalKCals() == 2230
    }

    def "2: return order part"() {
        given:
        def builder = Lunch.builder()
                .addChickenSoup(1)
                .addPotatoDraniki(1)
                .addPotatoDraniki(-1)

        when:
        def lunch  = builder.cook()

        then:
        lunch.getCost() == 100
    }

    def "3: return full order"() {
        given:
        def builder = Lunch.builder()
                .addChickenSoup(1)
                .addChickenSoup(-1)
                .addPotatoDraniki(1)
                .addPotatoDraniki(1)
                .addPotatoDraniki(-1)
                .addPotatoDraniki(-1)

        when:
        def lunch  = builder.cook()

        then:
        lunch.getCost() == 0
        lunch.getTotalWeight() == 0
        lunch.getTotalKCals() == 0
    }

    def "4: order nothing"() {
        given:
        def builder = Lunch.builder()

        when:
        def lunch  = builder.cook()

        then:
        lunch.getCost() == 0
        lunch.getTotalWeight() == 0
        lunch.getTotalKCals() == 0
    }

    def "5: order kcal"() {
        given:
        def lunch = Lunch.builder()
                .addPastaWithFish(pastaCount)
                .addPorkChop(porkCount)
                .cook()

        expect:
        lunch.getTotalKCals() == expectedTotalKCals

        where:
        pastaCount    |     porkCount   ||   expectedTotalKCals
        1             |     1           ||   301+282
        2             |     2           ||   (301+282)*2
        1000000000    |     1000000000  ||   (301+282)*1000000000L
    }

}
