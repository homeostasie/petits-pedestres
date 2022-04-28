# Dossiers
CODE := $(shell pwd)

# Visualiser les pdf

all: calc tests toolsca

calc-l4:
	python3 src/rpn_list4_calc.py

tools:
	python3 tools/rpn_tools.py

tests:
	python3 tests/tests.py


# nettoyage			
proper:
	rm -f *.log *.toc *.aux *.nav *.snm *.out *.bbl *.blg *.dvi
	rm -f *.backup *~
