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

CC=clang++ -std=c++20 -I/opt/homebrew/include -L/opt/homebrew/lib -lfmt

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
