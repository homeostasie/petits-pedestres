package main
import "fmt"

func main() {
    fmt.Println("Début du mooc sur Go")

    var x float64 = 135.2
    var y float64 = 1.352e2


    fmt.Println("Résultat de x-y : ")
    fmt.Println(x-y)


    var i int

    for i=0 ; i<10 ; i++ {
        fmt.Println("Boucle avant break : i=5 : ",i)
        if i == 5 {
            fmt.Println("break : i=5 : ",i)
            break

        }
        fmt.Println("Boucle après break : i=5 : ", i)
    }


    var j int

    for j=0 ; j<10 ; j++ {
        fmt.Println("Boucle avant continue : j=5 : ",j)
        if j == 5 {
            fmt.Println("continue : j=5 : ",j)
            continue
        }
        fmt.Println("Boucle après continue : j=5 : ", j)
    }
}
