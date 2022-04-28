# importation des donnees

# création des tableaux
# lignes les notes d'une même personne
# deux colonnes de notes : pre et post 
data.fgsm3 = read.csv("data.fgsm3.csv", header=TRUE, sep=",")
data.eleves = read.csv("data.eleves.csv", header=TRUE, sep=",")

# packages à charger
# install.packages("ggpubr")
library(ggpubr)

# les effectifs des groupes
nb.fgsm3 = length(data.fgsm3$pre)
nb.eleves = length(data.eleves$pre)
nb.total = nb.eleves + nb.fgsm3

# Le groupes FGSM3, Eleves, Pré et Post
groupes.FGSM3.ELEVES = c(rep("fgsm3",nb.fgsm3),rep("eleves",nb.eleves))
groupes.FGSM3.PP = c(rep("fgsm3.pre",nb.fgsm3),rep("fgsm3.post",nb.fgsm3))
groupes.ELEVES.PP = c(rep("eleves.pre",nb.eleves),rep("eleves.post",nb.eleves))

# I. test de normalité ; Test Shapiro
# H0 l'échantillon suit une loi normale.

    # 1. FGSM 3 : PréTest et PostTest
    test.norm.fgsm3.pre = shapiro.test(data.fgsm3$pre)
    test.norm.fgsm3.post = shapiro.test(data.fgsm3$post)

    # 2. ELEVES : PréTestPostTest

    test.norm.eleves.pre = shapiro.test(data.eleves$pre)
    test.norm.eleves.post = shapiro.test(data.eleves$post)


# II. test de distribution ; Test Wilcoxon Mann Withney
# H0 la distribution des données est la même pour les deux groupes.

# B. FGSM3 vs Eleves

    # 1. Pré
    notes.pre.fgsm3vseleves = c(data.fgsm3$pre,data.eleves$pre)
    test.notes.pre.fgsm3vseleves = wilcox.test(notes.pre.fgsm3vseleves~groupes.FGSM3.ELEVES)

    boxplot(notes.pre.fgsm3vseleves~groupes.FGSM3.ELEVES, col=c("pink","lightsteelblue3"), main="Notes : PréTest Élèves et PréTest FGSM3")


    # 2. Post
    notes.post.fgsm3vseleves = c(data.fgsm3$post,data.eleves$post)
    test.notes.post.fgsm3vseleves = wilcox.test(notes.post.fgsm3vseleves~groupes.FGSM3.ELEVES)

    boxplot(notes.post.fgsm3vseleves~groupes.FGSM3.ELEVES, col=c("pink","lightsteelblue3"),
    main="Notes : PostTest Élèves et PostTest FGSM3")
  

    # 3. Pré FGSM3 vs Post Élèves
    notes.pre.fgsm3vspost.eleves = c(data.fgsm3$pre,data.eleves$post)
    test.notes.pre.fgsm3vspost.eleves = wilcox.test(notes.pre.fgsm3vspost.eleves~groupes.FGSM3.ELEVES)

    boxplot(notes.pre.fgsm3vspost.eleves~groupes.FGSM3.ELEVES, col=c("pink","lightsteelblue3"),
    main="Notes : PostTest Élèves et PréTest FGSM3")
    

    # Explication du W

    rangs=rank(notes.pre.fgsm3vspost.eleves)
    data=data.frame(groupes.FGSM3.ELEVES,notes.pre.fgsm3vspost.eleves,rangs)
    boxplot(rangs~groupes.FGSM3.ELEVES, col=c("pink","lightsteelblue3"),
    main="Rang des notes : PostTest Élèves et PréTest FGSM3")

# C. Pré vs Post

    # 1. FGSM3
    notes.fgsm3prevspost = c(data.fgsm3$pre,data.fgsm3$post)
    test.fgsm3.prevspost = wilcox.test(data.fgsm3$pre, data.fgsm3$post, paired = TRUE)

    boxplot(notes.fgsm3prevspost~groupes.FGSM3.PP, col=c("pink","lightsteelblue3"),
        main="Notes : PréTest FGSM3 et PostTest FGSM3")

    test.eleves.prevspost =  wilcox.test(data.eleves$pre, data.eleves$post, paired = TRUE)

    # 2. Élèves
    notes.elevesprevspost = c(data.eleves$pre,data.eleves$post)
    test.eleves.prevspost =  wilcox.test(data.eleves$pre, data.eleves$post, paired = TRUE)

    boxplot(notes.elevesprevspost~groupes.ELEVES.PP, col=c("pink","lightsteelblue3"),
        main="Notes : PréTest Élèves et PostTest Élèves")




# Ecriture dans le fichier
sink("sortie.R-these-med.txt")
print("A. Test de normalité")

print("1. Normalité : PréTest FGSM3")
print(test.norm.fgsm3.pre )

print("2. Normalité : PostTest FGSM3")
print(test.norm.fgsm3.post )

print("3. Normalité : PréTest Élèves")
print(test.norm.eleves.pre )

print("4. Normalité : PréTest Élèves")
print(test.norm.eleves.post )


print("B. FGSM3 vs Eleves")

print("1. Notes : PréTest FGSM3 vs PréTest Élèves")
print(test.notes.pre.fgsm3vseleves)

print("2. Notes : PostTest FGSM3 vs PostTest Élèves")
print(test.notes.post.fgsm3vseleves)

print("3. Notes : PréTest FGSM3 vs PostTest Élèves")
print(test.notes.pre.fgsm3vspost.eleves)

print("C. pré vs Post")

print("1. Notes : PréTest FGSM3 vs PostTest FGSM3")
print(test.fgsm3.prevspost)

print("2. Notes : PréTest Élèves vs PostTest Élèves")
print(test.eleves.prevspost)

sink() 