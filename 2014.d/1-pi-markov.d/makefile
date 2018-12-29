CODE := $(shell pwd)

DATADIR = $(CODE)/output
DATAFILES = $(DATADIR)/data-`date +'%y.%m.%d-%H:%M'`.txt
DATAWORK = $(DATADIR)/data.txt
TOOLDIR =  $(CODE)/tools

# Special
.PHONY: clean

# Create folders if need
target:
	test -d $(DATADIR) || mkdir $(DATADIR)
	test -d $(TOOLDIR) || mkdir $(TOOLDIR)

# Python 3
py3:
	python3 python3/py3_test_pi_markov.py

py3-data:
	python3 python3/py3_test_pi_markov.py > $(DATAFILES); cp $(DATAFILES) $(DATAWORK)

# Plot
plot:
	gnuplot -persist $(TOOLDIR)/error_time.gp
