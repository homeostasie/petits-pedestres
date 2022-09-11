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


info_intro-go-1:
	pdflatex info_intro-go.d/info_intro-go-1.tex
	pdflatex info_intro-go.d/info_intro-go-1.tex
	mv info_intro-go-1.pdf '$(PDFDIR)'/info_intro-go-1.pdf

astro_deux-infinis-4:
	pdflatex astro-deux-infinis.d/astro_2-infinis-4.tex
	pdflatex astro-deux-infinis.d/astro_2-infinis-4.tex
	mv astro_2-infinis-4.pdf '$(PDFDIR)'/astro_2-infinis-4.pdf	

astro_ss:
	pdflatex astro_system.d/astro_ss.tex
	pdflatex astro_system.d/astro_ss.tex
	mv astro_ss.pdf '$(PDFDIR)'/astro_system-solar-ss.pdf	



# nettoyage		
proper:
	rm -f *.log *.toc *.aux *.nav *.snm *.out *.bbl *.blg *.dvi *.ps
	rm -f *.backup *~