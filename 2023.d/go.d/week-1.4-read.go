package main

import "fmt"
import "io/ioutil"
import "strings"

type Names struct {
	fname string
	lname  string
}


func main() {
	var filename string
	fmt.Printf("Enter the file name : ")
	fmt.Scan(&filename)

	sli := make([]Names, 0)

	data, _ := ioutil.ReadFile(filename)

	lignes := strings.Split(string(data), "\n")

	for i := 0; i < len(lignes); i = i + 1 {
		res := strings.Split(lignes[i], " ")

		var idPersonne Names

		idPersonne.fname = res[0]
		idPersonne.lname = res[1]

		sli = append(sli, idPersonne)
	}

	for i := 0; i < len(sli); i = i + 1 {

		fmt.Printf("First Name : %s, Last Name : %s\n", sli[i].fname, sli[i].lname)
		
	}
}