# Dossiers
CODE := $(shell pwd)

all: exo1

exo1:
	pdflatex tex/exo1-racine.tex
	pdflatex tex/exo1-racine.tex

liens:
	pdflatex tex/liens.tex
	pdflatex tex/liens.tex

# nettoyage			
proper:
	rm -f *.log *.toc *.aux *.nav *.snm *.out *.bbl *.blg *.dvi
	rm -f tex/*.log tex/*.fls tex/*.synctex.gz tex/*.aux tex/*.fdb_latexmk
	rm -f *.backup *~
