package main
import (
    "fmt"
    "strconv"
    "strings"
)

func tronquer( nombre float64 ) (nbInt int64){
    fmt.Println("Tronquer: ",nombre)

    var nbString string = fmt.Sprintf("%f", nombre)

    var i int
    
    for i = 0; i < len(nbString) && nbString[i] != '.' ; i++ {}

    var intString string = nbString[0:i]
    nbInt, _ = strconv.ParseInt(intString, 10, 0)
    
    return

}

func testString( mot string ){
    
    if mot[0] == 'i' {
        fmt.Println("commence avec i")
    }

    if mot[len(mot)-1] == 'n' {
        fmt.Println("fini avec n")
    }

    if strings.Contains(mot,"a") {
        fmt.Println("avec a")
    }
}


func main() {
    fmt.Println("Pour la semaine 2")

    /*
    var nbScan float64

    fmt.Scan(&nbScan)
    
    fmt.Println("Scan de nombre :", nbScan)
    */


    var nbFloat float64 = 128.5
    nbInt := tronquer(nbFloat)
    fmt.Println(nbInt)
    // on pouvait aussi faire : 

    var resultat2 = int(nbFloat)
    fmt.Println(resultat2)

   
    var chScan string

    fmt.Scan(&chScan)
    
    fmt.Println("Scan un mot :", chScan)
    fmt.Println(chScan)
    testString(chScan)

    fmt.Println("median")
    testString("median")

    fmt.Println("irrmedian")
    testString("irrmedian")
}
