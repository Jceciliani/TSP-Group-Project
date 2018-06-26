To run TSPAlgo:
add the following files from my zipped folder to a folder on the flip server:

TSPAlgo.cpp
test-input-1.txt
test-input-1.txt.tour
test-input-2.txt
test-input-2.txt.tour
test-input-3.txt
test-input-3.txt.tour
test-input-4.txt
test-input-4.txt.tour
test-input-5.txt
test-input-5.txt.tour
test-input-6.txt
test-input-6.txt.tour
test-input-7.txt
test-input-7.txt.tour
tsp_example_1.txt
tsp_example_1.txt.tour
tsp_example_2.txt
tsp_example_2.txt.tour
tsp_example_3.txt
tsp_example_3.txt.tour
TSPAllVisited.py
tsp-verifier.py
watch.py
makefile

run "make" from the linux console line
(if make doesn't run, just type in: g++ TSPAlgo.cpp -std=c++11 -o TSPAlgo)
run ./TSPAlgo from the linux console line
You will add your inputed txt and the program will read from it, printing the results to a txt.tour file. The program will let you know when the file is open and closed.
