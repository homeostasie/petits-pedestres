""" 
	Differential Equations in Action
	Lesson 1 - Houston We have a problem
"""	
# Import
import math # import math.cos(), math.sin(), math.pi
import numpy # import distance
import matplotlib.pyplot as plt # import plot

""" 
-----------------------------------------------------------------------
	- 1 - Exercices
-----------------------------------------------------------------------
"""

# Exo 1 - Define x, sin(x) and cos(x)
def sin_cos(num_steps):

    x = numpy.zeros(num_steps)
    sin_x = numpy.zeros(num_steps)
    cos_x = numpy.zeros(num_steps)

    for i in range(num_steps):
        x[i] =2 * math.pi * i / (num_steps-1)
        sin_x[i] = math.cos(x[i])
        cos_x[i] = math.sin(x[i])
        
    return x, sin_x, cos_x

# Exo 2 - Forward Euler method
def forward_euler(time_steps, num_steps, g):

    t = numpy.zeros(num_steps + 1)
    x = numpy.zeros(num_steps + 1)
    v = numpy.zeros(num_steps + 1)

    for step in range(num_steps):
        t[step + 1] = (step+1) * time_steps
        x[step + 1] = x[step] + time_steps*v[step]
        v[step + 1] = v[step] - time_steps*g
    
    return t, x, v

# Exo 3 - Spaceship acceleration with Moon and Earth at a t-time
def acceleration(moon_position, spaceship_position):
    X_ES = - spaceship_position
    X_MS = moon_position - spaceship_position

    F_ES =  ( gravitational_constant * earth_mass / ( numpy.linalg.norm(X_ES)**3) ) * X_ES
    F_MS =  ( gravitational_constant * earth_mass / ( numpy.linalg.norm(X_MS)**3) ) * X_MS

    return F_ES + F_MS

""" 
-----------------------------------------------------------------------
	- 2 - Problems
-----------------------------------------------------------------------
"""

# PROBLEM 1
# Modelise one revolution of the moon around the earth, assuming that 
# the orbit is circular.
def orbit(num_steps):
    x = numpy.zeros([num_steps + 1, 2])
    for i in range(num_steps + 1):
        x[i,0] = moon_distance * math.cos(2. * math.pi * i /num_steps)
        x[i,1] = moon_distance * math.sin(2. * math.pi * i /num_steps)

    return x

# PROBLEM 2
# Free fall at initial speed with  initial angles.
def trajectory(time_steps, num_steps, g, initial_speed, inital_angles):
    acceleration = numpy.array([0., -g])
    x = numpy.zeros([num_steps + 1, 2]) # m
    v = numpy.zeros([num_steps + 1, 2]) # m / s
	# init position and speed
    x[0,:] = [0,0]
    v[0,:] = [initial_speed * math.cos(inital_angles), initial_speed * math.sin(inital_angles) ]
    for step in range(num_steps):
		# Forward Euler Method
        v[step + 1,:] = v[step] + time_steps*acceleration
        x[step + 1,:] = x[step] + time_steps*v[step]
        
    return x, v


# PROBLEM 3
# Spaceship Acceleration
def acceleration(spaceship_position):
    a = numpy.zeros(2) # m
    a[0] = - gravitational_constant * (earth_mass * spaceship_position[0]) /  numpy.linalg.norm(spaceship_position)**3 
    a[1] = - gravitational_constant * (earth_mass * spaceship_position[1]) /  numpy.linalg.norm(spaceship_position)**3 
    return a

# Trajectory of a spacecraft with the given initial position and velocity.
def ship_trajectory(time_steps, num_steps, x_init, v_init):
    x = numpy.zeros([num_steps + 1, 2]) # m
    v = numpy.zeros([num_steps + 1, 2]) # m / s
    # init position and speed
    x[0, :] = x_init
    v[0, :] = v_init

    for step in range(num_steps):
		# Forward Euler Method
        v[step + 1,:] = v[step] + time_steps*acceleration(x[step,:])         
        x[step + 1,:] = x[step] + time_steps*v[step]
        
    return x, v

""" 
-----------------------------------------------------------------------
	- 3 - Plot
-----------------------------------------------------------------------
"""

# Exo 1 - plot sin(x) and cos(x)
def plot_sin_cos():
    plt.plot(x, sin_x)
    plt.plot(x, cos_x)
    plt.show()

# Exo 2 - plot Forward Euler Method
def plot_euler():
    axes_height = plt.subplot(211)
    plt.plot(t, x)
    axes_velocity = plt.subplot(212)
    plt.plot(t, v)
    axes_height.set_ylabel('Height in m')
    axes_velocity.set_ylabel('Velocity in m/s')
    axes_velocity.set_xlabel('Time in s')
    plt.show() 

# Pb1 - plot moon orbit
def plot_orbit():
    plt.axis('equal')
    plt.plot(x[:, 0], x[:, 1])
    axes = plt.gca()
    axes.set_xlabel('Longitudinal position in m')
    axes.set_ylabel('Lateral position in m')
    plt.show()

# Pb2 - plot Earth free fall
def plot_earth_free_fall(time_steps, num_steps, earth_gravitation, initial_speed, inital_angles):
    for angles in inital_angles:
        x,v = trajectory(time_steps, num_steps, earth_gravitation, initial_speed, angles)
        plt.plot(x[:, 0], x[:, 1])

    axes = plt.gca()
    axes.set_xlabel('x position in m')
    axes.set_ylabel('y position in m')
    plt.show()


# Pb3 - plot spaceship orbit
def plot_ship_trajectory():
    plt.plot(x[:, 0], x[:, 1])
    plt.scatter(0, 0)
    plt.axis('equal')
    axes = plt.gca()
    axes.set_xlabel('Longitudinal position in m')
    axes.set_ylabel('Lateral position in m')
    plt.show()

""" 
-----------------------------------------------------------------------
	- Main
-----------------------------------------------------------------------
"""

# STEPS
num_steps = 50 # Max iteration number
time_steps = 0.1 # s

# EARTH and MOON DATA
# Mass
earth_mass = 5.97e24 # kg
moon_mass = 7.35e22 # kg

# Distance
moon_distance = 384e6 # m

# Gravitation
gravitational_constant = 6.67e-11 # N m2 / kg2
earth_gravitation = 9.81 # m / s2

"""
-------------------- Exercices --------------------
"""

# Exo 1 - Cosinus and sinus
x, sin_x, cos_x = sin_cos(num_steps)
#plot_sin_cos() # uncomment for ploting

# Exo 2 - Forward Euler Method
t, x, v = forward_euler(time_steps, num_steps, earth_gravitation)
#plot_euler() # uncomment for ploting

"""
-------------------- Problems --------------------
"""

# pb1 - Moon orbit
x = orbit(num_steps)
#plot_orbit() # uncomment for ploting

# pb2 - Earth free fall
# Initial value
initial_speed = 20. # m / s
initial_angles = math.pi /180 * numpy.linspace(20., 70., 6)
#plot_earth_free_fall(time_steps, num_steps, earth_gravitation, initial_speed, initial_angles) # uncomment for ploting


# pb3 - spaceship orbit
time_steps = 0.1 # s
num_steps = 130000

x_init = [15e6, 1e6]
v_init = [2e3, 4e3]

x, v = ship_trajectory(time_steps, num_steps, x_init, v_init)
plot_ship_trajectory() # uncomment for ploting
