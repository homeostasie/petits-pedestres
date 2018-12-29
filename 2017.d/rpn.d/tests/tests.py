# Importation des modules
import sys 
sys.path.insert(0,'src')
import rpn_list4_calc as calc



# Initialisation	
print("----- init et affichage -----")

pessai = calc.list4()
print(pessai.list4)
pessai.affiche()

# Empiler
print("----- empiler -----")
pessai.affiche()

pessai.empile(12)
pessai.affiche()

pessai.empile(13)
pessai.affiche()

pessai.empile(14)
pessai.affiche()

pessai.empile(15)
pessai.affiche()

pessai.empile(17)
pessai.affiche()


#depiler
print("----- depiler -----")
pessai.affiche()

pessai.depile()
pessai.affiche()

pessai.depile()
pessai.affiche()

pessai.depile()
pessai.affiche()
