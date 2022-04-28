# Dossiers
CODE := $(shell pwd)
PDFDIR = _pdf
THEME = 

# Visualiser les pdf
LOG=evince

# Créer le dossier pdf s'il n'éxiste pas.
target:
	test -d $(PDFDIR) || mkdir $(PDFDIR)



math_intro-edo-1:
	pdflatex math_intro-edo-1.d/math_intro-edo-1.tex
	pdflatex math_intro-edo-1.d/math_intro-edo-1.tex
	mv math_intro-edo-1.pdf '$(PDFDIR)'/math_intro-edo-1.pdf



# nettoyage		
proper:
	rm -f *.log *.toc *.aux *.nav *.snm *.out *.bbl *.blg *.dvi *.ps
	rm -f *.backup *~