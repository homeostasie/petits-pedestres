package main

import (
    "fmt"
    "encoding/json"    
)

func main() {
	var Personne = make(map[string]string)

	var monNom string
	var monAdresse string

	fmt.Println("Votre nom ?")
	fmt.Scanln(&monNom)

	fmt.Println("Votre addresse ?")
	fmt.Scanln(&monAdresse)


	Personne["Nom"] = monNom
	Personne["Addresse"] = monAdresse


	json, err := json.MarshalIndent(Personne, "", "\t")

	if err != nil {
		fmt.Println(err)
	}

	fmt.Println(string(json))
}