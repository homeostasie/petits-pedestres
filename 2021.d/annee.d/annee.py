# Fonction pour définir si oui ou non l'année est bissextile
def bissextile(annee) :
    if (annee % 4 ==0 and annee % 100 != 0) or annee % 400 == 0 :
        return True
    return False

def jour_mois(mois, annee) :
    if (bissextile(annee)) :
        jour = [31, 29, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31]
        return (jour[mois - 1])
    else :
        jour = [31, 28, 31, 30 , 31, 30, 31, 31, 30, 31, 30, 31]
        return (jour[mois - 1])


def affiche_jour(mois, annee) : 
    if (bissextile(annee)) :
        est_bissextile = " est bissextile"
    else :    
        est_bissextile = " n'est pas bissextile"
    jour = str(jour_mois(mois, annee))


    print("Le mois numéro: " + str(mois) + " possède " + jour + " jours et l année" + est_bissextile)


annee = int(input("Choissisez une année : "))
mois = int(input("Choissisez un mois : "))

affiche_jour(mois, annee)