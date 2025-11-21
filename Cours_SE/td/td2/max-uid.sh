#!/bin/bash

cut -d: -f1,3 /etc/passwd | sort -t: -k2,2n | tail -n1 | cut -d: -f1
