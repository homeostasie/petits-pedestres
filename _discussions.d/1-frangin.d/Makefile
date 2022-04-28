# Dossiers
CODE := $(shell pwd)
PDFDIR = _pdf
THEME = 

# Visualiser les pdf
LOG=evince

# Créer le dossier pdf s'il n'éxiste pas.
target:
	test -d $(PDFDIR) || mkdir $(PDFDIR)

all: img poly proper

# Générations des images
FIGSRC = $(wildcard sources/1/*.ipe sources/2/*.ipe )

FIGOBJ = $(FIGSRC:.ipe=.pdf)

img: $(FIGOBJ)

sources/1/%.pdf: sources/1/%.ipe
	ipetoipe -pdf $<

# Cinquième

# Quatrième

# Troisième

t1:
	pdflatex tex/1-second-degree.tex
	pdflatex tex/1-second-degree.tex
	mv 1-second-degree.pdf '$(PDFDIR)'/1-second-degree.pdf

t2:
	pdflatex tex/2-statistiques.tex
	pdflatex tex/2-statistiques.tex
	mv 2-statistiques.pdf '$(PDFDIR)'/2-statistiques.pdf

t3:
	pdflatex tex/3-suites.tex
	pdflatex tex/3-suites.tex
	mv 3-suites.pdf '$(PDFDIR)'/3-suites.pdf	
# nettoyage			
proper:
	rm -f *.log *.toc *.aux *.nav *.snm *.out *.bbl *.blg *.dvi
	rm -f tex/*.log tex/*.fls tex/*.synctex.gz tex/*.aux tex/*.fdb_latexmk
	rm -f *.backup *~
