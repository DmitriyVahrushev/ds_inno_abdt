#!/bin/bash

mv input_data.exp brat-v1.3_Crunchy_Frog/
cd brat-v1.3_Crunchy_Frog
expect -f input_data.exp $1 $2 $3
python standalone.py