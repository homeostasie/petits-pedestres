# On est sur la première case.
# On a un grain de blé sur la première case.
# On a un grain de blé sur l'échéquier.

# Nombre de grain de blé par case.
# case est un nombre entier.
case = 1

# Nombre de grain blé au total sur l'échiquier.
# blé est un nombre entier.
ble = 1

# Coefficient d'augmentation du nombre de grain de blé par case.
# coef est un nombre entier
coef = 2

# Il y a 8*8=64 cases sur un échiquier.
# Il nous reste 63 cases à remplir de grain de blé.

# Si on veut connaitre pour toutes les cases.
print("Sur la première case, il y a : ", case, "grains de blé, pour un total de : ", ble , "grains sur l'échiquier.")

# On parcours les 63 cases restantes
for i in range(2,65):
    # Les cases suivantes contienent deux fois plus de grain de blé.
    case = case * coef
    # À chaque fois on rajoute les grains de la case dans le sac de blé.
    ble = ble + case
    # Si on veut connaitre pour toutes les cases.
    print("Sur la case : ", i , " , il y a : ", case, "grains de blé, pour un total de : ", ble , "grains sur l'échiquier.")

print("Nombre de grain de blé sur l'échéquier", ble)
print("Écriture scientifique : ", ble*1.)

# Poids en g. On multiplie le nombre de grain par 0.05g
poids = ble * 0.05

# Poids en tonnes. On divise par 10^6 ou on multiplie par 10^-6
poids = ble * 0.05 * 10**(-6) 
print("Poids du blé total en tonnes : ", poids, " tonnes")

# Le nombre d'année nécéssaire.
# Par an, la production mondiale de blé est : 600 millions.
prod_an = 600 * 10 **6
print("La production annuelle de blé est de ", prod_an, "tonnes de blé")

# Le nombre d'année nécéssaire =
# notre poids de blé sur l'échiquier diviser par la production annuelle.
nombre_an = poids / prod_an
print("Il faudra : ", nombre_an, "années à l'empereur afin de combler ça promesse.")

