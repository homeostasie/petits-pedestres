###########################################################################
#												  #
#	Traffic routier									  #
#												  #
###########################################################################
##
##  Réprésentation de la voie
##
############################

## 1 flux continu

rep_flux = matrix(1,nrow = 2, ncol= n_1 + n_2)

rep_flux[2,] = c(rep(-1,n_1), rep(1,n_2))
rep_flux[1,]= c(-flux_1, flux_2)
#rep_flux


par(mfrow=c(2,2))

plot(rep_flux[1,], rep_flux[2,],type="p")
title("au temps t = 0")
abline(v=0, col = 2)
abline(h=0, col = 4)

rep_flux[1,] = c(-flux_1+60, flux_2-60)
plot(rep_flux[1,], rep_flux[2,],type="p")
title("au temps t = t + 60s")
abline(v=0, col = 2)
abline(h=0, col = 4)

rep_flux[1,] = c(-flux_1+120, flux_2-120)
plot(rep_flux[1,], rep_flux[2,],type="p")
title("au temps t = t + 120s")
abline(v=0, col = 2)
abline(h=0, col = 4)

rep_flux[1,] = c(-flux_1+180, flux_2-180)
plot(rep_flux[1,], rep_flux[2,],type="p")
title("au temps t = t + 180s")
abline(v=0, col = 2)
abline(h=0, col = 4)


