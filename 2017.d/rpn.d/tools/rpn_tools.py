# Importation des modules
import sys 
sys.path.insert(0,'src')
import rpn_list4_calc as calc


# Essai interface

pessai = calc.list4()

registre = "0"
while (registre !=  "q" and registre != "x"):
	regt = registre.split(" ")

	if regt[0] == "s":
		pessai.swap()
	elif regt[0] == "h":
		pessai.fhaut()
	elif regt[0] == "b":
		pessai.fbas()
		
	elif regt[0] == "+":
		pessai.additioner()
	elif regt[0] == "-":
		pessai.soustraire()
	elif regt[0] == "*":
		pessai.multiplier()
	elif regt[0] == "/":
		pessai.diviser()
		
	else :
		nb = float(regt[0])
		pessai.empile(nb)
			
	pessai.affiche()
	registre = input('Registre : ')
