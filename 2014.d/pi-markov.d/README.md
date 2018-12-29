# Pi 

Just throw a point in the square \[-1,1\] x \[-1,1\] (*area = 4*) and look if it is in the disk of radius 1 (*area = pi*). The probability the point is in the disk is pi/4. Repeat with **Monte Carlo** method in order to approximated **pi**.

### Organization

1. **python3/** python3 source and test files

* **ouput/** : data and graph (*not in this repository*)
* **tools/** : gnuplot graph

- *makefile* : Automatize execution
- *README* : This wiki page

### Building Makefile

```
# PYTHON3
# Standart output
make py3
# Ouput the data in a file
make py3-data
# Plot with gnuplot
make plot
```

### Requirement

* Make
* python 3
* gnuplot 
 
## License

The source code will be available under [CC-BY-SA](http://creativecommons.org/licenses/by-sa/3.0/legalcode). License **CC-BY-SA** is copyleft with **Attribution** -BY and **ShareAlike** -SA.

#### Contributeurs

* LAFOND Thomas : https://github.com/homeostasie
