# Implémentation d'une pile de hauteur 4 à partir de la structure listes

class list4:
	"""Gestion de la *pile / liste* :
	- sa pile"""

	def __init__(self):
		"""Constructeur de notre classe
		- Les 4 registres sont mis à 0
		"""
		self.list4 = [0.0, 0.0, 0.0, 0.0]
		
	def affiche(self):
		print("T:      ",self.list4[3])
		print("Z:      ",self.list4[2])	
		print("Y:      ",self.list4[1])	
		print("X:      ",self.list4[0])			

	def empile(self, valeur):
		self.list4.insert(0, valeur)
		self.list4.pop()

		
	def depile(self):
		self.list4.append(self.list4[len(self.list4)-1])
		self.list4.pop(0)

# avec un tempon
	def swap(self):
		self.list4[0] = self.list4[0] + self.list4[1]
		self.list4[1] = self.list4[0] - self.list4[1]
		self.list4[0] = self.list4[0] - self.list4[1]
		
	def fhaut(self):
		self.empile(self.list4[3])
		
	def fbas(self):
		temp = self.list4[0]
		self.depile()
		self.list4[3] = temp
		
	def additioner(self):
		self.list4[1] += self.list4[0]
		self.depile()
		
	def soustraire(self):
		self.list4[1] -= self.list4[0]
		self.depile()
		
	def multiplier(self):
		self.list4[1] *= self.list4[0]
		self.depile()		
				
	def diviser(self):
		self.list4[1] /= self.list4[0]
		self.depile()		

"""
soustraire
multiplier
diviser
diviser
swap
fhaut
fbas
"""
