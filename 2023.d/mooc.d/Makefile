# Dossiers
CODE := $(shell pwd)
PDFDIR = _pdf
THEME = 

# Visualiser les pdf
LOG=evince

# Créer le dossier pdf s'il n'éxiste pas.
target:
	test -d $(PDFDIR) || mkdir $(PDFDIR)



info_intro-go-1:
	pdflatex info_Go-1.tex
	pdflatex info_Go-1.tex
	mv info_Go-1.pdf '$(PDFDIR)'/info_Go-1.pdf


info_mind-ai-1:
	pdflatex info_Mind-AI-1.tex
	pdflatex info_Mind-AI-1.tex
	mv info_Mind-AI-1.pdf '$(PDFDIR)'/info_Mind-AI-1.pdf

info_crypto-1:
	pdflatex info_Applied-Crypto-1.tex
	pdflatex info_Applied-Crypto-1.tex
	mv info_Applied-Crypto-1.pdf '$(PDFDIR)'/info_Applied-Crypto-1.pdf
	
astro_ss:
	pdflatex astro_Solar-System.tex
	pdflatex astro_Solar-System.tex
	mv astro_Solar-System.pdf '$(PDFDIR)'/astro_Solar-System.pdf	



# nettoyage		
proper:
	rm -f *.log *.toc *.aux *.nav *.snm *.out *.bbl *.blg *.dvi *.ps
	rm -f *.backup *~