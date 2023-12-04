# https://tech.davis-hansson.com/p/make/

SHELL := zsh
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules

ifeq ($(origin .RECIPEPREFIX), undefined)
  $(error This Make does not support .RECIPEPREFIX. Please use GNU Make 4.0 or later)
endif
.RECIPEPREFIX = >
#################

CC=clang++ -std=c++20 -I/opt/homebrew/include -L/opt/homebrew/lib -lfmt -lpystring


## 01 #########################################################################
clean_puzzle01:
> rm -f puzzle01 puzzle01_test
.PHONE: clean_puzzle01

run_puzzle01_test: puzzle01_test
> ./puzzle01_test

puzzle01_test: aocutil.hpp puzzle01.hpp puzzle01_test.cpp
> $(CC) puzzle01_test.cpp -o $@

run_puzzle01: puzzle01
> ./puzzle01

puzzle01: aocutil.hpp puzzle01.hpp puzzle01.cpp
> $(CC) puzzle01.cpp -o $@


## 02 #########################################################################
clean_puzzle02:
> rm -f puzzle02 puzzle02_test
.PHONE: clean_puzzle02

run_puzzle02_test: puzzle02_test
> ./puzzle02_test

puzzle02_test: aocutil.hpp puzzle02.hpp puzzle02_test.cpp
> $(CC) puzzle02_test.cpp -o $@

run_puzzle02: puzzle02
> ./puzzle02

puzzle02: aocutil.hpp puzzle02.hpp puzzle02.cpp
> $(CC) puzzle02.cpp -o $@


## 03 #########################################################################
clean_puzzle03:
> rm -f puzzle03 puzzle03_test
.PHONE: clean_puzzle03

run_puzzle03_test: puzzle03_test
> ./puzzle03_test

puzzle03_test: aocutil.hpp puzzle03.hpp puzzle03_test.cpp
> $(CC) puzzle03_test.cpp -o $@

run_puzzle03: puzzle03
> ./puzzle03

puzzle03: aocutil.hpp puzzle03.hpp puzzle03.cpp
> $(CC) puzzle03.cpp -o $@
