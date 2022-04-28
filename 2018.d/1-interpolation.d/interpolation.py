import numpy as np
from scipy import interpolate
import matplotlib.pyplot as plt

# DATA
NX=4
NY=4

y,x = np.mgrid[0:NX,0:NY]
x = x/NX
y = y/NY

dx=0.01
dy=0.01

NXNEW = int(NX/dx)
NYNEW = int(NY/dy)

ynew, xnew = np.mgrid[0:NXNEW,0:NYNEW]
xnew = xnew/NXNEW
ynew = ynew/NYNEW


Data=np.loadtxt("tab.dat")
z = np.reshape(Data[:,2],(NX,NY))

# INTERPOLATE


tck = interpolate.bisplrep(x,y,z,s=0)
znew = interpolate.bisplev(xnew[0,:],ynew[:,0],tck)


# GRAPH
xgp,ygp = np.mgrid[0:NX+1,0:NY+1]

xgpnew,ygpnew = np.mgrid[0:NXNEW+1,0:NYNEW+1]



plt.figure()

plt.pcolor(xgp,ygp,z)
plt.colorbar()
plt.title("Sparsely sampled function.")

plt.figure()
plt.pcolor(xgpnew,ygpnew,znew)
plt.colorbar()
plt.title("Interpolated function.")
plt.show()




exit()
