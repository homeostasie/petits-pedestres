package main
import (
    "fmt"
    "sort"
    "strconv"
)


func main() {
    fmt.Println("Pour la semaine 3")

    var inScan string
    var nbScan int

    fmt.Println("Scan d'un entier :", nbScan)
    fmt.Scan(&inScan)

    var sli = make([]int, 0)


    for inScan != "x"  {
        nbScan,_ = strconv.Atoi(inScan)
        fmt.Println("Scan d'un entier :", nbScan)

        sli = append(sli, nbScan)
        fmt.Println("Affiche slice d'entier :", sli)

        sort.Ints(sli)
        fmt.Println("Affiche slice ordonnée des entiers :", sli)

        fmt.Scan(&inScan)
    }   
    
}
