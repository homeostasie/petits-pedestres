NombreMax = 10000000
nombreTest = c(0:NombreMax)
racineCarre = sqrt(nombreTest)
partieEntiere = floor(racineCarre)
partieEntiereCarre = partieEntiere^2
resteCarre = nombreTest - partieEntiereCarre
Zettaleaf = function(n,a){n + a*(2*n+1)/(4*n^2+2*n+a)}
testRacineCarre = Zettaleaf(partieEntiere, resteCarre)
ecart = racineCarre - testRacineCarre

plot(nombreTest, ecart, type="l", ylim=c(-1*10^(-7),1*10^(-7)))

plot(nombreTest, racineCarre, col="blue",type="l")
lines(nombreTest,testRacineCarre, col="red",type="l")
legend("topleft",
c("sqrt(x)","Zettaleaf(x)"),
fill=c("blue","red"))